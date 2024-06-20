#include "Scheduler.h"
#include <thread>
#include <chrono>


int main()
{
    Scheduler::initialize();
    Scheduler* scheduler = Scheduler::get();
    scheduler->demo();

    scheduler->start();
    std::this_thread::sleep_for(std::chrono::milliseconds(20000)); // should be enough for this test
}