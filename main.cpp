#include <QCoreApplication>

#include "dbservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DBService db;
    if (!db.setConnection(DBService::QODBC, "testDB", "80.211.241.238", "", "solarhome", "Wind2Forest")) {
        qDebug() << "DB isn't set!";
        return a.exec();
    }
    QSqlQuery query = db.selectAllData("");
    QSqlRecord rec = query.record();
    QStringList list;
    while (query.next()) {
        list << query.value(0).toString();
    }
    qDebug() << list;

    return a.exec();
}
