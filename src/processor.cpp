#include "processor.h"

#include <cstdio>

namespace _6502
{
    void CPU::execute(Instruction instruction)
    {
        switch (instruction.mnemonic)
        {
            case Mnemonic::ADC:
                execute_ADC(instruction);
                break;

            case Mnemonic::AND:
                execute_AND(instruction);
                break;

            case Mnemonic::ASL:
                execute_ASL(instruction);
                break;

            case Mnemonic::BCC:
                execute_BCC(instruction);
                break;

            case Mnemonic::BCS:
                execute_BCS(instruction);
                break;

            case Mnemonic::BEQ:
                execute_BEQ(instruction);
                break;

            case Mnemonic::BIT:
                execute_BIT(instruction);
                break;

            case Mnemonic::BMI:
                execute_BMI(instruction);
                break;

            case Mnemonic::BNE:
                execute_BNE(instruction);
                break;

            case Mnemonic::BPL:
                execute_BPL(instruction);
                break;

            case Mnemonic::BRK:
                execute_BRK(instruction);
                break;

            case Mnemonic::BVC:
                execute_BVC(instruction);
                break;

            case Mnemonic::BVS:
                execute_BVS(instruction);
                break;

            case Mnemonic::CLC:
                execute_CLC(instruction);
                break;

            case Mnemonic::CLD:
                execute_CLD(instruction);
                break;

            case Mnemonic::CLI:
                execute_CLI(instruction);
                break;

            case Mnemonic::CLV:
                execute_CLV(instruction);
                break;

            case Mnemonic::CMP:
                execute_CMP(instruction);
                break;

            case Mnemonic::CPX:
                execute_CPX(instruction);
                break;

            case Mnemonic::CPY:
                execute_CPY(instruction);
                break;

            case Mnemonic::DEC:
                execute_DEC(instruction);
                break;

            case Mnemonic::DEX:
                execute_DEX(instruction);
                break;

            case Mnemonic::DEY:
                execute_DEY(instruction);
                break;

            case Mnemonic::EOR:
                execute_EOR(instruction);
                break;

            case Mnemonic::INC:
                execute_INC(instruction);
                break;

            case Mnemonic::INX:
                execute_INX(instruction);
                break;

            case Mnemonic::INY:
                execute_INY(instruction);
                break;

            case Mnemonic::JMP:
                execute_JMP(instruction);
                break;

            case Mnemonic::JSR:
                execute_JSR(instruction);
                break;

            case Mnemonic::LDA:
                execute_LDA(instruction);
                break;

            case Mnemonic::LDX:
                execute_LDX(instruction);
                break;

            case Mnemonic::LDY:
                execute_LDY(instruction);
                break;

            case Mnemonic::LSR:
                execute_LSR(instruction);
                break;

            case Mnemonic::NOP:
                execute_NOP(instruction);
                break;

            case Mnemonic::ORA:
                execute_ORA(instruction);
                break;

            case Mnemonic::PHA:
                execute_PHA(instruction);
                break;

            case Mnemonic::PHP:
                execute_PHP(instruction);
                break;

            case Mnemonic::PLA:
                execute_PLA(instruction);
                break;

            case Mnemonic::PLP:
                execute_PLP(instruction);
                break;

            case Mnemonic::ROL:
                execute_ROL(instruction);
                break;

            case Mnemonic::ROR:
                execute_ROR(instruction);
                break;

            case Mnemonic::RTI:
                execute_RTI(instruction);
                break;

            case Mnemonic::RTS:
                execute_RTS(instruction);
                break;

            case Mnemonic::SBC:
                execute_SBC(instruction);
                break;

            case Mnemonic::SEC:
                execute_SEC(instruction);
                break;

            case Mnemonic::SED:
                execute_SED(instruction);
                break;

            case Mnemonic::SEI:
                execute_SEI(instruction);
                break;

            case Mnemonic::STA:
                execute_STA(instruction);
                break;

            case Mnemonic::STX:
                execute_STX(instruction);
                break;

            case Mnemonic::STY:
                execute_STY(instruction);
                break;

            case Mnemonic::TAX:
                execute_TAX(instruction);
                break;

            case Mnemonic::TAY:
                execute_TAY(instruction);
                break;

            case Mnemonic::TSX:
                execute_TSX(instruction);
                break;

            case Mnemonic::TXA:
                execute_TXA(instruction);
                break;

            case Mnemonic::TXS:
                execute_TXS(instruction);
                break;

            case Mnemonic::TYA:
                execute_TYA(instruction);
                break;

            default:
                printf("PC: 0x%X | Unknown Instruction: %s , addressing mode: %s\n",
                    PC.read(),
                    to_string(instruction.mnemonic).c_str(),
                    to_string(instruction.addressing_mode).c_str()
                    );
                break;
        }
    }

    void CPU::execute(Byte op_code)
    {
        Instruction instruction = instruction_set[op_code];
        CPU::execute(instruction);
    }

    void CPU::execute_ADC(Instruction instruction)
    {
        switch (instruction.addressing_mode)
        {
            case AddressingMode::imm:
                break;

            case AddressingMode::zpg:
                break;

            case AddressingMode::zpgX:
                break;

            case AddressingMode::abs:
                break;

            case AddressingMode::absX:
                break;

            case AddressingMode::absY:
                break;

            case AddressingMode::Xind:
                break;

            case AddressingMode::indY:
                break;

            default:
                printf("PC: 0x%X | Unknown Instruction: %s , addressing mode: %s\n",
                    PC.read(),
                    to_string(instruction.mnemonic).c_str(),
                    to_string(instruction.addressing_mode).c_str()
                    );
        }
    }


}
