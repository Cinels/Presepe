#include "model/Dashboard.hpp"
#include "constants.hpp"

Dashboard::Dashboard(TaskHandle_t* taskHandler)
    :   photores(PHOTO_RESISTOR_PIN),
        display(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS) {
    dayTaskHandler = taskHandler;
    this->modeButton = Button(MODE_BUTTON_PIN, []() -> void {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xTaskNotifyFromISR(dayTaskHandler, MODE_BUTTON_NOTIFY, eSetBits, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    });
    this->periodButton = Button(PERIOD_BUTTON_PIN, []() -> void {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xTaskNotifyFromISR(dayTaskHandler, PERIOD_BUTTON_NOTIFY, eSetBits, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    });
    this->display.init();
}

bool Dashboard::isDark() {
    return photores.getValue() < BRIGHTNESS_THRESHOLD;
}