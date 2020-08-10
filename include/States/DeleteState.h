#ifndef DELETESTATE_H
#define DELETESTATE_H

#include "BaseState.h"
#include "Models/VehicleModel.h"

class DeleteState : public BaseState
{
    public:
        DeleteState(std::vector<VehicleModel *> &vehicles, int deleted_vehicle);

    protected:
       void display();
       BaseState* handle_input();

    protected:
        int deleted_vehicle;
};

#endif // DELETESTATE_H
