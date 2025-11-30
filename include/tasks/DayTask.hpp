#ifndef __DAY_TASK__
#define __DAY_TASK__

#include "Task.hpp"
#include "model/Visual.hpp"
#include "model/Dashboard.hpp"

typedef enum Mode {LOOP, FAST_LOOP, AUTOMATIC, MANUAL} Mode;
typedef enum DayPeriod {MORNING, DAY, EVENING, NIGHT, LATE_NIGHT} DayPeriod;

class DayTask : Task {
private:
    Mode mode = LOOP;
    DayPeriod dayPeriod = MORNING;
    Visual* visual;
    Dashboard* dashboard;
    long ts;
    void changeMode();
    void loopMode();
    void fastLoopMode();
    void automaticMode();
    void manualMode();
    void startDayPeriod(const DayPeriod period);
    void checkSkip();
public:
    DayTask(Visual* visual, Dashboard* dashboard, const char* name, const int period);
    void tick();
    // Mode getMode();
    // DayPeriod getDayPeriod();
};

#endif
