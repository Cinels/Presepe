#ifndef __HOUSES__
#define __HOUSES__

#include "devices/Relay.hpp"
#include "devices/Transistor.hpp"

class Houses {
private:
    Relay bigLights;
    Transistor mediumLights;
    Transistor smallLights;
public:
    Houses();
    void on();
    void off();
};

#endif
