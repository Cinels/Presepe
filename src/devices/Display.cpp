#include "devices/Display.hpp"
#include "constants.hpp"

Display::Display(const int addr, const uint8_t cols, const uint8_t rows) : lcd(addr, cols, rows) { }

void Display::init() {
    this->lcd.init();
    this->clear();
    this->setText(MODE_ROW, 0, "Modalita: LOOP");
    this->setText(PERIOD_ROW, 0, "Periodo: MATTINA");
}

void Display::setText(const uint8_t row, const uint8_t col, const String text) {
    this->lcd.backlight();
    this->lcd.setCursor(col, row);
    this->lcd.print(text);
}

void Display::clear() {
    this->lcd.clear();
    this->lcd.noBacklight();
}