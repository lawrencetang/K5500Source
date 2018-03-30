#ifndef ABSORBANCE_H
#define ABSORBANCE_H

#include <QVector>
#include <QObject>

class Absorbance
{
public:
    explicit Absorbance(QVector<double> w, QVector<double> a, int width = 7, int bwl = 340);

    QVector<double> waveLength();
    QVector<double> absorbance();
    double getAbsoByWL(double w);

    double correctionFactor() {return m_correctionFactor;}
    void setCorrectionFactor(double f) {m_correctionFactor = f;}

private:
    QVector<double> m_w;
    QVector<double> m_a;
    double m_correctionFactor;

    void minusZero(int bwl);
    void smothing(QVector<double> w, QVector<double> a, int width);
    QVector<double> transformWaveLength(QVector<double> w, int offset);
};

#endif // ABSORBANCE_H
