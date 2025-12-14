#ifndef __DAY_TASK__
#define __DAY_TASK__

#include "Task.hpp"
#include "controller/Visual.hpp"
#include "controller/Dashboard.hpp"

typedef enum Mode {LOOP, FAST_LOOP, AUTOMATIC, MANUAL} Mode;
typedef enum DayPeriod {MORNING, DAY, EVENING, NIGHT, LATE_NIGHT, OFF} DayPeriod;

class DayTask : public Task {
private:
    Mode mode;
    DayPeriod dayPeriod;
    Visual* visual;
    Dashboard* dashboard;
    long ts;
    void changeMode();
    void loopMode();
    void automaticMode();
    void manualMode();
    void changeDayPeriod();
    void startDayPeriod(const DayPeriod period);
    void checkSkip();
    uint32_t readNotification(uint32_t clearOnExit, int timeout);
    void tick();
public:
    DayTask(Visual* visual, Dashboard* dashboard);
};

#endif
