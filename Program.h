//
// Created by tmtoon on 23.01.19.
//

#ifndef REGISTER_MACHINE_PROGRAM_H
#define REGISTER_MACHINE_PROGRAM_H


#include <memory>
#include <vector>
#include "Instruction.h"

class Program {
private:
    std::vector<std::shared_ptr<Instruction>> _instructions;

public:
    Program& operator<<(Instruction* i);

    const std::shared_ptr<Instruction>& operator()(int IP) const;

    bool end(int IP) const;

};


#endif //REGISTER_MACHINE_PROGRAM_H
