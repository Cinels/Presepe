#ifndef __CRAFTS__
#define __CRAFTS__

#include "devices/relay.hpp"

class Crafts {
private:
    Relay crafts;
public:
    Crafts();
    void on();
    void off();
};


#endif
