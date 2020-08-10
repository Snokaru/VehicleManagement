//
// Implementation Of TruckModel Class
//

#include "Models/TruckModel.h"

TruckModel::TruckModel(const std::string &registration_plate, const std::string &make,
                       const std::string &itp_expiry_date, const std::string &fuel_type, double fuel_consumption,
                       double odometer_count, int fabrication_year, bool is_used, int max_carried_weight)
                       :VehicleModel(registration_plate, make, itp_expiry_date, fuel_type, fuel_consumption, odometer_count, fabrication_year, is_used){
    this->set_max_carried_weight(max_carried_weight);
}

void TruckModel::set_max_carried_weight(int max_carried_weight) {
    if (max_carried_weight <= 0)
        throw "Bad Carried Weight Data!";
    this->max_carried_weight = max_carried_weight;
}

int TruckModel::get_max_carried_weight() const {
    return this->max_carried_weight;
}

void TruckModel::print(std::ostream &output) const {
    VehicleModel::print(output);
    output << " Truck";
}

void TruckModel::print_in_detail(std::ostream &output) const {
    output << "Truck With Attributes: \n";
    VehicleModel::print_in_detail(output);
    output << std::endl;
    output << " -> Maximum Carried Weight: " << this->max_carried_weight << "tons";
}

void TruckModel::save(std::ostream &output) const {
    output << "truck,";
    VehicleModel::save(output);
    output << ',' << this->max_carried_weight;
}


