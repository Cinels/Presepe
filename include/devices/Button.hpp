#ifndef __BUTTON__
#define __BUTTON__

/// @brief Class to use buttons by interrupts.
class Button {
private:
    int pin;
public:
    /// @brief Button constructor, it creates a button and sets the pin in INPUT mode.
    /// @param pin the input pin for the button.
    Button();
    Button(int pin, void(*func)());
    static void foo();
};

#endif
