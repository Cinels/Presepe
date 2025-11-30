#ifndef __CONSTANTS__
#define __CONSTANTS__

//relay
#define CRAFTS_RELAY_PIN 2
#define HOUSE_AND_LANTERNS_RELAY_PIN 3
#define CANDLES_AND_LAMPS_RELAY_PIN 4
#define PATH_AND_STARS_RELAY_PIN 5

//photoresistor
#define PHOTO_RESISTOR_PIN 6
#define BRIGHTNESS_THRESHOLD 2000

//day duration
#define MORNING_TIME 30
#define DAY_TIME 180
#define EVENING_TIME 30
#define NIGHT_TIME 90
#define LATE_NIGHT_TIME 90
#define SKIP_TIME_PERIOD 300

//buttons
#define MODE_BUTTON_PIN 7
#define PERIOD_BUTTON_PIN 8
#define MODE_BUTTON_NOTIFY 0x00
#define PERIOD_BUTTON_NOTIFY 0x01

//display
#define LCD_I2C_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4

//tasks
#define DAY_TASK_PERIOD 100

#endif