#include "devices/Switch.hpp"
#include "Arduino.h"

Switch::Switch(int pin) {
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
    this->switchOff();
}

void Switch::switchOn() {
    digitalWrite(this->pin, HIGH);
    this->on = true;
}

void Switch::switchOff() {
    digitalWrite(this->pin, LOW);
    this->on = false;
}

bool Switch::isOn() {
    return this->on;
}