#pragma once
#include <array>
#include <cstdint>

namespace _6502
{
    using Byte = std::uint8_t;

    enum class AddressingMode
    {
        none = -1,
        A,      // Accumulator
        abs,    // absolute
        absX,   // absolute, X-indexed
        absY,   // absolute, Y-indexed
        imm,    // immediate
        impl,   // implied
        ind,    // indirect
        Xind,   // X-indexed, indirect
        indY,   // indirect, Y-indexed
        rel,    // relative
        zpg,    // zeropage
        zpgX,   // zeropage, X-indexed
        zpgY    // zeropage, Y-indexed
    };

    enum class Mnemonic
    {
        none = -1,
        ADC, AND, ASL,
        BCC, BCS, BEQ, BIT, BMI, BNE, BPL, BRK, BVC,
        CLC, CLD, CLI, CLV, CMP, CPX, CPY,
        DEC, DEX, DEY,
        EOR,
        INC, INX, INY,
        JMP, JSR,
        LDA, LDX, LDY, LSR,
        NOP,
        ORA,
        PHA, PHP, PLA, PLP,
        ROL, ROR, RTI, RTS,
        SBC, SEC, SED, SEI, STA, STX, STY,
        TAX, TAY, TSX, TXA, TXS, TYA
    };

    struct Instruction
    {
        Byte op_code;
        Byte bytes;
        Byte cycles;
        Mnemonic mnemonic;
        AddressingMode addressing_mode;
    };

    inline std::array<Instruction, 0x100> instruction_set
    {
        Instruction{0x00, 1, 7, Mnemonic::BRK, AddressingMode::impl},
        Instruction{0x01, 2, 6, Mnemonic::ORA, AddressingMode::Xind},
        Instruction{0x02, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x03, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x04, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x05, 2, 3, Mnemonic::ORA, AddressingMode::zpg},
        Instruction{0x06, 2, 5, Mnemonic::ASL, AddressingMode::zpg},
        Instruction{0x07, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x08, 1, 3, Mnemonic::PHP, AddressingMode::impl},
        Instruction{0x09, 2, 2, Mnemonic::ORA, AddressingMode::imm},
        Instruction{0x0A, 1, 2, Mnemonic::ASL, AddressingMode::A},
        Instruction{0x0B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x0C, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x0D, 3, 4, Mnemonic::ORA, AddressingMode::abs},
        Instruction{0x0E, 3, 6, Mnemonic::ASL, AddressingMode::abs},
        Instruction{0x0F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x10, 2, 2, Mnemonic::BPL, AddressingMode::rel},
        Instruction{0x11, 2, 5, Mnemonic::ORA, AddressingMode::indY},
        Instruction{0x12, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x13, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x14, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x15, 2, 4, Mnemonic::ORA, AddressingMode::zpgX},
        Instruction{0x16, 2, 6, Mnemonic::ASL, AddressingMode::zpgX},
        Instruction{0x17, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x18, 1, 2, Mnemonic::CLC, AddressingMode::impl},
        Instruction{0x19, 3, 4, Mnemonic::ORA, AddressingMode::absY},
        Instruction{0x1A, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x1B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x1C, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x1D, 3, 4, Mnemonic::ORA, AddressingMode::absX},
        Instruction{0x1E, 3, 7, Mnemonic::ASL, AddressingMode::absX},
        Instruction{0x1F, 0, 0, Mnemonic::none, AddressingMode::none},

    };

}
