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

        void execute(Instruction instruction);
        void execute(Byte op_code);

    private:
        void execute_ADC(Instruction instruction);
        void execute_AND(Instruction instruction);
        void execute_ASL(Instruction instruction);

        void execute_BCC(Instruction instruction);
        void execute_BCS(Instruction instruction);
        void execute_BEQ(Instruction instruction);
        void execute_BIT(Instruction instruction);
        void execute_BMI(Instruction instruction);
        void execute_BNE(Instruction instruction);
        void execute_BPL(Instruction instruction);
        void execute_BRK(Instruction instruction);
        void execute_BVC(Instruction instruction);
        void execute_BVS(Instruction instruction);

        void execute_CLC(Instruction instruction);
        void execute_CLD(Instruction instruction);
        void execute_CLI(Instruction instruction);
        void execute_CLV(Instruction instruction);
        void execute_CMP(Instruction instruction);
        void execute_CPX(Instruction instruction);
        void execute_CPY(Instruction instruction);

        void execute_DEC(Instruction instruction);
        void execute_DEX(Instruction instruction);
        void execute_DEY(Instruction instruction);

        void execute_EOR(Instruction instruction);

        void execute_INC(Instruction instruction);
        void execute_INX(Instruction instruction);
        void execute_INY(Instruction instruction);

        void execute_JMP(Instruction instruction);
        void execute_JSR(Instruction instruction);

        void execute_LDA(Instruction instruction);
        void execute_LDX(Instruction instruction);
        void execute_LDY(Instruction instruction);
        void execute_LSR(Instruction instruction);

        void execute_NOP(Instruction instruction);

        void execute_ORA(Instruction instruction);

        void execute_PHA(Instruction instruction);
        void execute_PHP(Instruction instruction);
        void execute_PLA(Instruction instruction);
        void execute_PLP(Instruction instruction);

        void execute_ROL(Instruction instruction);
        void execute_ROR(Instruction instruction);
        void execute_RTI(Instruction instruction);
        void execute_RTS(Instruction instruction);

        void execute_SBC(Instruction instruction);
        void execute_SEC(Instruction instruction);
        void execute_SED(Instruction instruction);
        void execute_SEI(Instruction instruction);
        void execute_STA(Instruction instruction);
        void execute_STX(Instruction instruction);
        void execute_STY(Instruction instruction);

        void execute_TAX(Instruction instruction);
        void execute_TAY(Instruction instruction);
        void execute_TSX(Instruction instruction);
        void execute_TXA(Instruction instruction);
        void execute_TXS(Instruction instruction);
        void execute_TYA(Instruction instruction);
    };
}