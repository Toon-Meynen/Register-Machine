//
// Created by tmtoon on 23.01.19.
//

#include "Instruction.h"
#include "Machine.h"
#include "Program.h"

MOV::MOV(const std::string &a, const std::string &b) : from(b), to(a) {}

MOV::MOV(const std::string &a, int b) : to(a), value(b) {}

void MOV::exe(Machine &m) const {
    m.resetflags();
    if (from.empty()) {
        m.setReg(to, value);
    } else {
        m.setReg(to, m.getReg(from));
    }
}

ADD::ADD(const std::string &lhs, const std::string &rhs) : lhs(lhs), rhs(rhs) {}

void ADD::exe(Machine &m) const {
    m.resetflags();
    m.setReg(lhs, m.getReg(lhs) + m.getReg(rhs));
    if (m.getReg(lhs) == 0) {
        m.setFlag("zero", true);
    }
}

SUB::SUB(const std::string &lhs, const std::string &rhs) : lhs(lhs), rhs(rhs) {}

void SUB::exe(Machine &m) const {
    m.resetflags();
    m.setReg(lhs, m.getReg(lhs) - m.getReg(rhs));
    if (m.getReg(lhs) == 0) {
        m.setFlag("zero", true);
    }
}

INC::INC(const std::string &reg) : reg(reg) {}

void INC::exe(Machine &m) const {
    m.resetflags();
    m.setReg(reg, m.getReg(reg) + 1);
    if (m.getReg(reg) == 0) {
        m.setFlag("zero", true);
    }
}

DEC::DEC(const std::string &reg) : reg(reg) {}

void DEC::exe(Machine &m) const {
    m.resetflags();
    m.setReg(reg, m.getReg(reg) - 1);
    if (m.getReg(reg) == 0) {
        m.setFlag("zero", true);
    }
}

CMP::CMP(const std::string &lhs, const std::string &rhs) : lhs(lhs), rhs(rhs) {}

void CMP::exe(Machine &m) const {
    m.resetflags();
    m.setFlag("equal", m.getReg(lhs) == m.getReg(rhs));
}

JNE::JNE(int goal) : goal(goal) {}

void JNE::exe(Machine &m) const {
    if (not m.getFlag("equal")) {
        m.setReg("IP", goal);
        m.setFlag("jump", true);
    }
}

JNZ::JNZ(int goal) : goal(goal) {}

void JNZ::exe(Machine &m) const {
    if (not m.getFlag("zero")) {
        m.setReg("IP", goal);
        m.setFlag("jump", true);
    }
}
