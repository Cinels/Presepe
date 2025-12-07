#ifndef __BUTTON__
#define __BUTTON__

#include <cstdint>

/// @brief Class to use buttons by interrupts.
class Button {
private:
    uint8_t pin;
public:
    /// @brief Button constructor, it creates a button and sets the pin in INPUT mode.
    /// @param pin the input pin for the button.
    Button();
    Button(const uint8_t pin, void(*func)());
};

#endif
