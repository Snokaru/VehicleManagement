//
// Main State Implementation
//

#include "States/MainState.h"
#include "States/ListState.h"
#include "States/VehicleTypeState.h"
#include "States/AddVehicleState.h"
#include "Utils/Config.h"



MainState::MainState(std::vector<VehicleModel *> &vehicles) : BaseState(vehicles) {}

void MainState::display() {
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("             Main Menu            ");
    Config::pretty_print("                                  ");
    Config::pretty_print("1) List All Vehicles              ");
    Config::pretty_print("2) List Vehicles With Expiring ITP");
    Config::pretty_print("3) List Unused Vehicles           ");
    Config::pretty_print("4) Add Vehicle                    ");
    Config::pretty_print("5) Statistics                     ");
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("0) Exit                           ");
}

BaseState* MainState::handle_input() {
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
                case 0:
                    return nullptr;
                    break;
                case 1:
                    return new ListState(vehicles);
                    break;
                case 2: {
                    bool correct_input = false;
                    while (!correct_input) {
                        correct_input = true;
                        Config::pretty_print("Enter Current Date(dd/mm/yyyy)    ");
                        Config::pretty_print("Or 'x' To Go Back:                ");
                        Config::pretty_print_left("> ");
                        std::string input_string;
                        std::getline(std::cin, input_string);
                        if (input_string == "x") {
                            Config::pretty_print("  You Are Back To The Main Menu   ");
                            break;
                        }
                        else {
                            try {
                                Date current_date(input_string);
                                return new ListState(vehicles, [current_date](VehicleModel* v) -> bool {
                                    return current_date.get_month() == v->get_itp_expiry_date().get_month() && current_date.get_year() == v->get_itp_expiry_date().get_year();
                                });
                            } catch (std::exception& e) {
                                Config::pretty_print("Bad Input Date!                   ");
                                correct_input = false;
                            } catch (const char * e) {
                                Config::pretty_print("Bad Input Date!                   ");
                                correct_input = false;
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    return new ListState(vehicles, [](VehicleModel* v) -> bool {
                        return !v->get_is_used();
                    });
                    break;
                }
                case 4:
                    return new AddVehicleState(vehicles);
                    break;

                case 5:
                    return new VehicleTypeState(vehicles);
                    break;

                default:
                    Config::pretty_print("Error: Wrong Input Value!         ");
                    continue;
            }

        }
    }
    return nullptr;
}
