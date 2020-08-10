//
// Truck Model Class
//

#ifndef FLEETVEHICLES_TRUCKMODEL_H
#define FLEETVEHICLES_TRUCKMODEL_H

#include "Models/VehicleModel.h"
#include <string>
#include <iostream>

class TruckModel : public VehicleModel {
public:

    TruckModel(const std::string &registration_plate, const std::string &make,
               const std::string &itp_expiry_date, const std::string &fuel_type,
               double fuel_consumption, double odometer_count, int fabrication_year,
               bool is_used, int max_carried_weight);

    void            print(std::ostream& output) const;
    void            print_in_detail(std::ostream& output) const;
    void            save(std::ostream& output) const;

    void            set_max_carried_weight(int max_carried_weight);
    int             get_max_carried_weight() const;


private:
    int max_carried_weight;

};



#endif //FLEETVEHICLES_TRUCKMODEL_H
