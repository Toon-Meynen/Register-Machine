#include <iostream>

#include "Machine.h"

int main() {
    int n = 10;

    Program prog;

    prog << (new MOV("D", n-1));
    prog << (new MOV("A", 0));
    prog << (new MOV("B", 1));

    prog << (new MOV("C", "B"));
    prog << (new ADD("B", "A"));
    prog << (new MOV("A", "C"));

    prog << (new DEC("D"));
    prog << (new JNZ(3));

    Machine mach;
    mach.run(prog);

    std::cout << "F_" << n << " = " << mach.getReg("B") << std::endl;
    return 0;
}