//
// Implementation of BusModel Class
//

#include "Models/BusModel.h"

BusModel::BusModel(const std::string &registration_plate, const std::string &make, const std::string &itp_expiry_date,
                   const std::string &fuel_type, double fuel_consumption, double odometer_count, int fabrication_year,
                   bool is_used, int person_capacity, int rent_price)
                   :VehicleModel(registration_plate, make, itp_expiry_date, fuel_type, fuel_consumption, odometer_count, fabrication_year, is_used) {
    this->set_person_capacity(person_capacity);
    this->set_rent_price(rent_price);
}

void BusModel::set_person_capacity(int person_capacity) {
    if (person_capacity <= 0)
        throw "Bad Person Capacity Data!";
    this->person_capacity = person_capacity;
}

int BusModel::get_person_capacity() const {
    return this->person_capacity;
}

void BusModel::set_rent_price(int rent_price) {
    if (rent_price <= 0)
        throw "Bad Rent Price Data!";
    this->rent_price = rent_price;
}

int BusModel::get_rent_price() const {
    return this->rent_price;
}

void BusModel::print(std::ostream &output) const {
    VehicleModel::print(output);
    output << (" Bus");
}

void BusModel::print_in_detail(std::ostream &output) const {
    output << "Bus With Attributes: \n";
    VehicleModel::print_in_detail(output);
    output << std::endl;
    output << " -> Person Capacity: " << this->person_capacity << std::endl;
    output << " -> Rent Price: $" << this->rent_price;
}

void BusModel::save(std::ostream& output) const {
    output << "bus,";
    VehicleModel::save(output);
    output << ',' << this->person_capacity << ',' << this->rent_price;
}




