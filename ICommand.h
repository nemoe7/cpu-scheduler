#pragma once
#ifndef ICOMMAND_H
#define ICOMMAND_H


enum CommandType {
    PRINT
};

class ICommand {
public:
    virtual void execute() = 0;

    int pid;
    CommandType type;
};

#endif // !ICOMMAND_H