#include <Arduino.h>
#include "constants.hpp"
#include "model/Dashboard.hpp"
#include "model/Visual.hpp"
#include "tasks/DayTask.hpp"

// #define PHOTORES_PIN 10
// #define LUMINOSITY 2000

Dashboard dashboard;
Visual visual;
DayTask* dayTask;

/*int brightness[3] = {RGB_BRIGHTNESS, RGB_BRIGHTNESS, RGB_BRIGHTNESS};
int color = 0;
int direction = 1;*/

void setup() {
  Serial.begin(115200);
  dashboard = Dashboard();
  visual = Visual();
  dayTask = new DayTask(&visual, &dashboard);
  
  dayTask->start("day task", DAY_TASK_PERIOD);
  dashboard.init(dayTask->getTaskHandle());

  /*pinMode(PHOTORES_PIN, INPUT);
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);
  Serial.begin(115200);
  Serial.print("setup() is running on core ");
  Serial.println(xPortGetCoreID());
  delay(1000);*/
}

void loop() {
  /*Serial.print("loop() is running on core ");
  Serial.println(xPortGetCoreID());
  int value = analogRead(PHOTORES_PIN);
  Serial.println(value);


#ifdef RGB_BUILTIN
  digitalWrite(RGB_BUILTIN, value < LUMINOSITY ? HIGH : LOW);
  /*neopixelWrite(RGB_BUILTIN, brightness[0], brightness[1], brightness[2]);

  if(direction == 1 ? brightness[color] >= RGB_BRIGHTNESS : brightness[color] <= 0){
    direction *= -1;
    color = (color + 2) % 3;
  }
  brightness[color] += direction;
  delay(100);*/
//#endif
  delay(1000);
}
