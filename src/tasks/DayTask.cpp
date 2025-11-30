#include "tasks/DayTask.hpp"
#include "constants.hpp"

void DayTask::tick() {
    switch (this->mode) {
    case LOOP: loopMode(); break;
    case FAST_LOOP: fastLoopMode(); break;
    case AUTOMATIC: automaticMode(); break;
    case MANUAL: manualMode(); break;
    default: loopMode(); break;
    }
}

/*void DayTask::changeMode() {
    switch (this->mode) {
    case LOOP: this->mode = FAST_LOOP; break;
    case FAST_LOOP: this->mode = AUTOMATIC; break;
    case AUTOMATIC: this->mode = MANUAL; break;
    case MANUAL: this->mode = LOOP; break;
    default: this->mode = LOOP; break;
    }
}

Mode DayTask::getMode() {
    return this->mode;
}

DayPeriod DayTask::getDayPeriod() {
    return this->dayPeriod;
}*/

void DayTask::loopMode() {
    ts++;
    if (this->dayPeriod == MORNING && ts > MORNING_TIME) this->startDayPeriod(DAY);
    else if (this->dayPeriod == DAY && ts > DAY_TIME) this->startDayPeriod(EVENING);
    else if (this->dayPeriod == EVENING && ts > EVENING_TIME) this->startDayPeriod(NIGHT);
    else if (this->dayPeriod == NIGHT && ts > NIGHT_TIME) this->startDayPeriod(LATE_NIGHT);
    else if (this->dayPeriod == LATE_NIGHT && ts > LATE_NIGHT_TIME) this->startDayPeriod(MORNING);
}

void DayTask::fastLoopMode() {
    ts++;
    if (this->dayPeriod == MORNING && ts > MORNING_TIME) this->startDayPeriod(DAY);
    else if (this->dayPeriod == DAY && ts > DAY_TIME) this->startDayPeriod(NIGHT);
    else if (this->dayPeriod == NIGHT && ts > NIGHT_TIME) this->startDayPeriod(MORNING);
}

void DayTask::automaticMode() {
    if (this->dashboard.isDark()) this->startDayPeriod(NIGHT);
    else if (this->dayPeriod == MORNING && ++ts > MORNING_TIME) this->startDayPeriod(DAY);
    else this->startDayPeriod(MORNING);
}

void DayTask::manualMode() {
    //listens from dashboard and internet
}

void DayTask::startDayPeriod(DayPeriod period) {
    ts = 0;
    this->dayPeriod = period;
    switch (period) {
    case MORNING: this->visual.startMorning(); break;
    case DAY: this->visual.startDay(); break;
    case EVENING: this->visual.startEvening(); break;
    case NIGHT: this->visual.startNight(); break;
    case LATE_NIGHT: this->visual.startLateNight(); break;
    default: this->visual.startMorning();
    }
}