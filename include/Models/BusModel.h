//
// Bus Model that inherits from Vehicle
//

#ifndef FLEETVEHICLES_BUSMODEL_H
#define FLEETVEHICLES_BUSMODEL_H

#include "Models/VehicleModel.h"
#include <string>
#include <iostream>

class BusModel : public VehicleModel {
public:

    BusModel(const std::string &registration_plate, const std::string &brand,
             const std::string &itp_expiry_date, const std::string &fuel_type,
             double fuel_consumption, double odometer_count, int fabrication_year,
             bool is_used, int person_capacity, int rent_price);

    void            print(std::ostream& output) const;
    void            print_in_detail(std::ostream& output) const;
    void            save(std::ostream& output) const;

    void            set_person_capacity(int person_capacity);
    int             get_person_capacity() const;

    void            set_rent_price(int rent_price);
    int             get_rent_price() const;

private:
    int             person_capacity;
    int             rent_price;
};


#endif //FLEETVEHICLES_BUSMODEL_H
