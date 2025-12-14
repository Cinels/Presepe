#ifndef __PATHS__
#define __PATHS__

#include "devices/Transistor.hpp"

class Paths {
private:
    Transistor path;
public:
    Paths();
    void on();
    void off();
};

#endif
