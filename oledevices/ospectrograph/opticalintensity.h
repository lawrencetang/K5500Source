#ifndef OPTICALINTENSITY_H
#define OPTICALINTENSITY_H

#include <QObject>
#include <QVector>

class Absorbance;
class OpticalIntensity
{
public:
    explicit OpticalIntensity(QVector<double> w, QVector<double> i);

    QVector<double> waveLength() { return m_w; }
    QVector<double> intensity() { return m_i; }
    static Absorbance *toAbsorbance(OpticalIntensity a, OpticalIntensity b,
                                    double optical, int width = 9, int bwl = 340);

private:
    QVector<double> m_w;
    QVector<double> m_i;
};

#endif // OPTICALINTENSITY_H
