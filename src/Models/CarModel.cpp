//
// Implementation of CarModel Class
//

#include "Models/CarModel.h"

CarModel::CarModel(const std::string &registration_plate, const std::string &make, const std::string &itp_expiry_date, const std::string &fuel_type,
                   double fuel_consumption, double odometer_count, int fabrication_year, bool is_used, int person_capacity, const std::string &owner)
                   :VehicleModel(registration_plate, make, itp_expiry_date, fuel_type, fuel_consumption, odometer_count, fabrication_year, is_used) {
    this->set_person_capacity(person_capacity);
    this->set_owner(owner);
}

void CarModel::set_person_capacity(int person_capacity) {
    if (person_capacity <= 0)
        throw "Bad Person Capacity Data!";
    this->person_capacity = person_capacity;
}

int CarModel::get_person_capacity() const {
    return this->person_capacity;
}

void CarModel::set_owner(const std::string &owner) {
    this->owner = owner;
}

std::string CarModel::get_owner() const {
    return this->owner;
}

void CarModel::print(std::ostream& output) const {
    VehicleModel::print(output);
    output << " Car";
}

void CarModel::print_in_detail(std::ostream &output) const {
    output << "Car With Attributes: \n";
    VehicleModel::print_in_detail(output);
    output << std::endl;
    output << " -> Person Capacity: " << this->person_capacity << std::endl;
    output << " -> Owner: " << this->owner;
}

void CarModel::save(std::ostream& output) const {
    output << "car,";
    VehicleModel::save(output);
    output << ',' << this->person_capacity << ',' << this->owner;
}


