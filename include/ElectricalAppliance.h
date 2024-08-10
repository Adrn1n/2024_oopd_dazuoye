#ifndef ELECTRICALAPPLIANCE_H
#define ELECTRICALAPPLIANCE_H

#include "Goods.h"

#include "Create_db_Table.h"
#include "Add_to_db_Table.h"

class ElectricalAppliance : public Goods
{
private:
    QString m_color;
    int m_maintenance_period;

public:
    ElectricalAppliance(QString sm_Name, QString category, QString name, QString production_date, int price, int quantity, QString Goods_db_path, QString color, int maintenance_period);
    virtual ~ElectricalAppliance();
    bool Get_Info();
};

#endif
