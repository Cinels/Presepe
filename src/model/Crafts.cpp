#include "model/Crafts.hpp"
#include "constants.hpp"

Crafts::Crafts() : crafts(CRAFTS_PIN) { }

void Crafts::on() {
    this->crafts.switchOn();
}

void Crafts::off() {
    this->crafts.switchOff();
}
