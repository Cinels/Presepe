#include <Arduino.h>

#define PHOTORES_PIN 10
#define LUMINOSITY 200


int brightness[3] = {RGB_BRIGHTNESS, RGB_BRIGHTNESS, RGB_BRIGHTNESS};
int color = 0;
int direction = 1;

void setup() {
  pinMode(PHOTORES_PIN, INPUT);
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);
  Serial.begin(115200);
  Serial.print("setup() is running on core ");
  Serial.println(xPortGetCoreID());
  delay(1000);
}

void loop() {
  Serial.print("loop() is running on core ");
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
#endif
  delay(1000);
}
