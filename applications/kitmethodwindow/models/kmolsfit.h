#ifndef KMOLSFIT_H
#define KMOLSFIT_H

#include <QVector>

int CalFit(QVector<double> x, QVector<double> y, int amount, int SizeSrc, QList<double> *coefs);

int CalAvgVar(QVector<double> x, QVector<double> y, int amount, int SizeSrc, QList<double> coefs, double *r2);

#endif // FIT_H

