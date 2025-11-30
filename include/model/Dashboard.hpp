#ifndef __DASHBOARD__
#define __DASHBOARD__

#include "devices/Photoresistor.hpp"

class Dashboard {
private:
    Photoresistor photores;
public:
    Dashboard();
    bool isDark();
};

#endif