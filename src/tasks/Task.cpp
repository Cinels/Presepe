#include "tasks/Task.hpp"
#include <Arduino.h>

Task::Task() { }

void Task::start(const char* name, const int period, const uint16_t stackSize, UBaseType_t priority) {
    this->period = period;
    xTaskCreate(entry, name, stackSize, this, priority, &this->taskHandler);
    Serial.printf("Task %s created with period: %i\n", name, period);
}

int Task::getPeriod() {
    return this->period;
}

TaskHandle_t Task::getTaskHandle() {
    return this->taskHandler;
}

void Task::entry(void *pvParameters) {
    Task* instance = static_cast<Task*>(pvParameters);
    instance->loop();
}

void Task::loop() {
    TickType_t xLastWakeTime = xTaskGetTickCount();     
    for (;;) {
        this->tick(); 
        // vTaskDelayUntil( &xLastWakeTime, this->period / portTICK_PERIOD_MS );
        vTaskDelay(this->period);
    }
    vTaskDelete(NULL);
}