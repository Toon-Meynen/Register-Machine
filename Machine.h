//
// Created by tmtoon on 23.01.19.
//

#ifndef REGISTER_MACHINE_MACHINE_H
#define REGISTER_MACHINE_MACHINE_H


#include <map>
#include "Program.h"

class Machine {
private:
    std::map<std::string, int> _registers;
    std::map<std::string, bool> _flags;

public:
    void reset();
    void resetflags();
    void setReg(const std::string& a, int val);
    void setFlag(const std::string& a, bool val);

    void run(const Program& p);

    int getReg(const std::string& reg);

    bool getFlag(const std::string& flag);
};


#endif //REGISTER_MACHINE_MACHINE_H
