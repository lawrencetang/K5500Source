#include "otableviewutil.h"
#include "otableview.h"

OTableViewUtil::OTableViewUtil(QObject *parent) :
    QObject(parent) {

}

void OTableViewUtil::showData(QString title, QStringList headerLabels, QList<QStringList> info) {
    OTableView tableView(headerLabels, info);
    tableView.setTitle(title);
    tableView.setFixedSize(700, 400);
    tableView.exec();
}

