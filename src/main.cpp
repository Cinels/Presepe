#include <Arduino.h>
#include "constants.hpp"
#include "controller/Dashboard.hpp"
#include "controller/Visual.hpp"
#include "tasks/DayTask.hpp"

Dashboard dashboard;
Visual visual;
DayTask* dayTask;

void setup() {
  Serial.begin(115200);
  dashboard = Dashboard();
  visual = Visual();
  dayTask = new DayTask(&visual, &dashboard);
  
  dayTask->start("day task", DAY_TASK_PERIOD, 4096);
  dashboard.init(dayTask->getTaskHandle());
}

void loop() {
  delay(1000);
}
