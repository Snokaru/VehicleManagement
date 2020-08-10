#include "States/EditedState.h"
#include "Utils/Config.h"

EditedState::EditedState(std::vector<VehicleModel *> &vehicles)
:BaseState(vehicles)
{
}

void EditedState::display() {
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("   The Vehicle Has Been Edited    ");
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("0) Back                           ");
}

BaseState* EditedState::handle_input() {
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
                    break;
            }

        }
    }
}
