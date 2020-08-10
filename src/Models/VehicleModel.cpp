//
// Implementation of VehicleModel Class
//

#include "Models/VehicleModel.h"

long long VehicleModel::max_id = 0;

VehicleModel::VehicleModel(const std::string& registration_plate, const std::string& make, const Date& itp_expiry_date, const std::string& fuel_type,
                           double fuel_consumption, double odometer_count, int fabrication_year, bool is_used)
                           :id(++max_id), itp_expiry_date(itp_expiry_date){
    this->set_registration_plate(registration_plate);
    this->set_make(make);
    this->set_fuel_type(fuel_type);
    this->set_fuel_consumption(fuel_consumption);
    this->set_odometer_count(odometer_count);
    this->set_fabrication_year(fabrication_year);
    this->set_is_used(is_used);
}

void VehicleModel::set_registration_plate(const std::string& registration_plate) {
    // TODO: ADD REGISTRATION PLATE REGEX CHECK
    this->registration_plate = registration_plate;
}

std::string VehicleModel::get_registration_plate() const {
    return this->registration_plate;
}

void VehicleModel::set_make(const std::string &make) {
    this->make = make;
}

std::string VehicleModel::get_make() const {
    return this->make;
}

void VehicleModel::set_fuel_type(const std::string &fuel_type) {
    this->fuel_type = fuel_type;
}

std::string VehicleModel::get_fuel_type() const {
    return this->fuel_type;
}

void VehicleModel::set_fuel_consumption(double fuel_consumption) {
    if (fuel_consumption < 0 || fuel_consumption > 100)
        throw "Invalid Fuel Consumption Data!";
    this->fuel_consumption = fuel_consumption;
}

double VehicleModel::get_fuel_consumption() const {
    return this->fuel_consumption;
}

void VehicleModel::set_odometer_count(double odometer_count) {
    if (odometer_count < 0)
        throw "Invalid Odometer Count Data!";
    this->odometer_count = odometer_count;
}

double VehicleModel::get_odometer_count() const {
    return this->odometer_count;
}

void VehicleModel::set_fabrication_year(int fabrication_year) {
    if (fabrication_year < 1900 || fabrication_year > 2020)
        throw "Invalid Fabrication Year Data!";
    this->fabrication_year = fabrication_year;
}

int VehicleModel::get_fabrication_year() const {
    return this->fabrication_year;
}

Date VehicleModel::get_itp_expiry_date() const {
    return this->itp_expiry_date;
}

void VehicleModel::set_itp_expiry_date(const Date &itp_expiry_date) {
    // TODO: VALIDATE DATE
    this->itp_expiry_date = itp_expiry_date;
}

void VehicleModel::print(std::ostream &output) const {
    output << this->fabrication_year << " " << this->make;
}

void VehicleModel::print_in_detail(std::ostream &output) const {
    output << " -> Make: " << this->make << std::endl;
    output << " -> Fabrication Year: " << this->fabrication_year << std::endl;
    output << " -> Registration Plate: " << this->registration_plate << std::endl;
    output << " -> ITP Expiry: " << this->itp_expiry_date << std::endl;
    output << " -> Fuel Type: " << this->fuel_type << std::endl;
    output << " -> Fuel Consumption: " << this->fuel_consumption << "%" << std::endl;
    output << " -> Odometer Count: " << this->odometer_count << "km" << std::endl;
    output << " -> Is Currently Used: " << (this->is_used == true ? "Yes" : "No");
}

void VehicleModel::save(std::ostream &output) const {
    output << make << ',' << registration_plate << ',' << itp_expiry_date << ',';
    output << fuel_type << ',' << fuel_consumption << ',' << odometer_count << ',' << fabrication_year << ',' << (is_used == true ? '1' : '0');
}

long long VehicleModel::get_id() const {
    return this->id;
}

bool VehicleModel::get_is_used() {
    return this->is_used;
}

void VehicleModel::set_is_used(bool is_used) {
    this->is_used = is_used;
}
