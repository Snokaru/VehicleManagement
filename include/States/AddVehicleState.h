#ifndef ADDVEHICLESTATE_H
#define ADDVEHICLESTATE_H

#include "States/BaseState.h"
#include "Models/VehicleModel.h"
#include <vector>


class AddVehicleState : public BaseState
{
    public:
        AddVehicleState(std::vector<VehicleModel *> &vehicles);


    protected:
        void display();
        BaseState* handle_input();

    private:
};

#endif // ADDVEHICLESTATE_H
