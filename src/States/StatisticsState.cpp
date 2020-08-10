#include "States/StatisticsState.h"
#include "States/SpecificStatState.h"
#include "Utils/Config.h"

StatisticsState::StatisticsState(std::vector<VehicleModel *> &vehicles, const std::string& type)
:BaseState(vehicles), type(type)
{}

void StatisticsState::display() {
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("      Choose Statistics Type      ");
    Config::pretty_print("                                  ");
    Config::pretty_print("1) Fabricated Before Year         ");
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("0) Back                           ");
}

BaseState* StatisticsState::handle_input() {
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
                case 1: {
                    bool correct_input = false;
                    while (!correct_input) {
                        correct_input = true;
                        Config::pretty_print("Enter Year:                       ");
                        Config::pretty_print("Or 'x' To Go Back:                ");
                        Config::pretty_print_left("> ");
                        std::string input_string;
                        std::getline(std::cin, input_string);
                        if (input_string == "x") {
                            Config::pretty_print("  You Are Back To The Stats Menu  ");
                            break;
                        }
                        else {
                            try {
                            int year = std::stoi(input_string);
                            return new SpecificStatState(vehicles, [year](VehicleModel *v) -> bool {
                                return year >= v->get_fabrication_year();
                            }, type);
                            } catch(std::exception& e) {
                                Config::pretty_print("Error: Wrong Input Value!         ");
                                correct_input = false;
                            }
                        }
                    }
                    break;
                }
                default:
                    Config::pretty_print("Error: Wrong Input Value!         ");
                    break;
            }
        }
    }
}
