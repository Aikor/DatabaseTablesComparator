#include "dbservice.h"

DBService::DBService(DBService::DBDriver driver, QString connectionName, QString hostName, QString dbName, QString username, QString password)
{
    m_dbConnection = QSqlDatabase::addDatabase(dbDriverToString(driver), connectionName);
    m_dbConnection.setHostName(hostName);
    m_dbConnection.setDatabaseName(dbName);
    m_dbConnection.setUserName(username);
    m_dbConnection.setPassword(password);
    m_isOpen = m_dbConnection.open();
}

DBService::~DBService()
{
    QString connectionName = m_dbConnection.connectionName();
    m_dbConnection.close();
    m_dbConnection = QSqlDatabase();
    QSqlDatabase::removeDatabase(connectionName);
}

QSqlQuery DBService::selectAllData(QString &table) const
{
    QSqlQuery query(m_dbConnection);
    query.exec("SELECT * FROM " + table);
    return query;
}

bool DBService::getIsOpen() const
{
    return m_isOpen;
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
