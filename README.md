# Vehicle Management App (Terminal Based)

## Description
Terminal App To Manage The Vehicle Fleet Of A Company (Can Manage Trucks, Buses and Vehicles).
The Vehicle Fleet Can Be Modified Respecting The data.txt format specified in Models/VehicleModel.h.
<p float="left">
  <img src="https://i.imgur.com/rPp2LGA.png" width="49%" />
  <img src="https://i.imgur.com/jkUh3RG.png" width="49%" /> 
</p>
<p float="left">
  <img src="https://i.imgur.com/GFbgM7B.png" width="49%" />
  <img src="https://i.imgur.com/Ygv1ybS.png" width="49%" /> 
</p>

## Installation
The App Requires CMake In Order To Be Built
```
$ git clone https://github.com/Snokaru/VehicleManagement.git
$ cd VehicleManagement
$ mkdir build
$ cd build
$ cmake ..
$ make 
$ ./VehicleManagement ../data.txt # Or Where You decide to put the data file
```
App works with both Linux and Windows, but it won't clear the screen on Windows (Config::clear_screen can pe modified in order for it to work on Windows correctly).

## What I Learned
- OOP Principles
- STL Containers and Algorithms
- Automata Theory Application (The Interface is a stack-based FSM)
