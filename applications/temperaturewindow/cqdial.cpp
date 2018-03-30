#include "cqdial.h"
#include <qwt_dial_needle.h>
#include <qwt_round_scale_draw.h>

#include <QDebug>
#include <QPainter>

const QFont dialFont = QFont( "黑体", 14, QFont::Bold );
const QFont labelFont = QFont( "微软雅黑", 12, QFont::Bold );

CqDial::CqDial(QWidget *parent) :
    QwtDial( parent ) {

    QwtRoundScaleDraw *scaleDraw = new QwtRoundScaleDraw();
    scaleDraw->setSpacing( 8 );
    scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, false );
    scaleDraw->setTickLength( QwtScaleDiv::MinorTick, 2 );
    scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 6 );
    scaleDraw->setTickLength( QwtScaleDiv::MajorTick, 12 );
    scaleDraw->setPenWidth( 2 );
    setScaleDraw( scaleDraw );

    setFont( dialFont );
    setWrapping( false );
    setReadOnly( true );

    setOrigin( 135.0 );
    setScaleArc( 0.0, 270.0 );

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow,
                                                           true, Qt::red, QColor( Qt::gray ).light( 130 ) );
    setNeedle( needle );
}

CqDial::~CqDial() {

}

/**
 * @brief CqDial::label
 * @return
 */
QString CqDial::label() const {
    return m_label;
}

/**
 * @brief CqDial::setLabel
 * @param label
 */
void CqDial::setLabel(const QString &label) {
    m_label = label;
    update();
}

/**
 * @brief CqDial::drawScaleContents
 * @param painter
 * @param center
 * @param radius
 */
void CqDial::drawScaleContents(QPainter *painter,
                               const QPointF &center, double radius) const {

    QRectF rect( 0.0, 0.0, 2.0 * radius, 2.0 * radius - 10.0 );
    rect.moveCenter( center );

    const QColor color = palette().color( QPalette::Text );
    painter->setPen( color );

    const int flags = Qt::AlignBottom | Qt::AlignHCenter;
    painter->setFont( labelFont );
    painter->drawText( rect, flags, m_label );
}


