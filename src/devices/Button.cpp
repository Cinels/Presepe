#define EI_ARDUINO_INTERRUPTED_PIN
#include "devices/Button.hpp"
#include <Arduino.h>

enum ENUM {A, B};

Button::Button(int pin, void(*func)()) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(this->pin), func, RISING);
}