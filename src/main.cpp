#include <Arduino.h>

int brightness[3] = {RGB_BRIGHTNESS, RGB_BRIGHTNESS, RGB_BRIGHTNESS};
int color = 0;
int direction = 1;

void setup() {
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);
  Serial.begin(115200);
  Serial.print("setup() is running on core ");
  Serial.println(xPortGetCoreID());
  delay(1000);
}

void loop() {
  Serial.print("loop() is running on core ");
  Serial.println(xPortGetCoreID());

#ifdef RGB_BUILTIN
  neopixelWrite(RGB_BUILTIN, brightness[0], brightness[1], brightness[2]);

  if(direction == 1 ? brightness[color] >= RGB_BRIGHTNESS : brightness[color] <= 0){
    direction *= -1;
    color = (color + 2) % 3;
  }
  brightness[color] += direction;
  delay(10);
#endif
}
