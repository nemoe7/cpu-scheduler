#pragma once
#ifndef PROCESS_H
#define PROCESS_H

#include <memory>
#include <string>
#include <vector>

#include "ICommand.h"


class Process {
public:
    Process(int pid, std::string name, bool filler = true);
    ~Process() = default;

    void execute();
    bool hasFinished();

    void setCPUCoreID(int cpuCoreID);

private:
    int _pid;
    std::string _name;
    std::vector<std::shared_ptr<ICommand>> _commandList;
    int _commandCounter = 0;
    int _cpuCoreID = -1;
};

#endif // !PROCESS_H