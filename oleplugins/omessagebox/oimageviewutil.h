#ifndef OIMAGEVIEWUTIL_H
#define OIMAGEVIEWUTIL_H

#include <QObject>

class OImageViewUtil
{
public:
    OImageViewUtil();
    ~OImageViewUtil();

    static void showImage(QString fileName, QPixmap pixmap);
};

#endif // OIMAGEVIEWUTIL_H
