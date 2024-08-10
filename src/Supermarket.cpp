#include "Supermarket.h"

Supermarket::Supermarket(QString name, int cash) : m_Name(name), m_Cash(cash)
{
    QSqlDatabase db;
    if (!Open_db(db, Supermarket_db_path, "Goods", "Goods"))
        return;
    Supermarket::Supermarket_db = db;
    if (!Create_db_Table("create table if not exists Supermarkets(name text primary key,cash int)", "Supermarkets"))
        return;
    QString add_sql = QString("insert into Supermarkets values('%1',%2)").arg(m_Name).arg(m_Cash);
    if (!Add_to_db_Table(add_sql, m_Name, "Supermarket"))
        return;
}

Supermarket::~Supermarket()
{
}

QSqlDatabase Supermarket::Supermarket_db;

bool Supermarket::Open_Supermarket_db()
{
    QSqlDatabase db;
    if (!Open_db(db, Supermarket_db_path, "Goods", "Goods"))
        return false;
    Supermarket::Supermarket_db = db;
    return true;
}
