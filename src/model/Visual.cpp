#include "model/Visual.hpp"
#include "constants.hpp"

Visual::Visual()
    : crafts(CRAFTS_RELAY_PIN),
      housesAndLanterns(HOUSE_AND_LANTERNS_RELAY_PIN),
      candlesAndLamps(CANDLES_AND_LAMPS_RELAY_PIN),
      pathAndStars(PATH_AND_STARS_RELAY_PIN) { }

void Visual::startMorning() {
    this->crafts.switchOff();
    this->housesAndLanterns.switchOn();
    this->candlesAndLamps.switchOn();
    this->pathAndStars.switchOff();
}

void Visual::startDay() {
    this->crafts.switchOn();
    this->housesAndLanterns.switchOff();
    this->candlesAndLamps.switchOff();
    this->pathAndStars.switchOff();
}

void Visual::startEvening() {
    this->crafts.switchOff();
    this->housesAndLanterns.switchOn();
    this->candlesAndLamps.switchOn();
    this->pathAndStars.switchOff();
}

void Visual::startNight() {
    this->crafts.switchOff();
    this->housesAndLanterns.switchOn();
    this->candlesAndLamps.switchOn();
    this->pathAndStars.switchOn();
}

void Visual::startLateNight() {
    this->crafts.switchOff();
    this->housesAndLanterns.switchOff();
    this->candlesAndLamps.switchOff();
    this->pathAndStars.switchOn();
}

void Visual::toggleCrafts() {
    if (crafts.isOn()) crafts.switchOff();
    else crafts.switchOn();
}

void Visual::toggleHouseAndLanterns() {
    if (housesAndLanterns.isOn()) housesAndLanterns.switchOff();
    else housesAndLanterns.switchOn();
}

void Visual::toggleCandlesAndLamps() {
    if (candlesAndLamps.isOn()) candlesAndLamps.switchOff();
    else candlesAndLamps.switchOn();
}

void Visual::togglePathAndStars() {
    if (pathAndStars.isOn()) pathAndStars.switchOff();
    else pathAndStars.switchOn();
}