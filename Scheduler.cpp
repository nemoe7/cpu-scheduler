#include "Scheduler.h"

#include <memory>

#include "CPU.h"
#include "Process.h"


Scheduler* Scheduler::_ptr = nullptr;

Scheduler* Scheduler::get() {
    return _ptr;
}

void Scheduler::initialize(int cpuCount) {
    _ptr = new Scheduler();
    for (int i = 0; i < cpuCount; i++) {
        _ptr->_cpuList.push_back(std::make_shared<CPU>());
    }
}

void Scheduler::destroy() {
    delete _ptr;
}

void Scheduler::addProcess(Process process) {

}

void Scheduler::start() {
}

void Scheduler::stop() {
}

void Scheduler::demo() {
}

void Scheduler::printStatus() {
}

Scheduler::Scheduler() {
}
