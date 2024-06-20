#pragma once
#ifndef CPU_H
#define CPU_H

#include <memory>

#include "Process.h"


class CPU {
public:
    CPU();
    ~CPU() = default;
    void setProcess(std::shared_ptr<Process> process);

    bool isReady() const { return _ready; };

private:
    void run();

    static int nextID;
    int _id;
    bool _ready = true;

    std::shared_ptr<Process> _process = nullptr;
};

#endif // !CPU_H