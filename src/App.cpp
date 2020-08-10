//
// Class Implementation of App
//

#include <algorithm>
#include <iostream>

#include "App.h"
#include "Utils/Config.h"

#include "Models/CarModel.h"
#include "Models/TruckModel.h"
#include "Models/BusModel.h"
#include "Models/VehicleFactory.h"

#include "States/MainState.h"
#include "States/DeleteState.h"
#include "States/AddVehicleState.h"
#include "States/EditedState.h"



void App::load_fleet() {
    std::ifstream fin(this->vehicle_filename);
    std::string line;
    VehicleFactory f;
    while(std::getline(fin, line) && !line.empty()) {
        this->fleet.push_back(f.create(line));
    }
    fin.close();
}

void App::save_fleet() {
    std::ofstream fout(this->vehicle_filename);
    for_each(this->fleet.begin(), this->fleet.end(), [&fout](VehicleModel* v) -> void {
        v->save(fout);
        fout << '\n';
    });
}

App::App(const std::string &vehicle_filename)
:vehicle_filename(vehicle_filename) {
    this->load_fleet();
    this->run();
}

void App::run() {
    Config::clear_screen();
    states.push(new MainState(fleet));
    while (!states.empty()) {
        Config::pretty_print("    Vehicle Management App        ");
        Config::pretty_print("          Author: Vlad Slivilescu ");
        BaseState* current = states.top();
        if (dynamic_cast<DeleteState *>(current)) {
            this->save_fleet();
            states.pop();
            delete states.top();
        }
        if (dynamic_cast<EditedState *>(current)) {
            this->save_fleet();
        }
        BaseState* next = current->run();
        if (dynamic_cast<AddVehicleState *>(current)) {
            this->save_fleet();
        }
        if (next == nullptr) {
            delete states.top();
            states.pop();
        }
        else {
            states.push(next);
        }
        Config::clear_screen();
    }
    Config::pretty_print("   Thank You For Using The App    ");

}
