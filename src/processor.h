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
    public:
        void execute(const Instruction& instruction);
        void execute(Byte op_code);

    public:
        int CLOCK_SPEED = 1000000;

        // Registers
        Register16 PC;  // program counter
        Register8 SP;  // stack pointer
        Register8 ACC;  // accumulator
        Register8 IX;   // index register x
        Register8 IY;   // index register y
        Register8 FLAGS;// processor status register (flags)

        Memory64k memory64;

    private:
        void printUnknownInstrMsg(const Instruction& instruction) const;

        void execute_ADC(const Instruction& instruction);
        void execute_AND(const Instruction& instruction);
        void execute_ASL(const Instruction& instruction);

        void execute_BCC(const Instruction& instruction);
        void execute_BCS(const Instruction& instruction);
        void execute_BEQ(const Instruction& instruction);
        void execute_BIT(const Instruction& instruction);
        void execute_BMI(const Instruction& instruction);
        void execute_BNE(const Instruction& instruction);
        void execute_BPL(const Instruction& instruction);
        void execute_BRK(const Instruction& instruction);
        void execute_BVC(const Instruction& instruction);
        void execute_BVS(const Instruction& instruction);

        void execute_CLC(const Instruction& instruction);
        void execute_CLD(const Instruction& instruction);
        void execute_CLI(const Instruction& instruction);
        void execute_CLV(const Instruction& instruction);
        void execute_CMP(const Instruction& instruction);
        void execute_CPX(const Instruction& instruction);
        void execute_CPY(const Instruction& instruction);

        void execute_DEC(const Instruction& instruction);
        void execute_DEX(const Instruction& instruction);
        void execute_DEY(const Instruction& instruction);

        void execute_EOR(const Instruction& instruction);

        void execute_INC(const Instruction& instruction);
        void execute_INX(const Instruction& instruction);
        void execute_INY(const Instruction& instruction);

        void execute_JMP(const Instruction& instruction);
        void execute_JSR(const Instruction& instruction);

        void execute_LDA(const Instruction& instruction);
        void execute_LDX(const Instruction& instruction);
        void execute_LDY(const Instruction& instruction);
        void execute_LSR(const Instruction& instruction);

        void execute_NOP(const Instruction& instruction);

        void execute_ORA(const Instruction& instruction);

        void execute_PHA(const Instruction& instruction);
        void execute_PHP(const Instruction& instruction);
        void execute_PLA(const Instruction& instruction);
        void execute_PLP(const Instruction& instruction);

        void execute_ROL(const Instruction& instruction);
        void execute_ROR(const Instruction& instruction);
        void execute_RTI(const Instruction& instruction);
        void execute_RTS(const Instruction& instruction);

        void execute_SBC(const Instruction& instruction);
        void execute_SEC(const Instruction& instruction);
        void execute_SED(const Instruction& instruction);
        void execute_SEI(const Instruction& instruction);
        void execute_STA(const Instruction& instruction);
        void execute_STX(const Instruction& instruction);
        void execute_STY(const Instruction& instruction);

        void execute_TAX(const Instruction& instruction);
        void execute_TAY(const Instruction& instruction);
        void execute_TSX(const Instruction& instruction);
        void execute_TXA(const Instruction& instruction);
        void execute_TXS(const Instruction& instruction);
        void execute_TYA(const Instruction& instruction);
    };
}