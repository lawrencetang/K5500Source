#include "accrediti.h"

#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QSettings>
#include <QtDebug>
#include "accredit.h"

AccreditI::AccreditI() {
}

AccreditI::~AccreditI() {

}

/**
 * @brief AccreditI::check 校验
 */
/**
 * @brief AccreditI::check
 *          程序启动时，校验授权的有效性
 * @param fileName：授权文件
 * @param noteFileName：授权说明文件
 * @param softwareName：当前程序的名称，如果为""则不判断，如果不为空则必须和Note文件中的software一致
 * @return true：授权有效；false：授权无效
 */
bool AccreditI::check(QString fileName, QString noteFileName, QString softwareName) {

    // 验证授权说明文件Note的有效性
    QStringList noteInfo;
    if (!decodeNoteFile(noteFileName, noteInfo)) {
        return false;
    }
    // 如果softwareName不为空，验证softwareName和NoteInfo文件的一致性
    if (!softwareName.isEmpty() && noteInfo.at(NOTE_SOFTWARE) != softwareName) {
        return false;
    }

    QList<QVariant> linsenceList;
    QList<QVariant> registerList;
    QString checkRegRet = checkRegister(noteInfo, registerList);
    QString checkRegLin = checkLinsence(fileName, noteInfo, linsenceList);

    // 如果linsence和register都失效，直接返回false
    if (checkRegRet != CHECK_RET_SUCCESS && checkRegLin != CHECK_RET_SUCCESS) {
        return false;
    }

    // 如果linsence有效，并且注册表无效或者注册表为旧版本，则更新授权信息
    if (checkRegLin == CHECK_RET_SUCCESS) {
        if ((checkRegRet == CHECK_RET_INVALID) ||
                (checkRegRet != CHECK_RET_INVALID && linsenceList.at(KEY_VERSION) > registerList.at(KEY_VERSION))) {
            if (writeRegister(noteInfo, linsenceList)) {
                // 更新完成后，重读注册表信息
                registerList.clear();
                checkRegRet = checkRegister(noteInfo, registerList);
            } else {
                return false;
            }
        }
    }
    // 注册信息(包括更新后的注册信息)无效或者过期，直接返回
    if (checkRegRet != CHECK_RET_SUCCESS) {
        return false;
    }

    // 如果注册表中的授权信息有效，则更新启动时间
    // 如果上次启动时间比当前时间靠后，保留上次启动时间，这种情况下，认为注册信息有效
    QDateTime currentDateTime = QDateTime::currentDateTime();
    if (currentDateTime.operator < (registerList.at(KEY_UPDATEDATE).toDateTime())) {
        return true;
    } else {
        registerList.removeAt(KEY_UPDATEDATE);
        registerList.insert(KEY_UPDATEDATE, QVariant(currentDateTime));
        return  writeRegister(noteInfo, registerList);
    }
}

/**
 * @brief AccreditI::writeRegister
 *          对内容进行加密，并写入注册表
 * @param noteInfo：加密相关信息
 * @param contentList：待加密的内容
 * @return
 */
bool AccreditI::writeRegister(QStringList noteInfo, QList<QVariant> contentList)
{
    QByteArray ciphertext = Accredit::encryptData(noteInfo.at(NOTE_KEY), contentList);
    if (ciphertext.isEmpty()) {
        return false;
    } else {
        QSettings settings("HKEY_CURRENT_USER\\Software", QSettings::NativeFormat);
        settings.setValue(noteInfo.at(NOTE_FOLDER) + "/" + noteInfo.at(NOTE_ITEM), ciphertext);
        return true;
    }
}

/**
 * @brief AccreditI::clearRegister
 *          清除注册表中的授权内容
 * @param noteInfo
 * @return
 */
bool AccreditI::clearRegister(QStringList noteInfo)
{
    QSettings settings("HKEY_CURRENT_USER\\Software", QSettings::NativeFormat);
    settings.setValue(noteInfo.at(NOTE_FOLDER) + "/" + noteInfo.at(NOTE_ITEM), "");
    return true;
}



/**
 * @brief AccreditI::checkLinsence 校验Linsence
 * @param fileName 文件名称
 * @param retStrList 返回解密数据
 * @return QString
 */
QString AccreditI::checkLinsence(QString fileName, QStringList noteInfo, QList<QVariant> &retList) {

    QStringList dataList = Accredit::decryptFile(noteInfo.at(NOTE_KEY), fileName);
    return checkAccredit(dataList, noteInfo, retList);
}

/**
 * @brief AccreditI::checkRegister 校验注册表
 * @return QString
 */
QString AccreditI::checkRegister(QStringList noteInfo, QList<QVariant> &retList) {

    QSettings settings("HKEY_CURRENT_USER\\Software", QSettings::NativeFormat);
    QByteArray cipherText = settings.value(noteInfo.at(NOTE_FOLDER) + "/" + noteInfo.at(NOTE_ITEM)).toByteArray();

    QStringList dataList = Accredit::decryptData(noteInfo.at(NOTE_KEY), cipherText);
    return checkAccredit(dataList, noteInfo, retList);
}

/**
 * @brief AccreditI::checkAccredit
 *          对解密后的内容进行验证
 * @param dataList：解密后的内容
 * @param noteInfo：解密相关内容
 * @param retList：返回解密后的内容
 * @return  CHECK_RET_INVALID(无效) CHECK_RET_OVERDUE(过期) CHECK_RET_SUCCESS(成功)
 */
QString AccreditI::checkAccredit(QStringList dataList, QStringList noteInfo, QList<QVariant> &retList)
{
    QString strFormat = Accredit::dateTimeFormat();
    for (int i = 0; i < dataList.size(); i ++) {
        QString strData = dataList.at(i);
        switch(i) {
        case 0:
            retList.append(QVariant(strData.toInt()));
            break;
        case 1:
            retList.append(QVariant(strData));
            break;
        case 2:
            retList.append(QVariant(strData));
            break;
        case 3:
            retList.append(QVariant(strData.toInt()));
            break;
        case 4:
            retList.append(QVariant(QDateTime::fromString(strData,strFormat)));
            break;
        case 5:
            retList.append(QVariant(QDateTime::fromString(strData,strFormat)));
            break;
        case 6:
            retList.append(QVariant(QDateTime::fromString(strData,strFormat)));
            break;
        }
    }

    // 1.信息完整性判断
    if (retList.size() != KEY_SIZE) {
        return CHECK_RET_INVALID;
    }
    if (retList.at(KEY_LEVEL).toInt() <= 0 ||
            retList.at(KEY_COMPANY).toString().isEmpty() ||
            retList.at(KEY_SOFTWARE).toString().isEmpty() ||
            retList.at(KEY_VERSION).toInt() <= 0 ||
            !retList.at(KEY_STARTDATE).toDateTime().isValid() ||
            !retList.at(KEY_ENDDATE).toDateTime().isValid() ||
            !retList.at(KEY_UPDATEDATE).toDateTime().isValid()) {
        return CHECK_RET_INVALID;
    }

    // 2.信息正确性判断
    if (retList.at(KEY_COMPANY).toString() != noteInfo.at(NOTE_COMPANY) ||
            retList.at(KEY_SOFTWARE).toString() != noteInfo.at(NOTE_SOFTWARE)) {
        return CHECK_RET_INVALID;
    }

    // 3.时间有效性判断
    if (retList.at(KEY_UPDATEDATE).toDateTime() < (retList.at(KEY_STARTDATE).toDateTime()) ||
            retList.at(KEY_UPDATEDATE).toDateTime() > (retList.at(KEY_ENDDATE).toDateTime())) {
        return CHECK_RET_OVERDUE;
    }

    // 4.当前时间有效性判断
    QDateTime currentDateTime = QDateTime::currentDateTime();
    if (currentDateTime.operator < (retList.at(KEY_STARTDATE).toDateTime()) ||
            currentDateTime.operator > (retList.at(KEY_ENDDATE).toDateTime())) {
        return CHECK_RET_OVERDUE;
    }
    return CHECK_RET_SUCCESS;
}

/**
 * @brief AccreditI::codeNoteFile
 *          对Note文件信息进行加密
 *          注意：为增加安全级别，原内容固定加上NOTE_ADD_INFO后进行加密，解密后固定去掉此字节
 * @param noteInfo
 * @param contentInfo
 * @return
 */
#define NOTE_ADD_INFO   "OLE9187"
QByteArray AccreditI::codeNoteFile(QStringList noteInfo, QStringList contentInfo)
{
    QString noteEncryInfo;
    for (int i = 0; i < noteInfo.size(); i++) {
        noteEncryInfo.append(noteInfo.at(i)).append((i < noteInfo.size() - 1) ? NOTE_FILE_SPLIT : "\r\n");
    }

    QString noteFileContent;
    for (int i = 0; i < contentInfo.size(); i++) {
        noteFileContent.append(contentInfo.at(i)).append((i < contentInfo.size() - 1) ? NOTE_FILE_SPLIT : "\r\n");
    }

    QList<QVariant> noteFileCipherList;
    noteFileCipherList.append(noteEncryInfo + noteFileContent + NOTE_ADD_INFO);
    QByteArray cipherByteArray = Accredit::encryptData(noteInfo.at(NOTE_KEY), noteFileCipherList);

    // 返回
    QByteArray byteArray;
    byteArray.append(noteEncryInfo.toLatin1()).append(noteFileContent.toLatin1()).append(cipherByteArray);
    return byteArray;
}

/**
 * @brief AccreditI::decodeNoteFile
 *          对Note文件信息进行解码和验证
 * @param noteFileName
 * @param noteInfo
 * @return
 */
bool AccreditI::decodeNoteFile(QString noteFileName, QStringList &noteInfo)
{
    // 判断文件是否存在
    QFile file(noteFileName);
    if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
        return false;
    }

    // 读取文件内容
    QByteArray noteEncryInfo = file.readLine(1024);     // 保存Key信息
    QByteArray noteFileContent = file.readLine(1024);   // 保存日期信息
    QByteArray cipherText;                              // 保存密文信息
    while (true) {
        QByteArray byteArray = file.readLine(1024);
        cipherText.append(byteArray);
        if (byteArray.size() <= 0) {
            break;
        }
    }
    file.close();

    // 判断Key信息，去掉"\r\n"并保存到NoteInfo
    QString strEncryInfo = QString(noteEncryInfo);
    noteInfo = strEncryInfo.left(strEncryInfo.size() - 2).split(NOTE_FILE_SPLIT);
    if (noteInfo.size() != NOTE_SIZE) {
        noteInfo.clear();
        return false;
    }

    // 判断日期信息，因为此部分内容不返回，因此可以不判断
    QString strFileContent = QString(noteFileContent);

    // 密文信息解密
    QStringList allContentList = Accredit::decryptData(noteInfo.at(NOTE_KEY), cipherText, "");
    if (allContentList.size() == 0) {
        return false;
    }
    QString allContent = allContentList.at(0);

    // 判断密文解密后的内容是否正确
    if (allContent == (strEncryInfo + strFileContent + NOTE_ADD_INFO)) {
        return true;
    } else {
        return false;
    }
}
