#ifndef FORMAT_DATE_H
#define FORMAT_DATE_H

#include <QString>

inline QString Format_date(QString org_date, char org, char tar)
{
    QString std_date;
    int idx = org_date.indexOf(org);
    std_date += org_date.mid(0, idx);
    std_date += tar;
    org_date = org_date.mid(idx + 1);
    idx = org_date.indexOf(org);
    if (idx < 2)
        std_date += "0";
    std_date += org_date.mid(0, idx);
    std_date += tar;
    org_date = (org_date.mid(idx + 1)).trimmed();
    if (org_date.length() < 2)
        std_date += "0";
    std_date += org_date;
    return std_date;
}

#endif
