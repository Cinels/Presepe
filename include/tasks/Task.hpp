#ifndef __TASK__
#define __TASK__

#include <Arduino.h>

/// @brief Abstract task.
class Task {
private:
    TaskHandle_t taskHandler;
    void loop();
    static void entry(void *pvParameters);
    /// @brief The task to execute each period.
    virtual void tick() = 0;
protected:
    int period;
public:
    Task();

    /// @brief Initialize the task setting the base period.
    /// @param name the name of the task.
    /// @param period the base period every which the task must be performed.
    /// @param stackSize 
    /// @param priority 
    void start(const char* name, const int period, const uint16_t stackSize = 2048, UBaseType_t priority = 1);

    /// @brief Returns the period of the task.
    /// @return the period of the task.
    int getPeriod();

    /// @brief Returns the task handle pointer.
    /// @return the pointer to the task handle.
    TaskHandle_t getTaskHandle();
};

#endif
