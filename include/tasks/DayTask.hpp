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
    Visual visual = Visual();
    Dashboard dashboard = Dashboard();
    long ts;
    void loopMode();
    void fastLoopMode();
    void automaticMode();
    void manualMode();
    void startDayPeriod(DayPeriod period);
public:
    void tick();
    // void changeMode();
    // Mode getMode();
    // DayPeriod getDayPeriod();
};

#endif
