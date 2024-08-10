#include "DailyGoods.h"

DailyGoods::DailyGoods(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path) : Goods(sm_Name, category, name, production_date, price, quantity, Goods_db_path)
{
    if (!Create_db_Table("create table if not exists DailyGoods(supermarket_name text,category text,name text,production_date text,price int,quantity int)", "DailyGoods"))
    {
        m_Goods_db.close();
        return;
    }
    QString add_sql = QString("insert into DailyGoods values('%1','%2','%3','%4',%5,%6)").arg(m_sm_Name).arg(m_category).arg(m_name).arg(m_production_date).arg(m_price).arg(m_quantity);
    if (!Add_to_db_Table(add_sql, "DailyGoods", "goods"))
    {
        m_Goods_db.close();
        return;
    }
    m_Goods_db.close();
}

DailyGoods::~DailyGoods()
{
}

bool DailyGoods::Get_Info()
{
    return true;
}
