#include "States/ListState.h"
#include "Utils/Config.h"
#include "States/DetailState.h"

#include <algorithm>

ListState::ListState(std::vector<VehicleModel *> &vehicles, std::function<bool(VehicleModel *)> filter)
:BaseState(vehicles), filter(filter) {
}

void ListState::display() {
    this->filter_vehicles();
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("         Select A Vehicle         ");
    Config::pretty_print("                                  ");
    for (auto i = 0; i < filtered_vehicles.size(); i++) {
        Config::pretty_print_left(std::to_string(i + 1) + ") ");
        filtered_vehicles[i].second->print(std::cout);
        std::cout << std::endl;
    }
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("0) Back                           ");
}

BaseState* ListState::handle_input() {
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
                    if (input_value > 0 && input_value <= filtered_vehicles.size()) {
                        return new DetailState(vehicles, filtered_vehicles[input_value - 1].first);
                    }
                    else {
                        Config::pretty_print("Error: Wrong Input Value!         ");
                    }
            }

        }
    }
}

void ListState::filter_vehicles()
{
    filtered_vehicles.clear();
    for (auto i = 0; i < vehicles.size(); i++) {
        if (filter == nullptr || filter(vehicles[i])) {
            filtered_vehicles.push_back(std::make_pair(i, vehicles[i]));
        }
    }
}
