//
// Created by tmtoon on 23.01.19.
//

#ifndef REGISTER_MACHINE_INSTRUCTION_H
#define REGISTER_MACHINE_INSTRUCTION_H

#include <iostream>

class Machine;
class Program;

class Instruction {
public:
    virtual void exe(Machine &m) const = 0;
};

class MOV : public Instruction {
private:
    std::string to;
    std::string from;
    int value;

public:
    MOV(const std::string &a, const std::string &b);

    MOV(const std::string &a, int b);

    void exe(Machine &m) const override;
};

class ADD : public Instruction {
private:
    std::string lhs;
    std::string rhs;

public:
    ADD(const std::string& lhs, const std::string& rhs);

    void exe(Machine &m) const override;
};

class SUB : public Instruction {
private:
    std::string lhs;
    std::string rhs;

public:
    SUB(const std::string& lhs, const std::string& rhs);

    void exe(Machine &m) const override;
};

class INC : public Instruction {
private:
    std::string reg;

public:
    explicit INC(const std::string& reg);

    void exe(Machine &m) const override;
};

class DEC : public Instruction {
private:
    std::string reg;

public:
    explicit DEC(const std::string& reg);

    void exe(Machine &m) const override;
};

class CMP : public Instruction {
private:
    std::string lhs;
    std::string rhs;

public:
    CMP(const std::string& lhs, const std::string& rhs);

    void exe(Machine &m) const override;
};

class JNE : public Instruction {
private:
    int goal;

public:
    explicit JNE(int goal);

    void exe(Machine &m) const override;
};

class JNZ : public Instruction {
private:
    int goal;

public:
    explicit JNZ(int goal);

    void exe(Machine &m) const override;
};

#endif //REGISTER_MACHINE_INSTRUCTION_H
