#include "devices/Transistor.hpp"
#include <Arduino.h>
#include "constants.hpp"

#define INCREASE 1
#define DECREASE -1

Transistor::Transistor(const uint8_t pin) 
    : Switch(pin), 
      task(pin) {
    const int BUFFER_SIZE = 16;
    char taskName[BUFFER_SIZE]; 
    snprintf(taskName, BUFFER_SIZE, "fade pin %i", pin);
    this->task.start(taskName, FADING_PERIOD);
    delay(100);
}

void Transistor::fadeOn() {
    this->on = true;
    // this->switchOn();
    this->task.setDirection(INCREASE);
    // this->task.resume();
}

void Transistor::fadeOff() {
    this->on = false;
    // this->switchOff();
    this->task.setDirection(DECREASE);
    // this->task.resume();
}
