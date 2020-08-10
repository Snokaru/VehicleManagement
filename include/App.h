//
// Class That Represents App
//

#ifndef FLEETVEHICLES_APP_H
#define FLEETVEHICLES_APP_H

#include <fstream>
#include <vector>
#include <stack>
#include "Models/VehicleModel.h"
#include "States/BaseState.h"


class App {
public:
    App(const std::string &vehicle_filename);

private:

    void                        load_fleet();
    void                        save_fleet();
    void                        run();

private:
    std::vector<VehicleModel*>  fleet;
    std::stack<BaseState* >     states;
    std::string                 vehicle_filename;
};


#endif //FLEETVEHICLES_APP_H
