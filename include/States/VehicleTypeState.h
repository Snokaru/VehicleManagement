#ifndef VEHICLETYPESTATE_H
#define VEHICLETYPESTATE_H

#include "States/BaseState.h"
#include "Models/VehicleModel.h"
#include <vector>

class VehicleTypeState : public BaseState
{
    public:
        VehicleTypeState(std::vector<VehicleModel *> &vehicles);

    protected:
        void        display();
        BaseState*  handle_input();
};

#endif // VEHICLETYPESTATE_H
