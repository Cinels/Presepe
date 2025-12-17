#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "devices/Photoresistor.hpp"
#include "devices/Button.hpp"
#include "devices/Display.hpp"

static TaskHandle_t dayTaskHandler = NULL;

class Dashboard {
private:
    Photoresistor photores;
    Button modeButton;
    Button periodButton;
    Display display;
public:
    Dashboard();
    void init(TaskHandle_t dayTaskHandler);
    bool isDark();
    void modeChanged(String mode);
    void periodChanged(String period);
    void showTimer(float ticks);
};

#endif