#include "Process.h"

#include "ICommand.h"
#include <iostream>
#include <memory>
#include <string>
#include "PrintCommand.h"


Process::Process(int pid, std::string name, bool filler) : _pid(pid), _name(name) {
    if (filler) {
        for (int i = 0; i < 100; i++) {
            this->_commandList.push_back(
                std::make_shared<PrintCommand>(
                    "Hello world from " + this->_name, this->_pid
                )
            );
        }
    }
}

void Process::execute() {
    if (!this->hasFinished()) {
        this->_commandList.at(_commandCounter)->execute(this->_cpuCoreID);
        this->_commandCounter++;
    }
}

bool Process::hasFinished() {
    if (this->_commandCounter >= this->_commandList.size()) {
        return true;
    }
    return false;
}

void Process::setCPUCoreID(int cpuCoreID) {
    this->_cpuCoreID = cpuCoreID;
}
