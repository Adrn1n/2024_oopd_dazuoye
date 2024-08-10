#include "Goods.h"

Goods::Goods(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path) : m_sm_Name(sm_Name), m_category(category), m_name(name), m_production_date(production_date), m_price(price), m_quantity(quantity)
{
    if (!Open_db(m_Goods_db, Goods_db_path, "Goods", "Goods"))
        return;
}

Goods::~Goods()
{
}

Goods *Goods::operator*(int num)
{
    this->m_quantity *= num;
    return this;
}

QString Goods::Get_SM_Name()
{
    return m_sm_Name;
}

QString Goods::Get_category()
{
    return m_category;
}
