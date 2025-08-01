#include "Task.h"
#include <iostream>

bool Task::verifyResult(bool condition, const std::string& message)
{
    if (condition)
    {
        // Green color for success
        std::cout << "\033[32m[PASS]\033[0m " << message << std::endl;
        return true;
    }
    else
    {
        // Red color for failure
        std::cout << "\033[31m[FAIL]\033[0m " << message << std::endl;
        return false;
    }
}

void Task::displayTaskInfo()
{
    std::cout << "TASK: " << getDescription() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}
