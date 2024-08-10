#include "Food.h"

Food::Food(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path, int guarantee_period) : Goods(sm_Name, category, name, production_date, price, quantity, Goods_db_path), m_Guarantee_period(guarantee_period)
{
    if (!Create_db_Table("create table if not exists Food(supermarket_name text,category text,name text,production_date text,price int,quantity int,guarantee_period int)", "Food"))
    {
        m_Goods_db.close();
        return;
    }
    QString add_sql = QString("insert into Food values('%1','%2','%3','%4',%5,%6,%7)").arg(m_sm_Name).arg(m_category).arg(m_name).arg(m_production_date).arg(m_price).arg(m_quantity).arg(m_Guarantee_period);
    if (!Add_to_db_Table(add_sql, "Food", "goods"))
    {
        m_Goods_db.close();
        return;
    }
    m_Goods_db.close();
}

Food::~Food()
{
}

bool Food::Get_Info()
{
    return true;
}
