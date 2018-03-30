#ifndef ULTRAMICROSPECTROPHOTOMETER_H
#define ULTRAMICROSPECTROPHOTOMETER_H

#include <QMap>
#include <QMainWindow>

namespace Ui {
class UltramicroSpectrophotometer;
}

class QTimer;
class ToolWindow;
class OScrollArea;
class QToolButton;
class OSerialPort;
class OSpectrograph;
class UvVisWindow;
class ProteinWindow;
class NanoGoldWindow;
class DynamicsWindow;
class OligoCalculator;
class KitMethodWindow;
class MicroArrayWindow;
class CellCultureWindow;
class NucleicAcidWindow;
class DeviceCheckWindow;
class TemperatureWindow;

class UltramicroSpectrophotometer : public QMainWindow
{
    Q_OBJECT

public:
    explicit UltramicroSpectrophotometer(QWidget *parent = 0);
    ~UltramicroSpectrophotometer();

public slots:
    void receiveAppMessage(QStringList messages);

private slots:
    void changePage();
    void toMainPage();

    void selfChecking();
    void reconnecting();

private:
    Ui::UltramicroSpectrophotometer *ui;
    bool m_isAnimation;
    // 8个应用程序
    UvVisWindow *m_pUvVisWindow;
    ProteinWindow *m_pProteinWindow;
    NanoGoldWindow *m_pNanoGoldWindow;
    DynamicsWindow *m_pDynamicsWindow;
    KitMethodWindow *m_pKitMethodWindow;
    MicroArrayWindow *m_pMicroArrayWindow;
    CellCultureWindow *m_pCellCultureWindow;
    NucleicAcidWindow *m_pNucleicAcidWindow;
    // 1个设备检测
    DeviceCheckWindow *m_pDeviceCheckWindow;
    ToolWindow *m_pToolWindow;
    TemperatureWindow *m_pTemperatureWindow;
    OligoCalculator *m_pOligoCalculator;
    QMap<QToolButton *, QWidget *> m_tBtnPagerMapper;

    OSerialPort *m_pSerialPort;                               // 串口设备
    OSpectrograph *m_pSpectrograph;                           // 光谱设备

    int m_rCount;                                             // 重连次数
    int m_channelNumber;                                      // 支持通道数
    QString m_company;                                        // 公司信息
    QStringList m_applicationNameList;                        // 应用程序名称列表
    QStringList m_toolNameList;                               // 工具列表

    bool m_obaitn_sn_s;
    bool m_obaitn_sn_c;
    QString m_sn_s;
    QString m_sn_c;
    int m_id_c;
    bool checkDevice();
    void resetDevice();

    int m_selfCheckingTime;                                   // 自检时间
    int m_reconnectingTime;                                   // 重连时间
    QTimer *m_pSelfCheckingTimer;                             // 自检定时器
    QTimer *m_pReconnectingTimer;                             // 重连定时器

    QString openDevice();
    void showStatusMessage(QString leftMessage, QString rightMessage);
    void flipOverAnimation(QWidget *w);
    void initializeSystems();
    void initializeSignals();
    void initializeWidgets();
    void installStyleSheet();
};

#endif // ULTRAMICROSPECTROPHOTOMETER_H
