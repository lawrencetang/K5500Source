#ifndef CQDIAL_H
#define CQDIAL_H

#include <qwt_dial.h>

class CqDial : public QwtDial
{

public:
    CqDial(QWidget *parent = NULL);
    ~CqDial();

    QString label() const;
    void setLabel(const QString &label);

protected:
    virtual void drawScaleContents( QPainter *painter,
                                    const QPointF &center, double radius ) const;
private:
    QString m_label;
};

#endif // CQDIAL_H
