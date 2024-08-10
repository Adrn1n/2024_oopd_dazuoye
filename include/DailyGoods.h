#ifndef DAILYGOODS_H
#define DAILYGOODS_H

#include "Goods.h"

#include "Create_db_Table.h"
#include "Add_to_db_Table.h"

class DailyGoods : public Goods
{
public:
    DailyGoods(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path);
    virtual ~DailyGoods();
    bool Get_Info();
};

#endif
