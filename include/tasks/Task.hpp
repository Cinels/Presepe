#ifndef __TASK__
#define __TASK__

#include <Arduino.h>

/// @brief Abstract task.
class Task {
private:
    int period;
    TaskHandle_t *taskHandler;
    void loop();
    static void entry(void *pvParameters);
    /// @brief The task to execute each period.
    virtual void tick() = 0;
public:
    /// @brief Initialize the task setting the base period.
    /// @param period the base period every which the task must be performed.
    Task(const char* name, int period);

    /// @brief Returns the period of the task.
    /// @return the period of the task.
    int getPeriod();

    /// @brief Returns the task handle pointer.
    /// @return the pointer to the task handle.
    TaskHandle_t* getTaskHandle();
};

#endif
