#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <ctime>
#include <memory>
#include <string>
#include <vector>

#include "ICommand.h"


class Process {
public:
    Process(int pid, std::string name, bool filler = false);
    ~Process() = default;

    void execute();
    bool hasFinished();

    std::string getName() const { return _name; };
    int getCommandCounter() const { return _commandCounter; };
    int getCommandListSize() const { return _commandList.size(); };
    time_t getArrivalTime() const { return _arrivalTime; };

    void setCPUCoreID(int cpuCoreID);

private:
    int _pid;
    std::string _name;
    std::vector<std::shared_ptr<ICommand>> _commandList;
    int _commandCounter = 0;
    int _cpuCoreID = -1;
    time_t _arrivalTime = time(nullptr);
};

#endif // !PROCESS_H