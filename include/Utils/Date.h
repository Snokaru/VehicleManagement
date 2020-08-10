//
// Date Class In The dd/mm/yy format
//

#ifndef FLEETVEHICLES_DATE_H
#define FLEETVEHICLES_DATE_H

#include <string>
#include <iostream>

class Date {
public:

    Date(const std::string &formatted_date);

    friend std::ostream&    operator<<(std::ostream& output, const Date& date);

    int                     get_month() const;
    int                     get_day() const;
    int                     get_year() const;

private:
    static const int        days_per_month[13];
    std::string             date;
    int                     month, day, year;
};


#endif //FLEETVEHICLES_DATE_H
