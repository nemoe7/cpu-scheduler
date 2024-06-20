#include "Scheduler.h"


Scheduler* Scheduler::_ptr = nullptr;

Scheduler* Scheduler::get() {
    return _ptr;
}

void Scheduler::initialize() {
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
