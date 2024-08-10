#ifndef ADD_TO_DB_TABLE_H
#define ADD_TO_DB_TABLE_H

#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

inline bool Add_to_db_Table(QString add_sql, QString table_name, QString itm_name)
{
    QSqlQuery query;
    if (!query.exec(add_sql))
    {
        QString err_info = QString("%1: Can't add %2!").arg(table_name).arg(itm_name);
        QMessageBox::critical(nullptr, "Error", err_info, QMessageBox::Ok);
        qDebug() << err_info;
        qDebug() << query.lastError();
        return false;
    }
    return true;
}

#endif
