#include "model/CandlesAndLamps.hpp"
#include "constants.hpp"

CandlesAndLamps::CandlesAndLamps() : candleAndLamp(CANDLES_AND_LAMPS_PIN) { }

void CandlesAndLamps::on() {
    this->candleAndLamp.fadeOn();
}

void CandlesAndLamps::off() {
    this->candleAndLamp.fadeOff();
}
