#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <memory>
#include <queue>

#include "CPU.h"
#include "Process.h"

class Scheduler {
public:
    static std::shared_ptr<Scheduler> get();
    static void initialize();
    static void destroy();

    void addProcess(Process process);

    void start();
    void stop();

    void demo();

    void printStatus();

private:
    Scheduler();
    ~Scheduler() = default;

    static std::shared_ptr<Scheduler> _ptr;

    std::queue<std::shared_ptr<Process>> _readyQueue;
    std::vector<std::shared_ptr<CPU>> _cpuList;

    bool running = false;
};

#endif // !SCHEDULER_H
