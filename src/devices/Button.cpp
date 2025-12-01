#define EI_ARDUINO_INTERRUPTED_PIN
#include "devices/Button.hpp"
#include <Arduino.h>

Button::Button() { }

Button::Button(const int pin, void(*func)()) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(this->pin), func, RISING);
}