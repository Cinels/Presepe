#include "controller/Visual.hpp"
#include "constants.hpp"
#include <Arduino.h>

Visual::Visual() { }

void Visual::startMorning() {
    this->candlesAndLamps.on();
    this->crafts.on();
    this->houses.on();
    this->lanterns.on();
    this->paths.on();
    this->stars.off();
}

void Visual::startDay() {
    this->candlesAndLamps.off();
    this->crafts.on();
    this->houses.off();
    this->lanterns.off();
    this->paths.on();
    this->stars.off();
}

void Visual::startEvening() {
    this->candlesAndLamps.on();
    this->crafts.off();
    this->houses.on();
    this->lanterns.on();
    this->paths.on();
    this->stars.off();
}

void Visual::startNight() {
    this->candlesAndLamps.on();
    this->crafts.off();
    this->houses.on();
    this->lanterns.on();
    this->paths.on();
    this->stars.on();
}

void Visual::startLateNight() {
    this->candlesAndLamps.off();
    this->crafts.off();
    this->houses.off();
    this->lanterns.off();
    this->paths.on();
    this->stars.on();
}

void Visual::turnOff() {
    this->candlesAndLamps.off();
    this->crafts.off();
    this->houses.off();
    this->lanterns.off();
    this->paths.off();
    this->stars.off();
}

/* void Visual::toggleCrafts() {
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
}*/