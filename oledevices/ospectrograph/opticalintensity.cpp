#include "opticalintensity.h"

#include "math.h"
#include "absorbance.h"

#include <QDebug>
#include <QVector>

#define STANDARD_OPTICAL 10

OpticalIntensity::OpticalIntensity(QVector<double> w, QVector<double> i) {

    m_w.clear();
    m_i.clear();
    m_w<<( w );
    m_i<<( i );
}

/**
 * @brief OpticalIntensity::toAbsorbance
 * @param a
 * @param b
 * @param width
 * @return
 */
Absorbance *OpticalIntensity::toAbsorbance(OpticalIntensity a,
                                           OpticalIntensity b,
                                           double optical, int width, int bwl) {

    QVector<double> ai = a.intensity();
    QVector<double> bi = b.intensity();
    QVector<double> aw = a.waveLength();

    QVector<double> ci;
    int aSize = ai.size();
    int bSize = bi.size();
    for (int i = 0; i < aSize; i ++) {

        double v1 = ai.at(i) + 10;
        double v2 = 1, v3 = 0;
        if (v1 != 0) {
            if (i < bSize) {
                v2 = (bi.at(i) + 10)/v1;
            }
        }
        if (v2 != 0) {
            v3 = log10(v2)*STANDARD_OPTICAL/optical;
            //qDebug() << "optical = " << optical;//ltg
        }
        ci.append(v3);
    }

    return new Absorbance(aw, ci, width, bwl);
}

