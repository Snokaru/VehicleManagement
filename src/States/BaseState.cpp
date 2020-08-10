//
// Created by zigza on 6/6/2020.
//

#include "States/BaseState.h"

BaseState::BaseState(std::vector<VehicleModel *> &vehicles)
:vehicles(vehicles){
}

BaseState* BaseState::run() {
    this->display();
    return this->handle_input();
}
