#include "model/Paths.hpp"
#include "constants.hpp"

Paths::Paths() : path(PATH_PIN) { }

void Paths::on() {
    this->path.fadeOn();
}

void Paths::off() {
    this->path.fadeOff();
}
