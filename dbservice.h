#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <QtSql>

class DBService
{
public:
    enum DBDriver { QMYSQL = 0, QODBC};
    explicit DBService(DBDriver driver, QString connectionName, QString hostName, QString dbName, QString username, QString password);
    ~DBService();

    QSqlQuery selectAllData(QString &table) const;

    bool getIsOpen() const;

private:
    QSqlDatabase m_dbConnection;
    bool m_isOpen;
    QString dbDriverToString(DBDriver &driver);
};

#endif // DBSERVICE_H
