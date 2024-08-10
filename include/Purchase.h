#ifndef PURCHASE_H
#define PURCHASE_H

#include "Order.h"

class Purchase : public Order
{
public:
    Purchase(QString date);
    virtual ~Purchase();
    bool Mod_Od_db(Goods *gd);
    bool Mod_DG_db(Goods *gd);
};

#endif
