#ifndef __CONSTANTS__
#define __CONSTANTS__

//relay
#define CRAFTS_PIN 17
#define HOUSE_BIG_LIGHTS_PIN 16
#define STARS_PIN 15

//transistor
#define HOUSE_MEDIUM_LIGHTS_PIN 9
#define HOUSE_SMALL_LIGHTS_PIN 10
#define BLACK_LANTERNS_PIN 11
#define BROWN_LANTERNS_1_PIN 12
#define BROWN_LANTERNS_2_PIN 13
#define CANDLES_AND_LAMPS_PIN 14
#define PATH_PIN 7

//photoresistor
#define PHOTO_RESISTOR_PIN 6
#define BRIGHTNESS_THRESHOLD 1000

//day duration
#define MORNING_TIME 30
#define DAY_TIME 180
#define EVENING_TIME 30
#define NIGHT_TIME 90
#define LATE_NIGHT_TIME 90
#define OFF_TIME 1
#define SKIP_TIME_PERIOD 300

//buttons
#define MODE_BUTTON_PIN 4
#define PERIOD_BUTTON_PIN 5

//display
#define I2C_SDA_PIN 1
#define I2C_SCL_PIN 2
#define LCD_I2C_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4
#define MODE_ROW 0
#define MODE_COL 10
#define PERIOD_ROW 1
#define PERIOD_COL 9
#define TIMER_ROW 2
#define TIMER_COL 0

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