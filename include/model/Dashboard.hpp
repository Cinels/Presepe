#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "devices/Photoresistor.hpp"
#include "devices/Button.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class Dashboard {
private:
    Photoresistor photores;
    Button modeButton;
    Button periodButton;
    static TaskHandle_t* dayTaskHandler;
    //two buttons -> one skip mode, the other skip period
    //one screen
    //maybe 4 switches
public:
    Dashboard(TaskHandle_t* dayTaskHandler);
    bool isDark();
};

#endif