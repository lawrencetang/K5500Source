#ifndef ACCREDITI_H
#define ACCREDITI_H

#include <QObject>
#include <QDateTime>

/**
 * Note中各信息的索引
 */
#define NOTE_COMPANY    0x00
#define NOTE_SOFTWARE   0x01
#define NOTE_KEY        0x02
#define NOTE_FOLDER     0x03
#define NOTE_ITEM       0x04
#define NOTE_SIZE       0x05

/**
 * 加密信息中各信息的索引
 */
#define KEY_LEVEL       0x00
#define KEY_COMPANY     0x01
#define KEY_SOFTWARE    0x02
#define KEY_VERSION     0x03
#define KEY_STARTDATE   0x04
#define KEY_ENDDATE     0x05
#define KEY_UPDATEDATE  0x06
#define KEY_SIZE        0x07

class AccreditI
{
public:
    AccreditI();
    ~AccreditI();

    static bool check(QString fileName, QString noteFileName, QString softwareName = "");               // 校验接口

#define CHECK_RET_SUCCESS   "SUCCESS"
#define CHECK_RET_INVALID   "INVALID"
#define CHECK_RET_OVERDUE   "OVERDUE"
    static QString checkLinsence(QString fileName, QStringList noteInfo, QList<QVariant> &retList);     // 校验Lisece文件
    static QString checkRegister(QStringList noteInfo, QList<QVariant> &retList);                       // 校验注册表

    static bool writeRegister(QStringList noteInfo, QList<QVariant> contentList);
    static bool clearRegister(QStringList noteInfo);

    // note file加解密
    static QByteArray codeNoteFile(QStringList noteInfo, QStringList contentInfo);
    static bool decodeNoteFile(QString noteFileName, QStringList &noteInfo);

private:
    static QString checkAccredit(QStringList dataList, QStringList noteInfo, QList<QVariant> &retList);
};

#endif // ACCREDITI_H
