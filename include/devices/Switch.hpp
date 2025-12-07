#ifndef __SWITCH__
#define __SWITCH__

class Switch {
private:
    uint8_t pin;
protected:
    bool on;
public:
    Switch(const uint8_t pin);
    virtual void switchOn();
    virtual void switchOff();
    virtual bool isOn();
};

#endif