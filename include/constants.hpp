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
#define OFF_TIME 1
#define SKIP_TIME_PERIOD 300

//buttons
#define MODE_BUTTON_PIN 7
#define PERIOD_BUTTON_PIN 8

//display
#define LCD_I2C_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4

//tasks
#define DAY_TASK_PERIOD 100
#define FADING_PERIOD 10

//notifications
#define MODE_BUTTON_NOTIFY (1 << 0)
#define PERIOD_BUTTON_NOTIFY (1 << 1)
#define MODE_LOOP_NOTIFY (1 << 2)
#define MODE_FAST_LOOP_NOTIFY (1 << 3)
#define MODE_AUTOMATIC_NOTIFY (1 << 4)
#define MODE_MANUAL_NOTIFY (1 << 5)
#define PERIOD_MORNING_NOTIFY (1 << 6)
#define PERIOD_DAY_NOTIFY (1 << 7)
#define PERIOD_EVENING_NOTIFY (1 << 8)
#define PERIOD_NIGHT_NOTIFY (1 << 9)
#define PERIOD_LATE_NIGHT_NOTIFY (1 << 10)
#define PERIOD_OFF_NOTIFY (1 << 11)
#define TOGGLE_CRAFTS_NOTIFY (1 << 12)
#define TOGGLE_HOUSES_AND_LANTERNS_NOTIFY (1 << 13)
#define TOGGLE_CANDLES_AND_LAMPS_NOTIFY (1 << 14)
#define TOGGLE_PATH_AND_STARS_NOTIFY (1 << 15)
//play specific sound (??)

#endif