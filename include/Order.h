#ifndef ORDER_H
#define ORDER_H

#include "DailyGoods.h"
#include "Food.h"
#include "ElectricalAppliance.h"

const QString Orders_db_path = "../assets/Orders.db";

class Order
{
public:
    Order(QString date);
    virtual ~Order();
    static bool Open_Orders_db();
    virtual bool Mod_Od_db(Goods *gd) = 0;
    virtual bool Mod_DG_db(Goods *gd) = 0;
    bool operator+(Goods *gd);
    bool operator-(Goods *gd);

protected:
    static int cnt;
    int m_money;
    QString m_date;
    static QSqlDatabase Orders_db;
};

#endif
