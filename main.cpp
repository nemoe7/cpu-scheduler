#include <iostream>
#include <chrono>
#include <string>
#include <vector>

#include "PrintCommand.h"
#include "Process.h"


int main()
{
    Process process = Process(0, "test", true);
    process.setCPUCoreID(1);
    while (!process.hasFinished()) {
        process.execute();
    }
}