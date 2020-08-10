#ifndef EDITEDSTATE_H
#define EDITEDSTATE_H

#include "States/BaseState.h"
#include <vector>

class EditedState : public BaseState
{
    public:
        EditedState(std::vector<VehicleModel *> &vehicles);

    protected:
        void display();
        BaseState* handle_input();

    private:
};

#endif // EDITEDSTATE_H
