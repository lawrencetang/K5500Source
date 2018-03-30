#include "oimageviewutil.h"

#include "oimageview.h"

OImageViewUtil::OImageViewUtil() {
}

OImageViewUtil::~OImageViewUtil() {
}

void OImageViewUtil::showImage(QString fileName, QPixmap pixmap) {
    OImageView imageView(fileName, pixmap);
    imageView.exec();
}

