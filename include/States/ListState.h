#ifndef LISTSTATE_H
#define LISTSTATE_H

#include "States/BaseState.h"
#include "Models/VehicleModel.h"
#include <functional>

class ListState : public BaseState
{
    public:
        ListState(std::vector<VehicleModel *> &vehicles, std::function<bool(VehicleModel *)> filter = nullptr);

    protected:
        void        display();
        BaseState*  handle_input();

        void        filter_vehicles();

    protected:
         std::function<bool(VehicleModel *)> filter;
         std::vector<std::pair<int, VehicleModel *>> filtered_vehicles;

};

#endif // LISTSTATE_H
