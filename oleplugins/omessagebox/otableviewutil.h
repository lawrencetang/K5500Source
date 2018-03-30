#ifndef OTABLEVIEWUTIL_H
#define OTABLEVIEWUTIL_H

#include <QObject>

class OTableViewUtil : public QObject
{
    Q_OBJECT
public:
    explicit OTableViewUtil(QObject *parent = 0);

    static void showData(QString title, QStringList headerLabels, QList<QStringList> info);
};

#endif // OTABLEWIDGETUTIL_H
