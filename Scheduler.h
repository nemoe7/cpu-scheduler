#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <memory>
#include <queue>
#include <vector>

#include "CPU.h"
#include "Process.h"

class Scheduler {
public:
    static Scheduler* get();
    static void initialize(int cpuCount = 4);
    static void destroy();

    void addProcess(Process process);

    void start();
    void stop();

    void demo();

    void printStatus();

private:
    Scheduler();
    ~Scheduler() = default;

    void run();

    static Scheduler* _ptr;

    std::queue<std::shared_ptr<Process>> _readyQueue;
    std::vector<std::shared_ptr<CPU>> _cpuList;
    std::vector<std::shared_ptr<Process>> _processList;
    bool running = false;
};

#endif // !SCHEDULER_H
