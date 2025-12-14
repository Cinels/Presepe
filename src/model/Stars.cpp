#include "model/Stars.hpp"
#include "constants.hpp"

Stars::Stars() : stars(STARS_PIN) { }

void Stars::on() {
    this->stars.switchOn();
}

void Stars::off() {
    this->stars.switchOff();
}
