#ifndef MONEY_CONVERT_H
#define MONEY_CONVERT_H

#include <QString>

inline QString IntMoney_to_Str(int i_money)
{
    QString s_money = QString::number(i_money / 100);
    short r = i_money % 100;
    if (r)
    {
        s_money += ".";
        if (r % 10)
            s_money += QString::number(r);
        else
            s_money += QString::number(r / 10);
    }
    return s_money;
}

inline int StrMoney_to_Int(QString s_money)
{
    int i_money = 0;
    int index = s_money.indexOf(".");
    if (index != -1)
    {
        i_money = 100 * (s_money.mid(0, index)).toInt();
        s_money = (s_money.mid(index + 1)).trimmed();
        short r = 1;
        if (s_money.length() < 2)
            r = 10;
        i_money += r * s_money.toInt();
    }
    else
        i_money = 100 * s_money.toInt();
    return i_money;
}

#endif
