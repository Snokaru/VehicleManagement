#ifndef SPECIFICSTATSTATE_H
#define SPECIFICSTATSTATE_H

#include <functional>
#include "States/BaseState.h"
#include "Models/VehicleModel.h"

class SpecificStatState : public BaseState
{
    public:
        SpecificStatState(std::vector<VehicleModel *> &vehicles, std::function<bool(VehicleModel *)> filter = nullptr, const std::string& type = "");

    protected:
        void display();
        BaseState* handle_input();

    private:
        void filter_vehicles();
        int vehicles_of_type;
        std::string type;
        std::vector<std::pair<int, VehicleModel *>> filtered_vehicles;
        std::function<bool(VehicleModel *)> filter;
};

#endif // SPECIFICSTATSTATE_H
