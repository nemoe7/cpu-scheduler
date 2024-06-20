#include "Scheduler.h"
#include <thread>
#include <chrono>


int main()
{
    Scheduler::initialize();
    Scheduler* scheduler = Scheduler::get();
    scheduler->demo();

    scheduler->start();
    auto start = std::chrono::steady_clock::now();
    while (true) {
        scheduler->printStatus();
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        if (std::chrono::steady_clock::now() - start > std::chrono::seconds(20))
            break;
    }
}