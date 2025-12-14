#ifndef __VISUAL__
#define __VISUAL__

#include "model/CandlesAndLamps.hpp"
#include "model/Crafts.hpp"
#include "model/Houses.hpp"
#include "model/Lanterns.hpp"
#include "model/Paths.hpp"
#include "model/Stars.hpp"

class Visual {
private:
    CandlesAndLamps candlesAndLamps;
    Crafts crafts;
    Houses houses;
    Lanterns lanterns;
    Paths paths;
    Stars stars;
public:
    Visual();
    void startMorning();
    void startDay();
    void startEvening();
    void startNight();
    void startLateNight();
    void turnOff();
    // void toggleCrafts();
    // void toggleHouseAndLanterns();
    // void toggleCandlesAndLamps();
    // void togglePathAndStars();
};

#endif
