#include "Process.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include "PrintCommand.h"


typedef std::string String;

Process::Process(int pid, String name, bool filler) : _pid(pid), _name(name) {
    String filename = ".\\output\\" + this->_name + ".txt";
    std::ofstream output;
    output.open(filename, std::ios::out);
    if (output.is_open()) {
        output << "Process name: " << this->_name << std::endl
            << "Logs:" << std::endl
            << std::endl;
        output.close();
    }
    if (filler) {
        for (int i = 0; i < 100; i++) {
            this->_commandList.push_back(
                std::make_shared<PrintCommand>(
                    "Hello world from " + this->_name + "!", this->_pid
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
