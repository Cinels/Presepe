#ifndef __PHOTO_RESISTOR__
#define __PHOTO_RESISTOR__

class Photoresistor {
private:
    int pin;
public:
    Photoresistor(const int pin);
    int getValue();
};

#endif