#ifndef __FADING_TASK__
#define __FADING_TASK__

#include "Task.hpp"

#define OFF_VALUE 0
#define ON_VALUE 256

class FadingTask : public Task {
private:
    uint8_t pin;
    uint8_t direction;
    int value;
    int offValue;
    int onValue;
    void tick();
public:
    FadingTask(const uint8_t pin);
    void setDirection(const uint8_t direction);
    // void resume();
    void setLimits(const int off = OFF_VALUE, const int on = ON_VALUE);
};

#endif