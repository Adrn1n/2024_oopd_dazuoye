#ifndef FOOD_H
#define FOOD_H

#include "Goods.h"

#include "Create_db_Table.h"
#include "Add_to_db_Table.h"

class Food : public Goods
{
private:
    int m_Guarantee_period;

public:
    Food(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path, int guarantee_period);
    virtual ~Food();
    bool Get_Info();
};

#endif
