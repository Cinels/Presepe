#include "tasks/Task.hpp"

Task::Task(const char* name, int period) {
    this->period = period;
    xTaskCreate(entry, name, 2048, this, 1, this->taskHandler);
}

int Task::getPeriod() {
    return this->period;
}

TaskHandle_t* Task::getTaskHandle() {
    return this->taskHandler;
}

void Task::entry(void *pvParameters) {
    Task* instance = static_cast<Task*>(pvParameters);
    instance->loop();
    vTaskDelete(NULL);
}

void Task::loop() {
    for (;;) {
        this->tick();
        vTaskDelay(this->period);
    }
}