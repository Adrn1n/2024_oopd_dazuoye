#include "Return.h"

Return::Return(QString date, int req_id, QString rsn) : Order(date), m_req_id(req_id), m_rsn(rsn)
{
    if (!Create_db_Table("create table if not exists Return(id int primary key,time text,req_id int,reason text)", "Return"))
    {
        Orders_db.close();
        return;
    }
    Orders_db.close();
}

Return::~Return()
{
}

bool Return::Mod_Od_db(Goods *gd)
{
    return true;
}

bool Return::Mod_DG_db(Goods *dg)
{
    return true;
}
