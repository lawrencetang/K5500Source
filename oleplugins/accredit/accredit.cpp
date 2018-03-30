#include "accredit.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QtDebug>
#include <QVariant>
#include <QDateTime>
#include "aesi.h"

Accredit::Accredit()
{
}

Accredit::~Accredit()
{
}


/**
 * @brief Accredit::dateTimeFormat
 * @return
 */
QString Accredit::m_dateTimeFormat = "yyyy.M.d hh:mm:ss";
QString Accredit::dateTimeFormat() {
    return m_dateTimeFormat;
}

/**
 * @brief Accredit::setDateTimeFormat
 * @param format
 */
void Accredit::setDateTimeFormat(QString format) {
    m_dateTimeFormat = format;
}


/**
 * @brief Accredit::encryptData 加密数据
 * @param key 秘钥
 * @param data 数据
 * @param separator 分隔符
 * @return 密文
 */
QByteArray Accredit::encryptData(QString key, QList<QVariant> data, QString separator) {

    QString str;
    for (int i = 0; i < data.size(); i ++) {

        QVariant var = data.at( i );
        if (QVariant::DateTime != var.type()) {
            str.append( var.toString() );   // int也可以转
        } else {
            str.append( var.toDateTime().toString( m_dateTimeFormat ) );
        }

        if (i < data.size() - 1) {
            str.append( separator );
        }
    }

    return encrypt(key, str.toLatin1());
}


/**
 * @brief Accredit::decryptData 解密数据
 * @param key 秘钥
 * @param ciphertext 密文
 * @param separator 分隔符
 * @return 明文
 */
QStringList Accredit::decryptData(QString key, QByteArray ciphertext, QString separator) {

    QString plainText = QString( decrypt(key, ciphertext) );
    if (separator.isEmpty()) {
        return QStringList(plainText);
    } else {
        return plainText.split(separator, QString::SkipEmptyParts);
    }
}

/**
 * @brief Accredit::decryptFile 解密文件
 * @param key 秘钥
 * @param fileName 文件名称
 * @param separator 分隔符
 * @return 明文
 */
QStringList Accredit::decryptFile(QString key, QString fileName, QString separator) {

    QByteArray cipherText;
    QFile file( fileName );
    if (file.open( QIODevice::ReadOnly )) {
        cipherText = file.readAll();
        file.close();
    }
    return decryptData(key, cipherText, separator);
}

/**
 * @brief Accredit::encrypt 加密
 * @param key 秘钥
 * @param plaintext 明文
 * @return 密文
 */
QByteArray Accredit::encrypt(QString key, QByteArray plaintext) {

    QByteArray ciphertext;
    if (plaintext.isEmpty()) {
        return ciphertext;
    }

    u8 u8Key[16];
    memset(u8Key, 0, 16);
    memcpy(u8Key, key.toLatin1().data(), key.size() > 16 ? 16 : key.size());

    // 加密
    ciphertext.resize( 1024 );
    AesI *t_pAesI = new AesI();
    t_pAesI->initializePrivateKey(16, u8Key);
    DWORD ret = t_pAesI->useAesEncrypt(plaintext.data(), plaintext.size(), (LPVOID)ciphertext.data());
    ciphertext.resize(ret);
    delete t_pAesI;

    return ciphertext;
}


/**
 * @brief Accredit::decrypt 解密
 * @param key 秘钥
 * @param ciphertext 密文
 * @return 明文
 */
QByteArray Accredit::decrypt(QString key, QByteArray ciphertext) {

    QByteArray plainText;
    if (ciphertext.isEmpty()) {
        return plainText;
    }

    u8 u8Key[16];
    memset(u8Key, 0, 16);
    memcpy(u8Key, key.toLatin1().data(), key.size() > 16 ? 16 : key.size());

    plainText.resize( 1024 );
    AesI *t_pAesI = new AesI();
    t_pAesI->initializePrivateKey(16, u8Key);
    DWORD ret = t_pAesI->useAesDecode(ciphertext.data(), ciphertext.size(), (LPVOID)plainText.data());
    plainText.resize(ret);
    delete t_pAesI;

    return plainText;
}

