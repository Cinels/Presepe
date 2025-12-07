#ifndef __PHOTO_RESISTOR__
#define __PHOTO_RESISTOR__

#include <cstdint>

class Photoresistor {
private:
    uint8_t pin;
public:
    Photoresistor(const uint8_t pin);
    int getValue();
};

#endif