#include "Scheduler.h"

#include <memory>
#include <string>
#include <thread>

#include "CPU.h"
#include "Process.h"

#include <iostream>
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
    this->_readyQueue.push(std::make_shared<Process>(process));
}

void Scheduler::start() {
    if (this->running == false) {
        this->running = true;
        std::thread t(&Scheduler::run, this);
        t.detach();
    }
}

void Scheduler::stop() {
    this->running = false;
}

void Scheduler::demo() {
    for (int i = 0; i < 10; i++) {
        this->_readyQueue.push(std::make_shared<Process>(i, "screen_" + std::to_string(i), true));
    }
}

void Scheduler::printStatus() {
}

Scheduler::Scheduler() {
}

void Scheduler::run() {
    while (this->running) {
        this->running = false;
        for (int i = 0; i < this->_cpuList.size(); i++) {
            std::shared_ptr<CPU> cpu = this->_cpuList.at(i);
            if (cpu->isReady()) {
                if (this->_readyQueue.size() > 0) {
                    cpu->setProcess(this->_readyQueue.front());
                    this->_readyQueue.pop();
                    this->running = true;
                }
            }
            else {
                if (this->running == false) {
                    this->running = true;
                }
            }
        }
    }
}
