#pragma once

#include "memory.h"
#include "Instructionset.h"

/*
sources:
https://www.masswerk.at/6502/6502_instruction_set.html#family
http://www.6502.org/users/obelisk/
 */

namespace _6502
{

    struct CPU
    {
        // Registers
        Register16 PC;  // program counter
        Register8 SP;  // stack pointer
        Register8 ACC;  // accumulator
        Register8 IX;   // index register x
        Register8 IY;   // index register y
        Register8 FLAGS;// processor status register (flags)

        Memory64k memory64;

        int CLOCK_SPEED = 1000000;

        void execute();
    };
}