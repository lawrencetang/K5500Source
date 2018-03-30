#ifndef OLIGOCALCULATOR_H
#define OLIGOCALCULATOR_H

#include <QFrame>

namespace Ui {
class OligoCalculator;
}

class OFullKeyboard;
class OligoCalculator : public QFrame
{
    Q_OBJECT

public:
    explicit OligoCalculator(QWidget *parent = 0);
    ~OligoCalculator();

signals:
    void backToMainPage();

private slots:
    void back();
    void clear();
    void calculate();

private:
    Ui::OligoCalculator *ui;
    OFullKeyboard *m_pKeyboard;
};

#endif // OLIGOCALCULATOR_H
