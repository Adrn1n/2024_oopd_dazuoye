#include "Purchase.h"

Purchase::Purchase(QString date) : Order(date)
{
    if (!Create_db_Table("create table if not exists Purchase(id int,date text,money int)", "Purchase"))
    {
        Orders_db.close();
        return;
    }
    Orders_db.close();
}

Purchase::~Purchase()
{
}

bool Purchase::Mod_Od_db(Goods *gd)
{
    return true;
}

bool Purchase::Mod_DG_db(Goods *dg)
{
    return true;
}
