//
// Vehicle Factory Implementation
// Format Of Vehicle Data String:
// {type},{make},{registration_plate},{itp_expiry_date},{fuel_type},{fuel_consumption},
// {odometer_count},{fabrication_year}
// For Cars: {person_capacity},{owner}
// For Trucks: {max_carried_weight}
// For Buses: {person_capacity},{rent_price}

#include "Models/VehicleFactory.h"
#include "Models/TruckModel.h"
#include "Models/BusModel.h"
#include "Models/CarModel.h"
#include <sstream>

VehicleModel* VehicleFactory::create(const std::string &vehicle_string) {
    std::stringstream input(vehicle_string);
    std::string type, make, itp_expiry_date, registration_plate, fuel_type, fuel_consumption, odometer_count, fabrication_year, is_used;
    std::getline(input, type, delimiter);
    std::getline(input, make, delimiter);
    std::getline(input, registration_plate, delimiter);
    std::getline(input, itp_expiry_date, delimiter);
    std::getline(input, fuel_type, delimiter);
    std::getline(input, fuel_consumption, delimiter);
    std::getline(input, odometer_count, delimiter);
    std::getline(input, fabrication_year, delimiter);
    std::getline(input, is_used, delimiter);
    if (type == "car") {
        std::string person_capacity, owner;
        std::getline(input, person_capacity, delimiter);
        std::getline(input, owner);
        return new CarModel(registration_plate, make, itp_expiry_date, fuel_type,std::stod(fuel_consumption), std::stoll(odometer_count), std::stoi(fabrication_year), std::stoi(is_used), std::stoi(person_capacity), owner);
    }
    else if (type == "truck") {
        std::string max_carried_weight;
        std::getline(input, max_carried_weight);
        return new TruckModel(registration_plate, make, itp_expiry_date, fuel_type, std::stod(fuel_consumption), std::stoll(odometer_count), std::stoi(fabrication_year), std::stoi(is_used), std::stoi(max_carried_weight));
    }
    else {
        std::string person_capacity, rent_price;
        std::getline(input, person_capacity, delimiter);
        std::getline(input, rent_price);
        return new BusModel(registration_plate, make, itp_expiry_date, fuel_type, std::stod(fuel_consumption), std::stoll(odometer_count), std::stoi(fabrication_year), std::stoi(is_used), std::stoi(person_capacity), std::stoi(rent_price));
    }
}
