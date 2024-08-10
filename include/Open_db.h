#ifndef OPEN_DB_H
#define OPEN_DB_H

#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>

inline bool Open_db(QSqlDatabase &db, QString path, QString name, QString itm_name)
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if (!db.open())
    {
        QString err_info = QString("%1: Can't open %2 database!").arg(name).arg(itm_name);
        QMessageBox::critical(nullptr, "Error", err_info, QMessageBox::Ok);
        qDebug() << err_info;
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    return true;
}

#endif
