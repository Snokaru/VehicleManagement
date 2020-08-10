//
// Created by zigza on 6/4/2020.
//

#include "Utils/Date.h"
#include <sstream>

const int Date::days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(const std::string &formatted_date)
{
    std::stringstream date_stream(formatted_date);
    std::string temp;

    std::getline(date_stream, temp, '/');
    int date_day = std::stoi(temp);

    std::getline(date_stream, temp, '/');
    int date_month = std::stoi(temp);

    std::getline(date_stream, temp);
    int date_year = std::stoi(temp);

    bool is_leap_year = (date_year % 4 == 0);
    if(is_leap_year && date_month == 2 && date_day > 29)
        throw "Bad Date Data!";
    else if (!is_leap_year && date_month == 2 && date_day > 28)
        throw "Bad Date Data!";
    else if (Date::days_per_month[date_month] < date_day || date_day <= 0 || date_month > 12 || date_month <= 0)
        throw "Bad Date Data!";
    else {
        this->month = date_month;
        this->day = date_day;
        this->year = date_year;
        this->date = formatted_date;
    }

}

int Date::get_day() const {
    return this->day;
}

int Date::get_month() const {
    return this->month;
}

int Date::get_year() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& output, const Date& date) {
    output << date.date;
}
