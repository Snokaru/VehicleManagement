//
// "Base State Abstract Interface Class"
//

#ifndef FLEETVEHICLES_BASESTATE_H
#define FLEETVEHICLES_BASESTATE_H

#include <vector>
#include "Models/VehicleModel.h"


class BaseState {

public:
    BaseState(std::vector<VehicleModel*> &vehicles);

    BaseState*                 run();

protected:
    virtual void               display() = 0;
    virtual BaseState*         handle_input() = 0;

protected:
    std::vector<VehicleModel*> &vehicles;
};


#endif //FLEETVEHICLES_BASESTATE_H
