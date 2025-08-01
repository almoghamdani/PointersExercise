#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "TaskManager.h"

int main()
{
    // Enable ANSI color support for Windows console
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    std::cout << "=== Pointers Exercise System ===" << std::endl;
    std::cout << "Welcome to the C/C++ Pointers Learning Platform!" << std::endl;
    std::cout << "This system will help you master pointer arithmetic concepts." << std::endl;
    std::cout << std::endl;

    TaskManager taskManager;
    taskManager.runAllTasks();

    std::cout << std::endl;
    std::cout << "=== Exercise Complete ===" << std::endl;
    std::cout << "Press any key to exit..." << std::endl;
    std::cin.get();

    return 0;
}
