#include "tasks/DayTask.hpp"
#include "constants.hpp"
#include <Arduino.h>

DayTask::DayTask(Visual* visual, Dashboard* dashboard) : Task() {
    this->visual = visual;
    this->dashboard = dashboard;
    this->mode = LOOP;
    startDayPeriod(MORNING);
    Serial.printf("Mode: %i\n", this->mode);
    Serial.printf("Period: %i\n", this->dayPeriod);
}

void DayTask::tick() {
    this->checkSkip();
    switch (this->mode) {
    case LOOP: loopMode(); break;
    case FAST_LOOP: loopMode(); break;
    case AUTOMATIC: automaticMode(); break;
    case MANUAL: manualMode(); break;
    default: loopMode(); break;
    }
}

void DayTask::changeMode() {
    String modeString = "";
    switch (this->mode) {
    case LOOP: this->mode = FAST_LOOP; modeString = "FAST LOOP "; break;
    case FAST_LOOP: this->mode = AUTOMATIC; modeString = "AUTO      "; break;
    case AUTOMATIC: this->mode = MANUAL; modeString = "MANUALE   "; break;
    case MANUAL: this->mode = LOOP; modeString = "LOOP      "; break;
    default: this->mode = LOOP; modeString = "LOOP      "; break;
    }
    this->dashboard->modeChanged(modeString);
    Serial.printf("Mode: %i %s\n", this->mode, modeString);
}

void DayTask::loopMode() {
    this->ts++;
    this->changeDayPeriod();
}

void DayTask::automaticMode() {
    if (this->dashboard->isDark()) this->startDayPeriod(NIGHT);
    else if (this->dayPeriod != MORNING && this->dayPeriod != DAY) this->startDayPeriod(MORNING);
    else if (this->dayPeriod == MORNING && ++this->ts > MORNING_TIME) this->startDayPeriod(DAY);
}

void DayTask::manualMode() {
    this->changeDayPeriod();

    uint32_t notify = this->readNotification(0x0000FFFC, 10);
    if (notify & MODE_LOOP_NOTIFY) this->mode = LOOP;
    if (notify & MODE_FAST_LOOP_NOTIFY) this->mode = FAST_LOOP;
    if (notify & MODE_AUTOMATIC_NOTIFY) this->mode = AUTOMATIC;
    if (notify & MODE_MANUAL_NOTIFY) this->mode = MANUAL;
    if (notify & PERIOD_MORNING_NOTIFY) this->startDayPeriod(MORNING);
    if (notify & PERIOD_DAY_NOTIFY) this->startDayPeriod(DAY);
    if (notify & PERIOD_EVENING_NOTIFY) this->startDayPeriod(EVENING);
    if (notify & PERIOD_NIGHT_NOTIFY) this->startDayPeriod(NIGHT);
    if (notify & PERIOD_LATE_NIGHT_NOTIFY) this->startDayPeriod(LATE_NIGHT);
    if (notify & PERIOD_OFF_NOTIFY) this->startDayPeriod(OFF);
    // if (notify & TOGGLE_CRAFTS_NOTIFY) this->visual->toggleCrafts();
    // if (notify & TOGGLE_HOUSES_AND_LANTERNS_NOTIFY) this->visual->toggleHouseAndLanterns();
    // if (notify & TOGGLE_CANDLES_AND_LAMPS_NOTIFY) this->visual->toggleCandlesAndLamps();
    // if (notify & TOGGLE_PATH_AND_STARS_NOTIFY) this->visual->togglePathAndStars();
}

void DayTask::changeDayPeriod() {
    if (this->dayPeriod == MORNING && this->ts > MORNING_TIME) this->startDayPeriod(DAY);
    else if (this->dayPeriod == DAY && this->ts > DAY_TIME) this->startDayPeriod(this->mode == FAST_LOOP ? NIGHT : EVENING);
    else if (this->dayPeriod == EVENING && this->ts > EVENING_TIME) this->startDayPeriod(NIGHT);
    else if (this->dayPeriod == NIGHT && this->ts > NIGHT_TIME) this->startDayPeriod(this->mode == FAST_LOOP ? MORNING : LATE_NIGHT);
    else if (this->dayPeriod == LATE_NIGHT && this->ts > LATE_NIGHT_TIME) this->startDayPeriod(this->mode == MANUAL ? OFF : MORNING);
    else if (this->dayPeriod == OFF && this->ts > OFF_TIME) this->startDayPeriod(MORNING);
    int time = 1;
    switch (this->dayPeriod) {
    case MORNING: time = MORNING_TIME; break;
    case DAY: time = DAY_TIME; break;
    case EVENING: time = EVENING_TIME; break;
    case NIGHT: time = NIGHT_TIME; break;
    case LATE_NIGHT: time = LATE_NIGHT_TIME; break;    
    default: time = SKIP_TIME_PERIOD; break;
    }
    this->dashboard->showTimer((float) this->ts / (float) time);
}

void DayTask::startDayPeriod(const DayPeriod period) {
    this->ts = 0;
    this->dayPeriod = period;
    String periodString = "";
    switch (period) {
    case MORNING: this->visual->startMorning(); periodString = "MATTINA    "; break;
    case DAY: this->visual->startDay(); periodString = "GIORNO     "; break;
    case EVENING: this->visual->startEvening(); periodString = "SERA       "; break;
    case NIGHT: this->visual->startNight(); periodString = "NOTTE      "; break;
    case LATE_NIGHT: this->visual->startLateNight(); periodString = "NOTTE FONDA"; break;
    case OFF: this->visual->turnOff(); periodString = "SPENTO     "; break;
    default: this->visual->startMorning(); periodString = "MATTINA    "; break;
    }
    this->dashboard->periodChanged(periodString);
    Serial.printf("Period: %i %s\n", this->dayPeriod, periodString);
}

void DayTask::checkSkip() {
    uint32_t notify = this->readNotification(MODE_BUTTON_NOTIFY | PERIOD_BUTTON_NOTIFY, 0);
    if (notify & MODE_BUTTON_NOTIFY) this->changeMode();
    if (notify & PERIOD_BUTTON_NOTIFY) this->ts = SKIP_TIME_PERIOD;
}

uint32_t DayTask::readNotification(uint32_t clearOnExit, int timeout) {
    uint32_t ulReceivedValue = 0;
    BaseType_t xResult = xTaskNotifyWait(0, clearOnExit, &ulReceivedValue, timeout);
    if(ulReceivedValue) Serial.printf("Notifications: %#08X\n", ulReceivedValue);
    return ulReceivedValue;
}
