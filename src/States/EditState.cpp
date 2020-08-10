#include "States/EditState.h"
#include "States/EditedState.h"
#include "Models/CarModel.h"
#include "Models/TruckModel.h"
#include "Models/BusModel.h"
#include "Utils/Config.h"

EditState::EditState(std::vector<VehicleModel *> &vehicles, int selected_vehicle)
:BaseState(vehicles), selected_vehicle(selected_vehicle)
{}

void EditState::display() {
        Config::pretty_print("   What would you like to edit?   ");
        std::cout << "\n";
        vehicles[selected_vehicle]->print_in_detail(std::cout);
        std::cout << "\n\n";
        Config::pretty_print("::::::::::::::::::::::::::::::::::");
        Config::pretty_print("1) Registration Plate             ");
        Config::pretty_print("2) ITP Date                       ");
        Config::pretty_print("3) Odometer Count                 ");
        Config::pretty_print("4) Is Currently Used              ");
        if (dynamic_cast<CarModel *>(vehicles[selected_vehicle])) {
            Config::pretty_print("5) Owner                          ");
        }
        else if (dynamic_cast<BusModel *>(vehicles[selected_vehicle])) {
            Config::pretty_print("5) Rent Price                     ");
        }
        else if (dynamic_cast<TruckModel *>(vehicles[selected_vehicle])) {
            Config::pretty_print("5) Maximum Carried Weight         ");
        }
        Config::pretty_print("::::::::::::::::::::::::::::::::::");
        Config::pretty_print("0) Back                           ");
}

BaseState* EditState::handle_input()
{
    bool running = true;
    while (running) {
        Config::pretty_print_left("> ");
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty()) {
            int input_value;
            try {
                input_value = std::stoi(input);
            } catch (std::exception& e) {
                Config::pretty_print("Error: Wrong Input Value!         ");
                continue;
            }
            switch(input_value) {
                case 1: {
                    bool correct_input = false;
                    while (!correct_input) {
                        correct_input = true;
                        Config::pretty_print("Enter New Registration Plate      ");
                        Config::pretty_print("Or 'x' To Go Back:                ");
                        Config::pretty_print_left("> ");
                        std::string input_string;
                        std::getline(std::cin, input_string);
                        if (input_string == "x") {
                            Config::pretty_print("  You Are Back To The Edit Menu   ");
                            break;
                        }
                        else {
                            try {
                                vehicles[selected_vehicle]->set_registration_plate(input_string);
                                return new EditedState(vehicles);
                            } catch (std::exception& e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            } catch (const char *e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            }
                        }
                    }
                }
                case 2: {
                    bool correct_input = false;
                    while (!correct_input) {
                        correct_input = true;
                        Config::pretty_print("Enter New ITP Date                ");
                        Config::pretty_print("Or 'x' To Go Back:                ");
                        Config::pretty_print_left("> ");
                        std::string input_string;
                        std::getline(std::cin, input_string);
                        if (input_string == "x") {
                            Config::pretty_print("  You Are Back To The Edit Menu   ");
                            break;
                        }
                        else {
                            try {
                                vehicles[selected_vehicle]->set_itp_expiry_date(Date(input_string));
                                return new EditedState(vehicles);
                            } catch (std::exception& e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            } catch (const char *e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            }
                        }
                    }
                }
                case 3: {
                    bool correct_input = false;
                    while (!correct_input) {
                        correct_input = true;
                        Config::pretty_print("Enter New Odometer Count          ");
                        Config::pretty_print("Or 'x' To Go Back:                ");
                        Config::pretty_print_left("> ");
                        std::string input_string;
                        std::getline(std::cin, input_string);
                        if (input_string == "x") {
                            Config::pretty_print("  You Are Back To The Edit Menu   ");
                            break;
                        }
                        else {
                            try {
                                int value = std::stoi(input_string);
                                vehicles[selected_vehicle]->set_odometer_count(value);
                                return new EditedState(vehicles);
                            } catch (std::exception& e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            } catch (const char *e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            }
                        }
                    }
                }
                case 4: {
                    bool correct_input = false;
                    while (!correct_input) {
                        correct_input = true;
                        Config::pretty_print("Is The Vehicle Used(1/0)?         ");
                        Config::pretty_print("Or 'x' To Go Back:                ");
                        Config::pretty_print_left("> ");
                        std::string input_string;
                        std::getline(std::cin, input_string);
                        if (input_string == "x") {
                            Config::pretty_print("  You Are Back To The Edit Menu   ");
                            break;
                        }
                        else {
                            try {
                                int value = std::stoi(input_string);
                                vehicles[selected_vehicle]->set_is_used(value);
                                return new EditedState(vehicles);
                            } catch (std::exception& e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            } catch (const char *e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            }
                        }
                    }
                }
                case 5: {
                    bool correct_input = false;
                    while (!correct_input) {
                        correct_input = true;
                        if (dynamic_cast<CarModel *>(vehicles[selected_vehicle])) {
                            Config::pretty_print("5) Enter New Owner                ");
                        }
                        else if (dynamic_cast<BusModel *>(vehicles[selected_vehicle])) {
                            Config::pretty_print("5) Enter New Rent Price           ");
                        }
                        else if (dynamic_cast<TruckModel *>(vehicles[selected_vehicle])) {
                            Config::pretty_print("5) Enter New Max Carried Weight   ");
                        }
                        Config::pretty_print("Or 'x' To Go Back:                ");
                        Config::pretty_print_left("> ");
                        std::string input_string;
                        std::getline(std::cin, input_string);
                        if (input_string == "x") {
                            Config::pretty_print("  You Are Back To The Edit Menu   ");
                            break;
                        }
                        else {
                            try {
                                if (dynamic_cast<CarModel *>(vehicles[selected_vehicle])) {
                                    CarModel* cp = dynamic_cast<CarModel *>(vehicles[selected_vehicle]);
                                    cp->set_owner(input_string);
                                }
                                else if (dynamic_cast<BusModel *>(vehicles[selected_vehicle])) {
                                    int value = std::stoi(input_string);
                                    BusModel* bp = dynamic_cast<BusModel *>(vehicles[selected_vehicle]);
                                    bp->set_rent_price(value);
                                }
                                else if (dynamic_cast<TruckModel *>(vehicles[selected_vehicle])) {
                                    int value = std::stoi(input_string);
                                    TruckModel* tp = dynamic_cast<TruckModel *>(vehicles[selected_vehicle]);
                                    tp->set_max_carried_weight(value);
                                }
                                return new EditedState(vehicles);
                            } catch (std::exception& e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            } catch (const char *e) {
                                Config::pretty_print("Bad Input Data!                   ");
                                correct_input = false;
                            }
                        }
                    }
                }
                case 0:
                    return nullptr;
                default:
                    Config::pretty_print("Error: Wrong Input Value!         ");
            }

        }
    }
}

