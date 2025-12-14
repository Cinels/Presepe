#include "model/Houses.hpp"
#include "constants.hpp"

Houses::Houses() 
    : bigLights(HOUSE_BIG_LIGHTS_PIN),
      mediumLights(HOUSE_MEDIUM_LIGHTS_PIN),
      smallLights(HOUSE_SMALL_LIGHTS_PIN) { }

void Houses::on() {
    this->bigLights.switchOn();
    this->mediumLights.fadeOn();
    this->smallLights.fadeOn();
}

void Houses::off() {
    this->bigLights.switchOff();
    this->mediumLights.fadeOff();
    this->smallLights.fadeOff();
}
