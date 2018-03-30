#include "oplotzoomer.h"

OPlotZoomer::OPlotZoomer(QWidget *canvas)
    :QwtPlotZoomer(canvas) {
    initialize();
}

OPlotZoomer::OPlotZoomer(int xAxis, int yAxis, QWidget *canvas)
    :QwtPlotZoomer(xAxis, yAxis, canvas){
    initialize();
}

OPlotZoomer::~OPlotZoomer() {

}

/**
 * @brief OPlotZoomer::trackerTextF
 * @param pos
 * @return
 */
QwtText OPlotZoomer::trackerTextF(const QPointF &pos) const {

    QString str = QString("x = %1").arg(pos.x()) + "\n" + QString("y = %1\n").arg(pos.y());
    QwtText text( str, QwtText::TeXText);
    text.setRenderFlags(Qt::AlignLeft);
    text.setColor(Qt::black);
    text.setFont(QFont("黑体", 9));
    return text;
}

/**
 * @brief OPlotZoomer::initialize
 */
void OPlotZoomer::initialize() {

    setRubberBandPen(QColor(Qt::red));
    setTrackerPen(QColor(Qt::black));

    /*设置鼠标动作
    * Ctrl + 鼠标右键: 直接还原
    * 鼠标右键: 逐步还原
    */
    setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);

    /*设置键盘动作
    * I: 逐步还原
    * O: 逐步还原
    * Home: 直接还原
    */
    setKeyPattern( QwtEventPattern::KeyRedo, Qt::Key_I );
    setKeyPattern( QwtEventPattern::KeyUndo, Qt::Key_O );
    setKeyPattern( QwtEventPattern::KeyHome, Qt::Key_Home );
}

