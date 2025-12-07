#ifndef __VISUAL__
#define __VISUAL__

#include "devices/Relay.hpp"
#include "devices/Transistor.hpp"

class Visual {
private:
    Relay crafts;
    Transistor housesAndLanterns;
    Transistor candlesAndLamps;
    Transistor pathAndStars;
public:
    Visual();
    void startMorning();
    void startDay();
    void startEvening();
    void startNight();
    void startLateNight();
    void turnOff();
    void toggleCrafts();
    void toggleHouseAndLanterns();
    void toggleCandlesAndLamps();
    void togglePathAndStars();
};

#endif
