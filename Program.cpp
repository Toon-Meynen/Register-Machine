//
// Created by tmtoon on 23.01.19.
//

#include "Program.h"

Program &Program::operator<<(Instruction *i) {
    _instructions.emplace_back(i);
    return *this;
}

bool Program::end(int IP) const {
    return _instructions.size() == IP;
}

const std::shared_ptr<Instruction> &Program::operator()(int IP) const {
    return _instructions[IP];
}
