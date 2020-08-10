#include "States/DeleteState.h"
#include "Utils/Config.h"

DeleteState::DeleteState(std::vector<VehicleModel *> &vehicles, int deleted_vehicle)
:BaseState(vehicles), deleted_vehicle(deleted_vehicle)
{
    delete vehicles[deleted_vehicle];
    vehicles.erase(vehicles.begin() + deleted_vehicle);
}

void DeleteState::display() {
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("   Vehicle Succesfully Deleted    ");
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("0) Back                           ");
}

BaseState* DeleteState::handle_input() {
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
                default:
                    Config::pretty_print("Error: Wrong Input Value!         ");
            }

        }
    }
    return nullptr;
}



