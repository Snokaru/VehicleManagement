//
// Vehicle Factory Method To Create A Vehicle Based On Type
// {type},{make},{registration_plate},{itp_expiry_date},{fuel_type},{fuel_consumption},
// {odometer_count},{fabrication_year}
// For Cars: {person_capacity},{owner}
// For Trucks: {max_carried_weight}
// For Buses: {person_capacity},{rent_price}

#ifndef FLEETVEHICLES_VEHICLEFACTORY_H
#define FLEETVEHICLES_VEHICLEFACTORY_H
#include "Models/VehicleModel.h"
#include <iostream>
#include <string>

class VehicleFactory {
public:
    VehicleModel*       create(const std::string &vehicle_string);
private:
    static const char   delimiter = ',';
};





#endif //FLEETVEHICLES_VEHICLEFACTORY_H
