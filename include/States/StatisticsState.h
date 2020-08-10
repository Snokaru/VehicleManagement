#ifndef STATISTICSSTATE_H
#define STATISTICSSTATE_H

#include "States/BaseState.h"
#include <string>
#include <vector>

class StatisticsState : public BaseState
{
    public:
        StatisticsState(std::vector<VehicleModel *> &vehicles, const std::string& type = "");

    protected:
        void            display();
        BaseState*      handle_input();

    private:
        std::string type;
};

#endif // STATISTICSSTATE_H
