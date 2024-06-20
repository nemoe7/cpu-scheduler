#include "Process.h"
#include "CPU.h"
#include <memory>
#include <queue>


int main()
{
    std::shared_ptr<Process> process_ptr = std::make_shared<Process>(0, "test", true);
    std::shared_ptr<Process> process_ptr2 = std::make_shared<Process>(1, "test1", true);
    std::shared_ptr<Process> process_ptr3 = std::make_shared<Process>(2, "test2", true);
    std::shared_ptr<Process> process_ptr4 = std::make_shared<Process>(3, "test3", true);
    std::queue<std::shared_ptr<Process>> process_list;
    process_list.push(process_ptr);
    process_list.push(process_ptr2);
    process_list.push(process_ptr3);
    process_list.push(process_ptr4);
    CPU cpu = CPU();
    CPU cpu2 = CPU();
    while (!process_ptr4->hasFinished()) {
        if (process_list.size() > 0 && cpu.isReady()) {
            cpu.setProcess(process_list.front());
            process_list.pop();
        }
        if (process_list.size() > 0 && cpu2.isReady()) {
            cpu2.setProcess(process_list.front());
            process_list.pop();
        }
    }
}