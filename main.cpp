#include "Scheduler.h"
#include <string>
#include <iostream>


int main()
{
    Scheduler::initialize();
    Scheduler* scheduler = Scheduler::get();
    scheduler->demo();
    scheduler->start();

    std::string input = "";
    while (input != "exit") {
        std::cout << "Enter a command: ";
        std::getline(std::cin, input);
        
        if (input == "screen -ls") {
            scheduler->printStatus();
        }
    }
}