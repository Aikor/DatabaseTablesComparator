#include "dbservice.h"

DBService::DBService()
{

}

DBService::~DBService()
{
    QString connectionName = m_dbConnection.connectionName();
    m_dbConnection.close();
    m_dbConnection = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectionName);
}

bool DBService::setConnection(DBService::DBDriver driver, QString connectionName, QString hostName, QString dbName, QString username, QString password)
{
    m_dbConnection = QSqlDatabase::addDatabase(dbDriverToString(driver), connectionName);
    m_dbConnection.setHostName(hostName);
    m_dbConnection.setDatabaseName(dbName);
    m_dbConnection.setUserName(username);
    m_dbConnection.setPassword(password);
    return m_dbConnection.open();
}

QSqlQuery DBService::selectAllData(QString table) const
{
    QSqlQuery query(m_dbConnection);
    query.exec("SELECT * FROM " + table);
    return query;
}

QString DBService::dbDriverToString(DBService::DBDriver &driver)
{
    QString result;
    switch (driver) {
    case QMYSQL:
        result = "QMYSQL";
        break;
    case QODBC:
        result = "QODBC";
        break;
    default:
        break;
    }
    return result;
}
