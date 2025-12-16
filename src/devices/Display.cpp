#include "devices/Display.hpp"

Display::Display(const int addr, const uint8_t cols, const uint8_t rows) : lcd(addr, cols, rows) { }

void Display::init() {
    Wire.begin(19,20);
    this->lcd.init();
    this->clear();
    this->setText(0, 0, "Modalità: ");
    this->setText(1, 0, "Periodo: ");
}

void Display::setText(const uint8_t row, const uint8_t col, const String text) {
    this->lcd.backlight();
    this->lcd.setCursor(row, col);
    this->lcd.print(text);
}

void Display::clear() {
    this->lcd.clear();
    this->lcd.noBacklight();
}