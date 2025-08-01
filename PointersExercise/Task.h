#pragma once
#include <string>

class Task
{
public:
    virtual ~Task() = default;

    virtual void execute() = 0;
    virtual std::string getDescription() const = 0;

protected:
    bool verifyResult(bool condition, const std::string& message);
    void displayTaskInfo();
};
