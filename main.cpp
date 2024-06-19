#include <iostream>
#include <chrono>
#include <string>
#include <vector>

#include "PrintCommand.h"
#include "Process.h"


int main()
{
    Process process = Process(0, "test");
    process.setCPUCoreID(1);
    process.execute();
}