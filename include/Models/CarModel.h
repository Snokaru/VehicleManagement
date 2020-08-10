//
// Car Model That Inherits Vehicle
//

#ifndef FLEETVEHICLES_CARMODEL_H
#define FLEETVEHICLES_CARMODEL_H

#include "Models/VehicleModel.h"
#include <string>
#include <iostream>

class CarModel : public VehicleModel {
public:

    CarModel(const std::string &registration_plate, const std::string &make,
             const std::string &itp_expiry_date, const std::string &fuel_type,
             double fuel_consumption, double odometer_count, int fabrication_year,
             bool is_used, int person_capacity, const std::string& owner);

    void            print(std::ostream& output) const;
    void            print_in_detail(std::ostream& output) const;
    void            save(std::ostream& output) const;

    void            set_person_capacity(int person_capacity);
    int             get_person_capacity() const;

    void            set_owner(const std::string& owner);
    std::string     get_owner() const;

private:
    int             person_capacity;
    std::string     owner;
};


#endif //FLEETVEHICLES_CARMODEL_H
