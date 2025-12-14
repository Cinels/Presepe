#ifndef __CANDLES_AND_LAMPS__
#define __CANDLES_AND_LAMPS__

#include "devices/Transistor.hpp"

class CandlesAndLamps {
private:
    Transistor candleAndLamp;
public:
    CandlesAndLamps();
    void on();
    void off();
};

#endif
