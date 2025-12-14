#include "model/Lanterns.hpp"
#include "constants.hpp"

Lanterns::Lanterns()
    : blackLanterns(BLACK_LANTERNS_PIN),
      brownLanterns1(BROWN_LANTERNS_1_PIN),
      brownLanterns2(BROWN_LANTERNS_2_PIN) { }

void Lanterns::on() {
    this->blackLanterns.fadeOn();
    this->brownLanterns1.fadeOn();
    this->brownLanterns2.fadeOn();
}

void Lanterns::off() {
    this->blackLanterns.fadeOff();
    this->brownLanterns1.fadeOff();
    this->brownLanterns2.fadeOff();
}
