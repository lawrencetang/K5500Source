#ifndef ACCREDIT_H
#define ACCREDIT_H

#include <QObject>

/**
 * 使用精确到秒的时间来授权
 * 为了兼容存在此精确的情况，默认授权版本为ACCREDIT_LEVEL_SECOND
 */
#define ACCREDIT_LEVEL_SECOND           0x80

/**
 * NOTE文件中的分隔符
 */
#define NOTE_FILE_SPLIT                 "#"

class Accredit
{
public:
    Accredit();
    ~Accredit();
    static QString dateTimeFormat();                                                              // 时间格式字符串
    static void setDateTimeFormat(QString format);                                                // 设置时间格式字符串
    static QByteArray encryptData(QString key, QList<QVariant> data, QString separator = "-");    // 加密数据
    static QStringList decryptData(QString key, QByteArray ciphertext, QString separator = "-");  // 解密数据
    static QStringList decryptFile(QString key, QString fileName, QString separator = "-");       // 解密文件

private:
    static QString m_dateTimeFormat;
    static QByteArray encrypt(QString key, QByteArray plaintext);                                 // 加密
    static QByteArray decrypt(QString key, QByteArray ciphertext);                                // 解密
};
#endif // ACCREDIT_H
