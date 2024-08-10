#ifndef RETURN_H
#define RETURN_H

#include "Order.h"

class Return : public Order
{
public:
    Return(QString date, int req_id, QString rsn);
    virtual ~Return();
    bool Mod_Od_db(Goods *gd);
    bool Mod_DG_db(Goods *gd);

private:
    int m_req_id;
    QString m_rsn;
};

#endif
