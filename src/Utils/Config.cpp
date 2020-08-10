#include "Utils/Config.h"
#include <iostream>
#include <stdlib.h>

void Config::pretty_print(const std::string &text) {
    std::cout << "::::::::::" << "  " << text <<  " " << "::::::::::" << "\n";
}
void Config::pretty_print_left(const std::string& text) {
    std::cout << "::::::::::" << "  " << text;
}

void Config::clear_screen() {
    system("clear");
}
