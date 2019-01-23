//
// Created by tmtoon on 23.01.19.
//

#include "Machine.h"

void Machine::reset() {
    _registers["A"] = 0;
    _registers["B"] = 0;
    _registers["C"] = 0;
    _registers["D"] = 0;
    _registers["IP"] = 0;
   resetflags();
}

void Machine::run(const Program& p) {
    reset();
    while (not p.end(getReg("IP"))) {
        p(getReg("IP"))->exe(*this);
        if (not getFlag("jump")) {
            setReg("IP", getReg("IP") + 1);
        }
    }
}

void Machine::setReg(const std::string &a, int val) {
    _registers[a] = val;
}

void Machine::setFlag(const std::string &a, bool val) {
    _flags[a] = val;
}

bool Machine::getFlag(const std::string &flag) {
    return _flags[flag];
}

int Machine::getReg(const std::string &reg) {
    return _registers[reg];
}

void Machine::resetflags() {
    _flags["equal"] = false;
    _flags["zero"] = false;
    _flags["jump"] = false;
}
