#ifndef __SWITCH__
#define __SWITCH__

class Switch {
private:
    int pin;
    bool on;
public:
    Switch(int pin);
    virtual void switchOn();
    virtual void switchOff();
    virtual bool isOn();
};

#endif