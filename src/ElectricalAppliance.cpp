#include "ElectricalAppliance.h"

ElectricalAppliance::ElectricalAppliance(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path, QString color, int maintenance_period) : Goods(sm_Name, category, name, production_date, price, quantity, Goods_db_path), m_color(color), m_maintenance_period(maintenance_period)
{
    if (!Create_db_Table("create table if not exists ElectricalAppliance(supermarket_name text,category text,name text,production_date text,price int,quantity int,color text,maintenance_period text)", "ElectricalAppliance"))
    {
        m_Goods_db.close();
        return;
    }
    QString add_sql = QString("insert into ElectricalAppliance values('%1','%2','%3','%4',%5,%6,'%7',%8)").arg(m_sm_Name).arg(m_category).arg(m_name).arg(m_production_date).arg(m_price).arg(m_quantity).arg(m_color).arg(m_maintenance_period);
    if (!Add_to_db_Table(add_sql, "ElectricalAppliance", "goods"))
    {
        m_Goods_db.close();
        return;
    }
    m_Goods_db.close();
}

ElectricalAppliance::~ElectricalAppliance()
{
}

bool ElectricalAppliance::Get_Info()
{
    return true;
}
