#include "Order.h"

Order::Order(QString date) : m_money(0), m_date(date)
{
    ++cnt;
    QSqlDatabase db;
    if (!Open_db(db, Orders_db_path, "Orders", "Orders"))
        return;
}

Order::~Order()
{
}

int Order::cnt = 0;
QSqlDatabase Order::Orders_db;

bool Order::Open_Orders_db()
{
    QSqlDatabase db;
    if (!Open_db(db, Orders_db_path, "Orders", "Orders"))
        return false;
    Order::Orders_db = db;
    return true;
}

bool Order::operator+(Goods *gd)
{
    Mod_Od_db(gd);
    Mod_DG_db(gd);
    return true;
}

bool Order::operator-(Goods *gd)
{
    Mod_Od_db(gd);
    Mod_DG_db(gd);
    return true;
}
