#ifndef DYDETECTIONFLOW_H
#define DYDETECTIONFLOW_H

#include <QMap>
#include <QObject>

class Absorbance;
class OSerialPort;
class OSpectrograph;
class DYSettingModel;
class OpticalIntensity;
class DYDetectionFlow : public QObject
{
    Q_OBJECT
public:
    explicit DYDetectionFlow(OSerialPort *serialPort, OSpectrograph *spectrograph, QObject *parent = 0);
    ~DYDetectionFlow();

    QString blank(DYSettingModel *setting);
    QString measure(DYSettingModel *setting);
    void quit() {m_isWaiting = false;}

signals:
    void toDrawCurve(double x, QVector<double> y);
    void toSaveResult(QString fileName, QStringList result);
    void toSaveRecord(QStringList record);

private:
    OSerialPort *m_pSerialPort;
    OSpectrograph *m_pSpectrograph;

    // key=光程, 每个通道检测值的列表
    QList<OpticalIntensity> m_ctBlankList;                      // Cuvette检测时的Blank数据列表
    int m_ctWidth;                                              // Cuvette检测时的滤波宽度
    double m_ctFactor;                                          // Cuvette检测时的修正系数
    double transformUnit(QString unit);
    bool m_isWaiting;
    void delay(int timeout);
    void showResult(DYSettingModel *setting, Absorbance *a, int count, QStringList data);

};

#endif // PTDETECTIONFLOW_H
