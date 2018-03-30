#include "oligocalculator.h"
#include "ui_oligocalculator.h"

#include "ofullkeyboard.h"
#include "omessageboxutil.h"

OligoCalculator::OligoCalculator(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OligoCalculator) {
    ui->setupUi(this);

    m_pKeyboard = new OFullKeyboard(this, this);
    QHBoxLayout *layout = new QHBoxLayout();
    m_pKeyboard->setKeySize(QSize(48, 48));
    layout->addWidget(m_pKeyboard);
    ui->frameKeyboard->setLayout(layout);

    connect(ui->inputTextEdit, SIGNAL(textChanged()), this, SLOT(calculate()));
    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SLOT(back()));
}

OligoCalculator::~OligoCalculator() {
    delete ui;
}

/**
 * @brief OligoCalculator::back
 */
void OligoCalculator::back() {

    int result = OMessageBoxUtil::staticNotice(0, tr( "Do you want to clear result?" ),
                                               QStringList() << tr( "OK" ) << tr( "Cancel" ), 10);
    if (result == 0) {
        clear();
        ui->inputTextEdit->clear();
    }

    emit backToMainPage();
}

/**
 * 函数名称: clear
 * 函数用途: 清空计算结果
 * 输入参数:
 *          无
 * 输出参数:
 *          无
 */
void OligoCalculator::clear() {
    ui->nbLineEdit->clear();
    ui->gcLineEdit->clear();
    ui->tmLineEdit->clear();
    ui->mwLineEdit->clear();
    ui->odLineEdit->clear();
}

/**
 * 函数名称: calculate
 * 函数用途: 计算引物的退火温度（Tm），分子量和1OD260相当于多少摩尔数
 * 输入参数:
 *          无
 * 输出参数:
 *          无
 */
void OligoCalculator::calculate() {

    QString text = ui->inputTextEdit->toPlainText();
    if (!text.isEmpty()) {
        QRegExp regExp("[^ACGT]");
        if (text.count(regExp)) {
            text.replace(regExp, "");
            ui->inputTextEdit->setPlainText(text);
        }
    }
    clear();

    int A = text.count("A");
    int C = text.count("C");
    int G = text.count("G");
    int T = text.count("T");

    int Number = A + C + G + T;
    if (0 == Number) {
        return;
    }
    int GC = (G + C)*100/Number;

    double Tm = 0;
    if (Number >= 14 && Number <= 20) {
        Tm = 4*(G+C)+2*(A+T);
    } else if (Number > 20) {
        Tm = 0.41*(double)GC- 675/(double)Number + 81.5;
    }

    int MW = (A*312)+(C*288)+(G*328)+(T*303)-61;

    int OD260 = 0;
    if (0 != MW) {
        OD260 = 33*1000000/MW;
    }

    ui->nbLineEdit->setText(QString::number(Number));
    ui->gcLineEdit->setText(QString::number(GC));
    ui->tmLineEdit->setText(QString::number(Tm, 'g'));
    ui->mwLineEdit->setText(QString::number(MW));
    ui->odLineEdit->setText(QString::number(OD260));
}

