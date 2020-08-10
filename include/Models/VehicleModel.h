//
// Vehicle Model Class
//

#ifndef FLEETVEHICLES_VEHICLEMODEL_H
#define FLEETVEHICLES_VEHICLEMODEL_H

#include <string>
#include <iostream>
#include "Utils/Date.h"

class VehicleModel {

public:
    // Constructor Pentru Initiere Cu Date Din Program
    VehicleModel(const std::string& registration_plate, const std::string& make,
                 const Date& itp_expiry_date, const std::string& fuel_type,
                 double fuel_consumption, double odometer_count, int fabrication_year, bool is_used);

    // Metode Pentru Scriere si Afisare Pe Stream
    virtual void        print(std::ostream& output) const;
    virtual void        print_in_detail(std::ostream& output) const;
    virtual void        save(std::ostream& output) const;

    // Setters And Getters For Class Attributes
    long long           get_id() const;


    void                set_registration_plate(const std::string& registration_plate); //TODO: ADD NAMEPLATE REGEX VALIDATION
    std::string         get_registration_plate() const;

    void                set_itp_expiry_date(const Date& itp_expiry_date);
    Date                get_itp_expiry_date() const;

    void                set_make(const std::string& make);
    std::string         get_make() const;

    void                set_fuel_type(const std::string& fuel_type);
    std::string         get_fuel_type() const;

    void                set_fuel_consumption(double fuel_consumption);
    double              get_fuel_consumption() const;

    void                set_odometer_count(double odometer_count);
    double              get_odometer_count() const;

    void                set_fabrication_year(int fabrication_year);
    int                 get_fabrication_year() const;

    bool                get_is_used();
    void                set_is_used(bool is_used);

protected:
    static long long    max_id;

    bool                is_used;
    long long           id;
    Date                itp_expiry_date;
    std::string         registration_plate;
    std::string         make;
    std::string         fuel_type;
    double              fuel_consumption;
    long long           odometer_count;
    int                 fabrication_year;
};

#endif //FLEETVEHICLES_VEHICLEMODEL_H
