#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include "Open_db.h"
#include "Create_db_Table.h"
#include "Add_to_db_Table.h"

const QString Supermarket_db_path = "../assets/Supermarket.db";

class Supermarket
{
public:
    Supermarket(QString name, int cash);
    virtual ~Supermarket();
    static bool Open_Supermarket_db();

private:
    QString m_Name;
    int m_Cash;
    static QSqlDatabase Supermarket_db;
};

#endif
