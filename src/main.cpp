#include <Arduino.h>
#include "constants.hpp"
#include "controller/Dashboard.hpp"
#include "controller/Visual.hpp"
#include "tasks/DayTask.hpp"

Dashboard dashboard = Dashboard();
Visual visual = Visual();
DayTask* dayTask;

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  dayTask = new DayTask(&visual, &dashboard);
  dayTask->start("day task", DAY_TASK_PERIOD);
  dashboard.init(dayTask->getTaskHandle());
}

void loop() {
  delay(1000);
}
