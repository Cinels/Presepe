#include "controller/Dashboard.hpp"
#include "constants.hpp"
#include <Arduino.h>

Dashboard::Dashboard()
    :   photores(PHOTO_RESISTOR_PIN),
        display(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS) { }

void Dashboard::init(TaskHandle_t taskHandler) {
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
    Serial.printf("Enviromental brightness: %d, is night: %d\n", photores.getValue(), photores.getValue() < BRIGHTNESS_THRESHOLD);
    return photores.getValue() < BRIGHTNESS_THRESHOLD;
}

void Dashboard::modeChanged(String mode) {
    this->display.setText(MODE_ROW, MODE_COL, mode);
}

void Dashboard::periodChanged(String period) {
    this->display.setText(PERIOD_ROW, PERIOD_COL, period);
}

void Dashboard::showTimer(float ticks) {
    uint8_t timer = round(ticks * (float) 20);
    if (timer != this->lastTimer) {
        this->lastTimer = timer;
        String timerString = "";
        for (uint8_t i = 0; i < LCD_COLUMNS; i++) timerString += i < timer ? char(255) : char(32);
        this->display.setText(TIMER_ROW, TIMER_COL, String(timerString));
    }
}
