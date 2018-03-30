#ifndef ODIGITKEYBOARD_H
#define ODIGITKEYBOARD_H

#include <QMap>
#include <QFrame>

namespace Ui {
class ODigitKeyboard;
}

class QToolButton;
class ODigitKeyboard : public QFrame
{
    Q_OBJECT

public:
    explicit ODigitKeyboard(QWidget *receiver, QWidget *parent);
    ~ODigitKeyboard();

    void setReceiver(QWidget *receiver) {
        m_reveiver = receiver;
    }

    bool isAutoResize() { return m_isAutoResize; }
    void setAutoResize(bool isAuto);

    bool isFloated() { return m_isFloated; }
    void setFloated(bool isFloated);

    QSize keySize() { return m_keySize; }
    void setKeySize(QSize keySize);

    int keyRadius() { return m_keyRadius; }
    void setKeyRadius(int radius);

    QString keyFont() { return m_keyFont; }
    void setKeyFont(QString font);

    QString keyColor() { return m_keyColor; }
    void setKeyColor(QString color);

    QStringList keyBackground() { return QStringList() << m_keyBackground_enabled << m_keyBackground_hover
                                                       << m_keyBackground_pressed << m_keyBackground_disabled; }
    void setKeyBackground(QStringList data);

    int borderRadius() { return m_borderRadius; }
    void setBorderRadius(int radius);

    QString border() { return m_border; }
    void setBorder(QString border);

    QString borderBackground() { return m_borderBackground; }
    void setBorderBackground(QString background);

private slots:
    void onKeyPressed();

protected:
    virtual void showEvent(QShowEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::ODigitKeyboard *ui;
    QWidget *m_reveiver;
    QSize m_keySize;
    bool m_isFloated;
    bool m_isAutoResize;

    bool m_isPressed;
    QPoint m_dragOrigin;
    QMap<QToolButton *, Qt::Key> m_keyMapper;

    void resize();
    void refresh();
    void initializeKey();

    // 按键stylesheet
    int m_keyRadius;
    QString m_keyFont;
    QString m_keyColor;
    QString m_keyBackground_enabled;
    QString m_keyBackground_hover;
    QString m_keyBackground_pressed;
    QString m_keyBackground_disabled;
    QString m_keyStyleSheet;

    // 边框stylesheet
    int m_borderRadius;
    QString m_border;
    QString m_borderBackground;
    QString m_borderStyleSheet;
    void initializeStyleSheet();
};

#endif // ODIGITKEYBOARD_H
