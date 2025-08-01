#pragma once
#include <vector>
#include <memory>
#include "Task.h"

class TaskManager
{
public:
    TaskManager();
    ~TaskManager() = default;

    void runAllTasks();
    void runTask(int taskNumber);

private:
    std::vector<std::unique_ptr<Task>> tasks;
    void initializeTasks();
};
