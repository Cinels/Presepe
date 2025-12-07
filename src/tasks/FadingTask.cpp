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

void FadingTask::setDirection(const uint8_t direction) {
    this->direction = direction;
    Serial.print("task state: ");
    Serial.println(eTaskGetState(this->getTaskHandle()));
    // xTaskNotifyGive(this->getTaskHandle());
}

/*void FadingTask::resume() {
    // Serial.println(eTaskGetState(this->getTaskHandle()));
    // vTaskResume(this->getTaskHandle());
}*/

void FadingTask::tick() {
    this->value += direction;
    
    if (value > OFF_VALUE && value < ON_VALUE) {
        Serial.print(pin);
        Serial.print(" value: ");
        Serial.println(value);
    }
    if (direction && this->value < this->onValue && this->value >= this->offValue) {
        analogWrite(this->pin, this->value);
    } else {
        direction = 0;
        // vTaskSuspend(this->getTaskHandle());
        // ulTaskNotifyTake(0xFFFFFFFF, portMAX_DELAY);
        // ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        // Serial.println(direction);
    }
}
