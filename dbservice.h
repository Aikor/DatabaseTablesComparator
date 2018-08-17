#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <QtSql>

class DBService
{
public:
    enum DBDriver { QMYSQL = 0, QODBC};
    explicit DBService();
    ~DBService();

    bool setConnection(DBDriver driver, QString connectionName, QString hostName, QString dbName, QString username, QString password);
    QSqlQuery selectAllData(QString table) const;

private:
    QSqlDatabase m_dbConnection;
    QString dbDriverToString(DBDriver &driver);
};

#endif // DBSERVICE_H
