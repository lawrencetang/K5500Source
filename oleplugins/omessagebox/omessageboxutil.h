#ifndef OMESSAGEBOXUTIL_H
#define OMESSAGEBOXUTIL_H

#include <QObject>

class OMessageBox;
class OMessageBoxUtil
{
public:
    OMessageBoxUtil();
    ~OMessageBoxUtil();

    static void setStyleSheet(QString stylesheet);
    static int staticNotice(QWidget *parent, QString text, QStringList btnLabels, int timeout = 0);
    static OMessageBox *dynamicNotice(QWidget *parent, QString text);

private:
    static QString m_styleSheet;
};

#endif // OMESSAGEBOX_H
