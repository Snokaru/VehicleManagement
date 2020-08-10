#include "States/AddVehicleState.h"
#include "Utils/Config.h"
#include "Models/CarModel.h"
#include "Models/BusModel.h"
#include "Models/TruckModel.h"

AddVehicleState::AddVehicleState(std::vector<VehicleModel *> &vehicles)
:BaseState(vehicles)
{}

void AddVehicleState::display() {
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("        Add A New Vehicle         ");

}

BaseState* AddVehicleState::handle_input()
{
    bool correct_data = false;
    while (!correct_data) {
        correct_data = true;
        std::string type, make, itp_date, registration_plate, itp_expiry_date;
        std::string fuel_type, fuel_consumption, odometer_count, fabrication_year;
        std::string is_used;
        Config::pretty_print("Type(car/bus/truck):              ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, type);

        Config::pretty_print("Make:                             ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, make);

        Config::pretty_print("Registration Plate:               ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, registration_plate);

        Config::pretty_print("ITP Expiry Date(dd/mm/yyyy):      ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, itp_expiry_date);

        Config::pretty_print("Fuel Type:                        ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, fuel_type);

        Config::pretty_print("Fuel Consumption Percentage:      ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, fuel_consumption);

        Config::pretty_print("Odometer Count:                   ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, odometer_count);

        Config::pretty_print("Fabrication Year:                 ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, fabrication_year);

        Config::pretty_print("Is The Car Currently Used(1/0)?   ");
        Config::pretty_print_left("> ");
        std::getline(std::cin, is_used);



        if (type == "car") {
            std::string person_capacity, owner;

            Config::pretty_print("Person Capacity:                  ");
            Config::pretty_print_left("> ");
            std::getline(std::cin, person_capacity);

            Config::pretty_print("Owner:                            ");
            Config::pretty_print_left("> ");
            std::getline(std::cin, owner);

            try {
            vehicles.push_back(new CarModel(registration_plate, make, itp_expiry_date, fuel_type,std::stod(fuel_consumption), std::stoll(odometer_count), std::stoi(fabrication_year), std::stoi(is_used), std::stoi(person_capacity), owner));
            } catch (std::exception& e) {
                correct_data = false;
                Config::clear_screen();
                Config::pretty_print("Bad Input Data. Try Again         ");

            } catch (const char * e) {
                correct_data = false;
                Config::clear_screen();
                Config::pretty_print("Bad Input Data. Try Again         ");
            }
        }
        else if (type == "truck") {
            std::string max_carried_weight;
            Config::pretty_print("Max Carried Weight:               ");
            std::getline(std::cin, max_carried_weight);

            try {
                vehicles.push_back(new TruckModel(registration_plate, make, itp_expiry_date, fuel_type, std::stod(fuel_consumption), std::stoll(odometer_count), std::stoi(fabrication_year), std::stoi(is_used), std::stoi(max_carried_weight)));
            } catch (std::exception& e) {
                correct_data = false;
                Config::clear_screen();
                Config::pretty_print("Bad Input Data. Try Again         ");

            } catch (const char * e) {
                correct_data = false;
                Config::clear_screen();
                Config::pretty_print("Bad Input Data. Try Again         ");


            }
        }
        else if (type == "bus") {
            std::string person_capacity, rent_price;

            Config::pretty_print("Person Capacity:                  ");
            Config::pretty_print_left("> ");
            std::getline(std::cin, person_capacity);

            Config::pretty_print("Rent Price:                       ");
            Config::pretty_print_left("> ");
            std::getline(std::cin, rent_price);

            try {
                vehicles.push_back(new BusModel(registration_plate, make, itp_expiry_date, fuel_type, std::stod(fuel_consumption), std::stoll(odometer_count), std::stoi(fabrication_year), std::stoi(is_used), std::stoi(person_capacity), std::stoi(rent_price)));
            } catch (std::exception& e) {
                correct_data = false;
                Config::clear_screen();
                Config::pretty_print("Bad Input Data. Try Again         ");
            } catch (const char * e) {
                correct_data = false;
                Config::clear_screen();
                Config::pretty_print("Bad Input Data. Try Again         ");
            }
        }
        else {
            correct_data = false;
            Config::clear_screen();
            Config::pretty_print("Bad Input Data. Try Again         ");
        }
    }
    return nullptr;
}
