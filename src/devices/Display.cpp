#include "devices/Display.hpp"

Display::Display(const int addr, const int cols, const int rows) {
    this->lcd = new LiquidCrystal_I2C(addr, cols, rows);
}

void Display::init() {
    this->lcd->init();
    this->clear();
}

void Display::setText(const int row, const int col, const String text) {
    this->lcd->backlight();
    this->lcd->setCursor(row, col);
    this->lcd->print(text);
}

void Display::clear() {
    this->lcd->clear();
    this->lcd->noBacklight();
}