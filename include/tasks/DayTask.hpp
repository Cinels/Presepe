#ifndef __DAY_TASK__
#define __DAY_TASK__

#include "Task.hpp"
#include "model/Visual.hpp"
#include "model/Dashboard.hpp"

typedef enum Mode {LOOP, FAST_LOOP, AUTOMATIC, MANUAL} Mode;
typedef enum DayPeriod {MORNING, DAY, EVENING, NIGHT, LATE_NIGHT, OFF} DayPeriod;

class DayTask : public Task {
private:
    Mode mode = LOOP;
    DayPeriod dayPeriod = MORNING;
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
public:
    DayTask(Visual* visual, Dashboard* dashboard, const char* name, const int period);
    void tick();
};

#endif
