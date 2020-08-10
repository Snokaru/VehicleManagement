#ifndef EDITSTATE_H
#define EDITSTATE_H

#include "Models/VehicleModel.h"
#include "States/BaseState.h"
#include <vector>

class EditState : public BaseState {

public:
    EditState(std::vector<VehicleModel*> &vehicles, int selected_vehicle);


protected:
    void               display();
    BaseState*         handle_input();

protected:
    int selected_vehicle;
};

#endif // EDITSTATE_H
