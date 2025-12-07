#include "devices/Photoresistor.hpp"
#include <Arduino.h>

Photoresistor::Photoresistor(const uint8_t pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

int Photoresistor::getValue() {
    return analogRead(this->pin);
}