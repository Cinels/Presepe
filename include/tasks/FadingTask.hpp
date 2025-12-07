#ifndef __FADING_TASK__
#define __FADING_TASK__

#include "Task.hpp"

#define OFF_VALUE 0
#define ON_VALUE 255

class FadingTask : public Task {
private:
    uint8_t pin;
    int8_t direction;
    int value;
    int offValue;
    int onValue;
    void tick();
public:
    FadingTask(const uint8_t pin);
    void setLimits(const int off = OFF_VALUE, const int on = ON_VALUE);
};

#endif