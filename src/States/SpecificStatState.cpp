#include "States/SpecificStatState.h"
#include "Models/CarModel.h"
#include "Models/BusModel.h"
#include "Models/TruckModel.h"
#include "States/ListState.h"
#include "Utils/Config.h"

SpecificStatState::SpecificStatState(std::vector<VehicleModel *> &vehicles, std::function<bool(VehicleModel *)> filter, const std::string& type)
:BaseState(vehicles), filter(filter), type(type)
{}

void SpecificStatState::display() {
    this->filter_vehicles();
    Config::pretty_print("::::::::::::::::::::::::::::::::::");

    std::string vehicle_type;
    if (type == "car")
        vehicle_type = "Cars";
    else if (type == "bus")
        vehicle_type = "Buses";
    else if (type == "truck")
        vehicle_type = "Trucks";
    else
        vehicle_type = "Vehicles";

    std::cout << std::endl;
    std::cout << "There Are " + std::to_string(filtered_vehicles.size()) + " " + vehicle_type + " That Satisfy The Property";
    std::cout << std::endl;
    std::cout << "There Are " + std::to_string(vehicles_of_type - filtered_vehicles.size()) + " " + vehicle_type + " That Do Not Satisfy The Property";
    std::cout << std::endl << std::endl;
    Config::pretty_print_left("1) List " + vehicle_type + " That Satisfy The Property");
    std::cout << std::endl;
    Config::pretty_print_left("2) List " + vehicle_type + " That Do Not Satisfy The Property");
    std::cout << std::endl;
    Config::pretty_print("::::::::::::::::::::::::::::::::::");
    Config::pretty_print("0) Back                           ");
}

BaseState* SpecificStatState::handle_input() {
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
                    std::string temp_str = type;
                    std::function<bool(VehicleModel *)> temp_fun = filter;
                    return new ListState(vehicles, [temp_str, temp_fun](VehicleModel *v) {
                        if (temp_str == "" || (temp_str == "car" && dynamic_cast<CarModel *>(v)) || (temp_str == "bus" && dynamic_cast<BusModel *>(v)) || (temp_str == "truck" && dynamic_cast<TruckModel *>(v))) {
                            return temp_fun(v);
                        }
                        return false;
                    });
                }
                case 2: {
                    std::string temp_str = type;
                    std::function<bool(VehicleModel *)> temp_fun = filter;
                    return new ListState(vehicles, [temp_str, temp_fun](VehicleModel *v) {
                        if (temp_str == "" || (temp_str == "car" && dynamic_cast<CarModel *>(v)) || (temp_str == "bus" && dynamic_cast<BusModel *>(v)) || (temp_str == "truck" && dynamic_cast<TruckModel *>(v))) {
                            return !temp_fun(v);
                        }
                        return false;
                    });
                }
                default:
                    Config::pretty_print("Error: Wrong Input Value!         ");
                    break;

            }

        }
    }
}

void SpecificStatState::filter_vehicles()
{
    filtered_vehicles.clear();
    vehicles_of_type = 0;
    for (auto i = 0; i < vehicles.size(); i++) {
        if (type == "" || (type == "car" && dynamic_cast<CarModel *>(vehicles[i])) || (type == "bus" && dynamic_cast<BusModel *>(vehicles[i])) || (type == "truck") && dynamic_cast<TruckModel *>(vehicles[i])) {
            vehicles_of_type++;
            if (filter == nullptr || filter(vehicles[i])) {
                filtered_vehicles.push_back(std::make_pair(i, vehicles[i]));
            }
        }
    }
}
