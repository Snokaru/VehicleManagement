#include "States/DetailState.h"
#include "States/DeleteState.h"
#include "States/EditState.h"
#include "Utils/Config.h"
#include <iostream>

DetailState::DetailState(std::vector<VehicleModel *> &vehicles, int selected_vehicle)
:BaseState(vehicles), selected_vehicle(selected_vehicle)
{}

void DetailState::display() {
        Config::pretty_print("         Selected Vehicle         ");
        std::cout << "\n";
        vehicles[selected_vehicle]->print_in_detail(std::cout);
        std::cout << "\n\n";
        Config::pretty_print("::::::::::::::::::::::::::::::::::");
        Config::pretty_print("1) Edit Vehicle                   ");
        Config::pretty_print("2) Delete Vehicle                 ");
        Config::pretty_print("::::::::::::::::::::::::::::::::::");
        Config::pretty_print("0) Back                           ");
}

BaseState* DetailState::handle_input()
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
                case 1:
                    return new EditState(vehicles, selected_vehicle);
                case 2:
                    return new DeleteState(vehicles, selected_vehicle);
                case 0:
                    return nullptr;
                default:
                    Config::pretty_print("Error: Wrong Input Value!         ");
            }

        }
    }
}
