//
// Created by zigza on 6/6/2020.
//

#ifndef FLEETVEHICLES_MAINSTATE_H
#define FLEETVEHICLES_MAINSTATE_H

#include "States/BaseState.h"

class MainState : public BaseState {

public:
    MainState(std::vector<VehicleModel *> &vehicles);

protected:
    void        display();
    BaseState*  handle_input();

};


#endif //FLEETVEHICLES_MAINSTATE_H
