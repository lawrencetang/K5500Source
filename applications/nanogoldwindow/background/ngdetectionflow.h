#ifndef NGDETECTIONFLOW_H
#define NGDETECTIONFLOW_H

#include <QMap>
#include <QObject>

class Absorbance;
class OSerialPort;
class OSpectrograph;
class NGSettingModel;
class OpticalIntensity;

class NGDetectionFlow;
typedef void (NGDetectionFlow::*pShowResultFunc)(NGSettingModel *setting, Absorbance *a, int id, QString optical);

class NGDetectionFlow : public QObject
{
    Q_OBJECT
public:
    explicit NGDetectionFlow(OSerialPort *serialPort, OSpectrograph *spectrograph, QObject *parent = 0);
    ~NGDetectionFlow();

    QString blank(NGSettingModel *setting);
    QString measure(NGSettingModel *setting);
    void quit() {m_isWaiting = false;}

signals:
    void toDrawCurve(QString name, QVector<double> x, QVector<double> y);
    void toSaveResult(QString fileName, QStringList result);
    void toSaveRecord(QStringList record);

private:
    OSerialPort *m_pSerialPort;
    OSpectrograph *m_pSpectrograph;

    // key=光程, 每个通道检测值的列表
    QMap<QString, QList<OpticalIntensity> > m_msBlankMapper;    // Microscale检测时的Blank数据Map
    QList<OpticalIntensity> m_ctBlankList;                      // Cuvette检测时的Blank数据列表

    QList<int> m_msWidths;                                      // Microscale检测时每个通道的滤波宽度
    QList<double> m_msFactors;                                  // Microscale检测时每个通道的修正系数
    int m_ctWidth;                                              // Cuvette检测时的滤波宽度
    double m_ctFactor;                                          // Cuvette检测时的修正系数

    double transformUnit(QString unit);

    bool m_isWaiting;
    void delay(int timeout);
    void showResult(NGSettingModel *setting, Absorbance *a, int id, QString optical);
    QString prejudgement(NGSettingModel *setting, QList<int> &stdId, QList<int> &maxId, QList<int> &minId);
    QString excuteMicroscaleBlank(NGSettingModel *setting, QString opticalStr);
    QString excuteMicroscaleMeasure(NGSettingModel *setting, QString opticalStr,
                                    QList<int> excuteId, QList<Absorbance *> *result = NULL, pShowResultFunc showResult = NULL);
};

#endif // NGDETECTIONFLOW_H
