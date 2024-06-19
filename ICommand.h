#pragma once
#ifndef ICOMMAND_H
#define ICOMMAND_H


enum CommandType {
    PRINT
};

class ICommand {
public:
    virtual void execute(int core) = 0;

    int _pid;
    CommandType _type;
};

#endif // !ICOMMAND_H