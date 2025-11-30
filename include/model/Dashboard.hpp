#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "devices/Photoresistor.hpp"
#include "devices/Button.hpp"
#include "devices/Display.hpp"

class Dashboard {
private:
    static TaskHandle_t* dayTaskHandler;

    Photoresistor photores;
    Button modeButton;
    Button periodButton;
    Display display;
    //one screen
    //maybe 4 switches
public:
    Dashboard(TaskHandle_t* dayTaskHandler);
    bool isDark();
};

#endif