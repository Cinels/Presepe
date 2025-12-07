#include "tasks/FadingTask.hpp"
#include <Arduino.h>

FadingTask::FadingTask(const uint8_t pin) : Task() {
    this->pin = pin;
    this->value = 0;
    this->direction = 0;
    this->setLimits();
}

void FadingTask::setLimits(const int off, const int on) {
    this->offValue = off < OFF_VALUE ? OFF_VALUE : off;
    this->onValue = on > ON_VALUE ? ON_VALUE : on;
}

void FadingTask::tick() {
    this->value += this->direction;
    if (this->direction && this->value <= this->onValue && this->value >= this->offValue) {
        analogWrite(this->pin, this->value);
    } else {
        this->direction = 0;
        if (this->value > this->onValue) this->value = this->onValue;
        if (this->value < this->offValue) this->value = this->offValue;
        this->direction = (int8_t) ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }
}
