#pragma once

#include "memory.h"

struct CPU
{
    // Registers
    Register16 PC;  // program counter
    Register16 SP;  // stack pointer
    Register8 ACC;  // accumulator
    Register8 IX;   // index register x
    Register8 IY;   // index register y
    Register8 FLAGS;// processor status register (flags)

    Memory64k memory64;
};