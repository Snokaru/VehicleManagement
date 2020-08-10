#ifndef DETAILSTATE_H
#define DETAILSTATE_H

#include "States/BaseState.h"

class DetailState : public BaseState
{
    public:
        DetailState(std::vector<VehicleModel *> &vehicles, int selected_vehicle);

    protected:
        void               display();
        BaseState*         handle_input();

    private:
        int                selected_vehicle;
};

#endif // DETAILSTATE_H
