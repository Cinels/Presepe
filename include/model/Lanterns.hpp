#ifndef __LANTERNS__
#define __LANTERNS__

#include "devices/Transistor.hpp"

class Lanterns {
private:
    Transistor blackLanterns;
    Transistor brownLanterns1;
    Transistor brownLanterns2;
public:
    Lanterns();
    void on();
    void off();
};

#endif
