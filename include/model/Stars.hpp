#ifndef __STARS__
#define __STARS__

#include "devices/Relay.hpp"

class Stars {
private:
    Relay stars;
public:
    Stars();
    void on();
    void off();
};

#endif
