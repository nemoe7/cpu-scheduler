#include "PrintCommand.h"
#include <chrono>
#include <thread>

void PrintCommand::execute() {
    //TODO
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
