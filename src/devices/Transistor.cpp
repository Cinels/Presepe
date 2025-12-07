#include "devices/Transistor.hpp"
#include <Arduino.h>
#include "constants.hpp"

#define INCREASE 1
#define DECREASE -1

Transistor::Transistor(const uint8_t pin) : Switch(pin) {
    task = new FadingTask(pin);
    const int BUFFER_SIZE = 16;
    char taskName[BUFFER_SIZE]; 
    snprintf(taskName, BUFFER_SIZE, "fade pin %i", pin);
    this->task->start(taskName, FADING_PERIOD);
}

void Transistor::fadeOn() {
    this->on = true;
    xTaskNotify(this->task->getTaskHandle(), INCREASE, eSetValueWithOverwrite);
}

void Transistor::fadeOff() {
    this->on = false;
    xTaskNotify(this->task->getTaskHandle(), DECREASE, eSetValueWithOverwrite);
}
