#include "absorbance.h"

#include <QDir>
#include <QDebug>
#include <QVector>
#include <QSettings>

Absorbance::Absorbance(QVector<double> w, QVector<double> a, int width, int bwl) {

    QString fileName = QDir::currentPath() + "/configs/system.ini";
    QSettings *configIniReader = new QSettings( fileName, QSettings::IniFormat );
    int offset = configIniReader->value("Spectrograph/Offset").toInt();
    delete configIniReader;
    configIniReader = NULL;

    m_correctionFactor = 1.0;
    QVector<double> t_w = transformWaveLength(w, offset);
    smothing(t_w, a, width);
    minusZero(bwl);
}

/**
 * @brief Absorbance::waveLength
 * @return
 */
QVector<double> Absorbance::waveLength() {
    return m_w;
}

/**
 * @brief Absorbance::absorbance
 * @return
 */
QVector<double> Absorbance::absorbance() {

    QVector<double> r;
    foreach (double v, m_a) {
        r.append(v*m_correctionFactor);
    }
    return r;
}

/**
 * @brief Absorbance::getAbsoByWL
 * @param w
 * @return
 */
double Absorbance::getAbsoByWL(double w) {
    int index = m_w.indexOf(w);
    if (index >= 0 && index < m_a.size()) {
        return m_a.at(index)*m_correctionFactor;
        //return m_a.at(index);
    }
    return 0;
}

/**
 * @brief Absorbance::minusZero
 * @param bwl
 */
void Absorbance::minusZero(int bwl) {
    double z = getAbsoByWL((double)bwl);
    for (int i = 0; i < m_a.size(); i ++) {
        m_a.replace(i, m_a.at(i)*m_correctionFactor - z);
    }
}

/**
 * @brief Absorbance::smothing
 * @param w
 * @param a
 * @param width
 */
void Absorbance::smothing(QVector<double> w, QVector<double> a, int width) {

    int size = a.size();
    if (size == 0 && size < width) {
        m_w.clear();
        m_a.clear();
        m_w<<(w);
        m_a<<(a);
        return;
    }

    QVector<double> iExtendData;
    iExtendData<<(a.mid(0, width/2));
    iExtendData<<(a);
    iExtendData<<(a.mid(size - width/2, width/2));

    m_w.clear();
    m_a.clear();

    double sum = 0.0;
    QVector<double> ba;
    for (int i = 0; i < a.size(); i ++) {
        sum = 0;
        for (int j = 0; j < width; j ++) {
            sum += iExtendData.at(i + j);
        }
        ba.append(sum/(double)width);
    }

    m_w<<(w);
    m_a<<(ba);
}

/**
 * @brief Absorbance::transformWaveLength
 * @param w
 * @param offset
 * @return
 */
QVector<double> Absorbance::transformWaveLength(QVector<double> w, int offset) {

    QVector<double> t_w;
    for(int i = 0; i < w.size(); i ++) {
        t_w.append(w.at(i) - offset);
    }
    return t_w;
}

