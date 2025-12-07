#ifndef __TRANSISTOR__
#define __TRANSISTOR__

#include "Switch.hpp"
#include <cstdint>
#include "tasks/FadingTask.hpp"

class Transistor : public Switch {
private:
    FadingTask task;
public:
    // using Switch::Switch;
    Transistor(const uint8_t pin);
    void fadeOn();
    void fadeOff();
};

#endif
