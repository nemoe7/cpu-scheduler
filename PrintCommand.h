#pragma once
#include "ICommand.h"
#include <memory>


class PrintCommand :
    public ICommand {
    PrintCommand(int pid) : _pid(pid) {};
    ~PrintCommand() = default;

    void execute();

    int _pid;
    CommandType _type = PRINT;

    std::shared_ptr<std::ostream> _output;
};

