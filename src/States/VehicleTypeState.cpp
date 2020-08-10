#include "States/VehicleTypeState.h"
#include "States/StatisticsState.h"
#include "Utils/Config.h"

VehicleTypeState::VehicleTypeState(std::vector<VehicleModel *> &vehicles)
:BaseState(vehicles) {
}

void VehicleTypeState::display() {
        Config::pretty_print("::::::::::::::::::::::::::::::::::");
        Config::pretty_print("      Choose A Vehicle Type       ");
        Config::pretty_print("                                  ");
        Config::pretty_print("1) Car                            ");
        Config::pretty_print("2) Truck                          ");
        Config::pretty_print("3) Bus                            ");
        Config::pretty_print("4) All                            ");
        Config::pretty_print("::::::::::::::::::::::::::::::::::");
        Config::pretty_print("0) Back                           ");
}

BaseState* VehicleTypeState::handle_input() {
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
                    return new StatisticsState(vehicles, "car");
                    break;
                case 2:
                    return new StatisticsState(vehicles, "truck");
                    break;
                case 3:
                    return new StatisticsState(vehicles, "bus");
                    break;
                case 4:
                    return new StatisticsState(vehicles);
                    break;
                default:
                    Config::pretty_print("Error: Wrong Input Value!         ");
                    break;
            }

        }
    }
}
