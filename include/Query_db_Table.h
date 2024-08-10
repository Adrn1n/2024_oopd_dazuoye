#ifndef QUERY_DB_TABLE_H
#define QUERY_DB_TABLE_H

#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

inline bool Query_db_Talbe(QSqlQuery &query, QString sql_query, QString table_name, QString name)
{
    if (!query.exec(sql_query))
    {
        QString err_info = QString("%1: Can't query %2 table!").arg(name).arg(table_name);
        QMessageBox::critical(nullptr, "Error", err_info, QMessageBox::Ok);
        qDebug() << err_info;
        qDebug() << query.lastError();
        return false;
    }
    return true;
}

#endif
