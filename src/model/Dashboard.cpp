#include "model/Dashboard.hpp"
#include "constants.hpp"

Dashboard::Dashboard() : photores(PHOTO_RESISTOR_PIN) {

}

bool Dashboard::isDark() {
    return photores.getValue() < BRIGHTNESS_THRESHOLD;
}