#include "model/Visual.hpp"
#include "constants.hpp"
#include <Arduino.h>

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

void Visual::turnOff() {
    this->crafts.switchOff();
    this->housesAndLanterns.switchOff();
    this->candlesAndLamps.switchOff();
    this->pathAndStars.switchOff();
}

void Visual::toggleCrafts() {
    if (crafts.isOn()) crafts.switchOff();
    else crafts.switchOn();
    Serial.printf("Crafts: %d\n", crafts.isOn());
}

void Visual::toggleHouseAndLanterns() {
    if (housesAndLanterns.isOn()) housesAndLanterns.switchOff();
    else housesAndLanterns.switchOn();
    Serial.printf("House: %d\n", housesAndLanterns.isOn());
}

void Visual::toggleCandlesAndLamps() {
    if (candlesAndLamps.isOn()) candlesAndLamps.switchOff();
    else candlesAndLamps.switchOn();
    Serial.printf("Candles: %d\n", candlesAndLamps.isOn());
}

void Visual::togglePathAndStars() {
    if (pathAndStars.isOn()) pathAndStars.switchOff();
    else pathAndStars.switchOn();
    Serial.printf("Stars: %d\n", pathAndStars.isOn());
}