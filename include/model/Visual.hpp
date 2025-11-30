#ifndef __VISUAL__
#define __VISUAL__

#include "devices/Relay.hpp"

class Visual {
private:
    Relay crafts;
    Relay housesAndLanterns;
    Relay candlesAndLamps;
    Relay pathAndStars;
public:
    Visual();
    void startMorning();
    void startDay();
    void startEvening();
    void startNight();
    void startLateNight();
    void toggleCrafts();
    void toggleHouseAndLanterns();
    void toggleCandlesAndLamps();
    void togglePathAndStars();
};

#endif
