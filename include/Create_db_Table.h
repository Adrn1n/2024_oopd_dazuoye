#ifndef CREATE_DB_TABLE_H
#define CREATE_DB_TABLE_H

#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

inline bool Create_db_Table(QString creat_sql, QString table_name)
{
    QSqlQuery query;
    if (!query.exec(creat_sql))
    {
        QString err_info = QString("Can't create %1 table!").arg(table_name);
        QMessageBox::critical(nullptr, "Error", err_info, QMessageBox::Ok);
        qDebug() << err_info;
        qDebug() << query.lastError();
        return false;
    }
    return true;
}

#endif
