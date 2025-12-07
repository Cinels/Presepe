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
    this->housesAndLanterns.fadeOn();
    this->candlesAndLamps.fadeOn();
    this->pathAndStars.fadeOff();
}

void Visual::startDay() {
    this->crafts.switchOn();
    this->housesAndLanterns.fadeOff();
    this->candlesAndLamps.fadeOff();
    this->pathAndStars.fadeOff();
}

void Visual::startEvening() {
    this->crafts.switchOff();
    this->housesAndLanterns.fadeOn();
    this->candlesAndLamps.fadeOn();
    this->pathAndStars.fadeOff();
}

void Visual::startNight() {
    this->crafts.switchOff();
    this->housesAndLanterns.fadeOn();
    this->candlesAndLamps.fadeOn();
    this->pathAndStars.fadeOn();
}

void Visual::startLateNight() {
    this->crafts.switchOff();
    this->housesAndLanterns.fadeOff();
    this->candlesAndLamps.fadeOff();
    this->pathAndStars.fadeOn();
}

void Visual::turnOff() {
    this->crafts.switchOff();
    this->housesAndLanterns.fadeOff();
    this->candlesAndLamps.fadeOff();
    this->pathAndStars.fadeOff();
}

void Visual::toggleCrafts() {
    if (crafts.isOn()) crafts.switchOff();
    else crafts.switchOn();
    Serial.printf("Crafts: %d\n", crafts.isOn());
}

void Visual::toggleHouseAndLanterns() {
    if (housesAndLanterns.isOn()) housesAndLanterns.fadeOff();
    else housesAndLanterns.fadeOn();
    Serial.printf("House: %d\n", housesAndLanterns.isOn());
}

void Visual::toggleCandlesAndLamps() {
    if (candlesAndLamps.isOn()) candlesAndLamps.fadeOff();
    else candlesAndLamps.fadeOn();
    Serial.printf("Candles: %d\n", candlesAndLamps.isOn());
}

void Visual::togglePathAndStars() {
    if (pathAndStars.isOn()) pathAndStars.fadeOff();
    else pathAndStars.fadeOn();
    Serial.printf("Stars: %d\n", pathAndStars.isOn());
}