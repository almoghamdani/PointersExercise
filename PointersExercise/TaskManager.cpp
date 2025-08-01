#include "TaskManager.h"
#include "PointerArithmeticTasks.h"
#include <iostream>

TaskManager::TaskManager()
{
    initializeTasks();
}

void TaskManager::initializeTasks()
{
    // Initialize all advanced pointer arithmetic tasks
    tasks.push_back(std::make_unique<PointerArithmeticTask1>());
    tasks.push_back(std::make_unique<PointerArithmeticTask2>());
    tasks.push_back(std::make_unique<PointerArithmeticTask3>());
    tasks.push_back(std::make_unique<PointerArithmeticTask4>());
    tasks.push_back(std::make_unique<PointerArithmeticTask5>());
    tasks.push_back(std::make_unique<PointerArithmeticTask6>());
    tasks.push_back(std::make_unique<PointerArithmeticTask7>());
    tasks.push_back(std::make_unique<PointerArithmeticTask8>());

    // Initialize new pointer-to-pointer tasks
    tasks.push_back(std::make_unique<PointerArithmeticTask9>());
    tasks.push_back(std::make_unique<PointerArithmeticTask10>());
    tasks.push_back(std::make_unique<PointerArithmeticTask11>());
    tasks.push_back(std::make_unique<PointerArithmeticTask12>());
    tasks.push_back(std::make_unique<PointerArithmeticTask13>());
    tasks.push_back(std::make_unique<PointerArithmeticTask14>());
    tasks.push_back(std::make_unique<PointerArithmeticTask15>());
    tasks.push_back(std::make_unique<PointerArithmeticTask16>());

    // Initialize new vector manipulation tasks
    tasks.push_back(std::make_unique<PointerArithmeticTask17>());
    tasks.push_back(std::make_unique<PointerArithmeticTask18>());
    tasks.push_back(std::make_unique<PointerArithmeticTask19>());
    tasks.push_back(std::make_unique<PointerArithmeticTask20>());
    tasks.push_back(std::make_unique<PointerArithmeticTask21>());
    tasks.push_back(std::make_unique<PointerArithmeticTask22>());
    tasks.push_back(std::make_unique<PointerArithmeticTask23>());
    tasks.push_back(std::make_unique<PointerArithmeticTask24>());

    // Initialize new complex vector tasks
    tasks.push_back(std::make_unique<PointerArithmeticTask25>());
    tasks.push_back(std::make_unique<PointerArithmeticTask26>());
    tasks.push_back(std::make_unique<PointerArithmeticTask27>());
    tasks.push_back(std::make_unique<PointerArithmeticTask28>());
    tasks.push_back(std::make_unique<PointerArithmeticTask29>());

    // Initialize complex struct data extraction tasks
    tasks.push_back(std::make_unique<PointerArithmeticTask30>());
    tasks.push_back(std::make_unique<PointerArithmeticTask31>());
    tasks.push_back(std::make_unique<PointerArithmeticTask32>());
    tasks.push_back(std::make_unique<PointerArithmeticTask33>());

    // Initialize bug-fixing tasks
    tasks.push_back(std::make_unique<PointerArithmeticTask34>());
    tasks.push_back(std::make_unique<PointerArithmeticTask35>());
    tasks.push_back(std::make_unique<PointerArithmeticTask36>());

    // Initialize advanced complex bug-fixing tasks
    tasks.push_back(std::make_unique<PointerArithmeticTask37>());
    tasks.push_back(std::make_unique<PointerArithmeticTask38>());
}

void TaskManager::runAllTasks()
{
    std::cout << "Total tasks available: " << tasks.size() << std::endl;
    std::cout << std::endl;

    for (size_t i = 0; i < tasks.size(); ++i)
    {
        std::cout << "=== Task " << (i + 1) << " ===" << std::endl;
        try
        {
            tasks[i]->execute();
        }
        catch (const std::exception& e)
        {
            std::cout << "\033[31m[EXCEPTION]\033[0m Task " << (i + 1) << " threw an exception: " << e.what() <<
                    std::endl;
            std::cout << "\033[31m[FAILED]\033[0m Task " << (i + 1) << " failed due to exception" << std::endl;
        }
        catch (...)
        {
            std::cout << "\033[31m[EXCEPTION]\033[0m Task " << (i + 1) << " threw an unknown exception" << std::endl;
            std::cout << "\033[31m[FAILED]\033[0m Task " << (i + 1) << " failed due to unknown exception" << std::endl;
        }
        std::cout << std::endl;
    }
}

void TaskManager::runTask(int taskNumber)
{
    if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size()))
    {
        std::cout << "=== Task " << taskNumber << " ===" << std::endl;
        try
        {
            tasks[taskNumber - 1]->execute();
        }
        catch (const std::exception& e)
        {
            std::cout << "\033[31m[EXCEPTION]\033[0m Task " << taskNumber << " threw an exception: " << e.what() <<
                    std::endl;
            std::cout << "\033[31m[FAILED]\033[0m Task " << taskNumber << " failed due to exception" << std::endl;
        }
        catch (...)
        {
            std::cout << "\033[31m[EXCEPTION]\033[0m Task " << taskNumber << " threw an unknown exception" << std::endl;
            std::cout << "\033[31m[FAILED]\033[0m Task " << taskNumber << " failed due to unknown exception" <<
                    std::endl;
        }
    }
    else
    {
        std::cout << "Invalid task number. Available tasks: 1-" << tasks.size() << std::endl;
    }
}
