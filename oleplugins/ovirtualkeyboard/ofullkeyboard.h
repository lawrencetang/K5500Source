#ifndef OFULLKEYBOARD_H
#define OFULLKEYBOARD_H

#include <QMap>
#include <QFrame>

namespace Ui {
class OFullKeyboard;
}

class QPoint;
class QToolButton;
class OFullKeyboard : public QFrame
{
    Q_OBJECT

public:
    explicit OFullKeyboard(QWidget *receiver, QWidget *parent = 0);
    ~OFullKeyboard();

    void setReceiver(QWidget *receiver) {
        m_receiver = receiver;
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

    int headerRadius() { return m_headerRadius; }
    void setheaderRadius(int radius);

    QString headerFont() { return m_headerFont; }
    void setHeaderFont(QString font);

    QString headerColor() { return m_headerColor; }
    void setHeaderColor(QString color);

    QString headerBorder() { return m_headerBorder; }
    void setHeaderBorder(QString border);

    QString headerBackground() { return m_headerBackground; }
    void setHeaderBackground(QString background);

private slots:
    void onKeyPressedEn();
    void onKeyPressedCh();
    void onCapKeyPressed();
    void onSwitchKeyPressed();
    void onSelectKeyPressed();
    void updateHz(QString text);

    void prePage();
    void nextPage();

protected:
    virtual void showEvent(QShowEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::OFullKeyboard *ui;
    QWidget *m_receiver;
    QSize m_keySize;
    int m_currentPage;
    bool m_isAutoResize;
    bool m_isFloated;

    bool m_isPressed;
    QPoint m_dragOrigin;
    QMap<QToolButton *, Qt::Key> m_keyMapper;
    QList<QToolButton *> m_digitKeyList;
    QList<QToolButton *> m_letterKeyList;
    QMap<QString, QString> m_hanziMapper;

    void resize();
    void refresh();
    void loadFontLibrary();
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

    //
    int m_headerRadius;
    QString m_headerFont;
    QString m_headerColor;
    QString m_headerBorder;
    QString m_headerBackground;
    QString m_headerStyleSheet;
    void initializeStyleSheet();
};

#endif // OFULLKEYBOARD_H
