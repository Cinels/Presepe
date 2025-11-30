#include "model/Dashboard.hpp"
#include "constants.hpp"

Dashboard::Dashboard(TaskHandle_t* taskHandler) : photores(PHOTO_RESISTOR_PIN) {
    dayTaskHandler = taskHandler;
    this->modeButton = Button(MODE_BUTTON_PIN, []() -> void {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xTaskNotifyFromISR(dayTaskHandler, MODE_BUTTON_NOTIFY, eSetValueWithOverwrite, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    });
    this->periodButton = Button(PERIOD_BUTTON_PIN, []() -> void {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xTaskNotifyFromISR(dayTaskHandler, PERIOD_BUTTON_NOTIFY, eSetValueWithOverwrite, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    });
}

bool Dashboard::isDark() {
    return photores.getValue() < BRIGHTNESS_THRESHOLD;
}