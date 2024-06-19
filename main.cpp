#include <iostream>
#include <chrono>
#include <vector>

#include "PrintCommand.h"


int main()
{
    std::vector<PrintCommand> commands;
    for (int i = 0; i < 5; i++) {
        commands.push_back(PrintCommand("Hello world", 0));

    }
    auto start = std::chrono::high_resolution_clock::now();
    for (auto& command : commands) {
        command.execute(0);
    }
    auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << elapsed.count();
}