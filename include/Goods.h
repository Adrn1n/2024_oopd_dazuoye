#ifndef GOODS_H
#define GOODS_H

#include "Open_db.h"

class Goods
{
protected:
    QString m_sm_Name, m_category, m_name, m_production_date;
    int m_price, m_quantity;
    QSqlDatabase m_Goods_db;

public:
    Goods(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path);
    virtual ~Goods();
    Goods *operator*(int num);
    QString Get_SM_Name();
    QString Get_category();
    virtual bool Get_Info() = 0;
};

#endif
