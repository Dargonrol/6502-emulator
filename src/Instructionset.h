#pragma once

#include <array>
#include <cstdint>
#include <string>

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
        BCC, BCS, BEQ, BIT, BMI, BNE, BPL, BRK, BVC, BVS,
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

        Instruction{0x20, 3, 6, Mnemonic::JSR, AddressingMode::abs},
        Instruction{0x21, 2, 6, Mnemonic::AND, AddressingMode::Xind},
        Instruction{0x22, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x23, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x24, 2, 3, Mnemonic::BIT, AddressingMode::zpg},
        Instruction{0x25, 2, 3, Mnemonic::AND, AddressingMode::zpg},
        Instruction{0x26, 2, 5, Mnemonic::ROL, AddressingMode::zpg},
        Instruction{0x27, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x28, 1, 4, Mnemonic::PLP, AddressingMode::impl},
        Instruction{0x29, 2, 2, Mnemonic::AND, AddressingMode::imm},
        Instruction{0x2A, 1, 2, Mnemonic::ROL, AddressingMode::A},
        Instruction{0x2B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x2C, 3, 4, Mnemonic::BIT, AddressingMode::abs},
        Instruction{0x2D, 3, 4, Mnemonic::AND, AddressingMode::abs},
        Instruction{0x2E, 3, 6, Mnemonic::ROL, AddressingMode::abs},
        Instruction{0x2F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x30, 2, 2, Mnemonic::BMI, AddressingMode::rel},
        Instruction{0x31, 2, 5, Mnemonic::AND, AddressingMode::indY},
        Instruction{0x32, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x33, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x34, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x35, 2, 4, Mnemonic::AND, AddressingMode::zpgX},
        Instruction{0x36, 2, 6, Mnemonic::ROL, AddressingMode::zpgX},
        Instruction{0x37, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x38, 1, 2, Mnemonic::SEC, AddressingMode::impl},
        Instruction{0x39, 3, 4, Mnemonic::AND, AddressingMode::absY},
        Instruction{0x3A, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x3B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x3C, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x3D, 3, 4, Mnemonic::AND, AddressingMode::absX},
        Instruction{0x3E, 3, 7, Mnemonic::ROL, AddressingMode::absX},
        Instruction{0x3F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x40, 1, 6, Mnemonic::RTI, AddressingMode::impl},
        Instruction{0x41, 2, 6, Mnemonic::EOR, AddressingMode::Xind},
        Instruction{0x42, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x43, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x44, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x45, 2, 3, Mnemonic::EOR, AddressingMode::zpg},
        Instruction{0x46, 2, 5, Mnemonic::LSR, AddressingMode::zpg},
        Instruction{0x47, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x48, 1, 3, Mnemonic::PHA, AddressingMode::impl},
        Instruction{0x49, 2, 2, Mnemonic::EOR, AddressingMode::imm},
        Instruction{0x4A, 1, 2, Mnemonic::LSR, AddressingMode::A},
        Instruction{0x4B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x4C, 3, 3, Mnemonic::JMP, AddressingMode::abs},
        Instruction{0x4D, 3, 4, Mnemonic::EOR, AddressingMode::abs},
        Instruction{0x4E, 3, 6, Mnemonic::LSR, AddressingMode::abs},
        Instruction{0x4F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x50, 2, 2, Mnemonic::BVC, AddressingMode::rel},
        Instruction{0x51, 2, 5, Mnemonic::EOR, AddressingMode::indY},
        Instruction{0x52, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x53, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x54, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x55, 2, 4, Mnemonic::EOR, AddressingMode::zpgX},
        Instruction{0x56, 2, 6, Mnemonic::LSR, AddressingMode::zpgX},
        Instruction{0x57, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x58, 1, 2, Mnemonic::CLI, AddressingMode::impl},
        Instruction{0x59, 3, 4, Mnemonic::EOR, AddressingMode::absY},
        Instruction{0x5A, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x5B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x5C, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x5D, 3, 4, Mnemonic::EOR, AddressingMode::absX},
        Instruction{0x5E, 3, 7, Mnemonic::LSR, AddressingMode::absX},
        Instruction{0x5F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x60, 1, 6, Mnemonic::RTS, AddressingMode::impl},
        Instruction{0x61, 2, 6, Mnemonic::ADC, AddressingMode::Xind},
        Instruction{0x62, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x63, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x64, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x65, 2, 3, Mnemonic::ADC, AddressingMode::zpg},
        Instruction{0x66, 2, 5, Mnemonic::ROR, AddressingMode::zpg},
        Instruction{0x67, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x68, 1, 4, Mnemonic::PLA, AddressingMode::impl},
        Instruction{0x69, 2, 2, Mnemonic::ADC, AddressingMode::imm},
        Instruction{0x6A, 1, 2, Mnemonic::ROR, AddressingMode::A},
        Instruction{0x6B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x6C, 3, 5, Mnemonic::JMP, AddressingMode::ind},
        Instruction{0x6D, 3, 4, Mnemonic::ADC, AddressingMode::abs},
        Instruction{0x6E, 3, 6, Mnemonic::ROR, AddressingMode::abs},
        Instruction{0x6F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x70, 2, 2, Mnemonic::BVS, AddressingMode::rel},
        Instruction{0x71, 2, 5, Mnemonic::ADC, AddressingMode::indY},
        Instruction{0x72, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x73, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x74, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x75, 2, 4, Mnemonic::ADC, AddressingMode::zpgX},
        Instruction{0x76, 2, 6, Mnemonic::ROR, AddressingMode::zpgX},
        Instruction{0x77, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x78, 1, 2, Mnemonic::SEI, AddressingMode::impl},
        Instruction{0x79, 3, 4, Mnemonic::ADC, AddressingMode::absY},
        Instruction{0x7A, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x7B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x7C, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x7D, 3, 4, Mnemonic::ADC, AddressingMode::absX},
        Instruction{0x7E, 3, 7, Mnemonic::ROR, AddressingMode::absX},
        Instruction{0x7F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x80, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x81, 2, 6, Mnemonic::STA, AddressingMode::Xind},
        Instruction{0x82, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x83, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x84, 2, 3, Mnemonic::STY, AddressingMode::zpg},
        Instruction{0x85, 2, 3, Mnemonic::STA, AddressingMode::zpg},
        Instruction{0x86, 2, 3, Mnemonic::STX, AddressingMode::zpg},
        Instruction{0x87, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x88, 1, 2, Mnemonic::DEY, AddressingMode::impl},
        Instruction{0x89, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x8A, 1, 2, Mnemonic::TXA, AddressingMode::impl},
        Instruction{0x8B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x8C, 3, 4, Mnemonic::STY, AddressingMode::abs},
        Instruction{0x8D, 3, 4, Mnemonic::STA, AddressingMode::abs},
        Instruction{0x8E, 3, 4, Mnemonic::STX, AddressingMode::abs},
        Instruction{0x8F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0x90, 2, 2, Mnemonic::BCC, AddressingMode::rel},
        Instruction{0x91, 2, 6, Mnemonic::STA, AddressingMode::indY},
        Instruction{0x92, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x93, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x94, 2, 4, Mnemonic::STY, AddressingMode::zpgX},
        Instruction{0x95, 2, 4, Mnemonic::STA, AddressingMode::zpgX},
        Instruction{0x96, 2, 4, Mnemonic::STX, AddressingMode::zpgY},
        Instruction{0x97, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x98, 1, 2, Mnemonic::TYA, AddressingMode::impl},
        Instruction{0x99, 3, 5, Mnemonic::STA, AddressingMode::absY},
        Instruction{0x9A, 1, 2, Mnemonic::TXS, AddressingMode::impl},
        Instruction{0x9B, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x9C, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x9D, 3, 5, Mnemonic::STA, AddressingMode::absX},
        Instruction{0x9E, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0x9F, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0xA0, 2, 2, Mnemonic::LDY, AddressingMode::imm},
        Instruction{0xA1, 2, 6, Mnemonic::LDA, AddressingMode::Xind},
        Instruction{0xA2, 2, 2, Mnemonic::LDX, AddressingMode::imm},
        Instruction{0xA3, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xA4, 2, 3, Mnemonic::LDY, AddressingMode::zpg},
        Instruction{0xA5, 2, 3, Mnemonic::LDA, AddressingMode::zpg},
        Instruction{0xA6, 2, 3, Mnemonic::LDX, AddressingMode::zpg},
        Instruction{0xA7, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xA8, 1, 2, Mnemonic::TAY, AddressingMode::impl},
        Instruction{0xA9, 2, 2, Mnemonic::LDA, AddressingMode::imm},
        Instruction{0xAA, 1, 2, Mnemonic::TAX, AddressingMode::impl},
        Instruction{0xAB, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xAC, 3, 4, Mnemonic::LDY, AddressingMode::abs},
        Instruction{0xAD, 3, 4, Mnemonic::LDA, AddressingMode::abs},
        Instruction{0xAE, 3, 4, Mnemonic::LDX, AddressingMode::abs},
        Instruction{0xAF, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0xB0, 2, 2, Mnemonic::BCS, AddressingMode::rel},
        Instruction{0xB1, 2, 5, Mnemonic::LDA, AddressingMode::indY},
        Instruction{0xB2, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xB3, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xB4, 2, 4, Mnemonic::LDY, AddressingMode::zpgX},
        Instruction{0xB5, 2, 4, Mnemonic::LDA, AddressingMode::zpgX},
        Instruction{0xB6, 2, 4, Mnemonic::LDX, AddressingMode::zpgY},
        Instruction{0xB7, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xB8, 1, 2, Mnemonic::CLV, AddressingMode::impl},
        Instruction{0xB9, 3, 4, Mnemonic::LDA, AddressingMode::absY},
        Instruction{0xBA, 1, 2, Mnemonic::TSX, AddressingMode::impl},
        Instruction{0xBB, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xBC, 3, 4, Mnemonic::LDY, AddressingMode::absX},
        Instruction{0xBD, 3, 4, Mnemonic::LDA, AddressingMode::absX},
        Instruction{0xBE, 3, 4, Mnemonic::LDX, AddressingMode::absY},
        Instruction{0xBF, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0xC0, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC1, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC2, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC3, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC4, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC5, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC6, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC7, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC8, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xC9, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xCA, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xCB, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xCC, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xCD, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xCE, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xCF, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0xD0, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD1, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD2, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD3, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD4, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD5, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD6, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD7, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD8, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xD9, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xDA, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xDB, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xDC, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xDD, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xDE, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xDF, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0xE0, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE1, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE2, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE3, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE4, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE5, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE6, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE7, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE8, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xE9, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xEA, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xEB, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xEC, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xED, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xEE, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xEF, 0, 0, Mnemonic::none, AddressingMode::none},

        Instruction{0xF0, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF1, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF2, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF3, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF4, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF5, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF6, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF7, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF8, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xF9, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xFA, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xFB, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xFC, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xFD, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xFE, 0, 0, Mnemonic::none, AddressingMode::none},
        Instruction{0xFF, 0, 0, Mnemonic::none, AddressingMode::none}
    };

    inline std::string to_string(Mnemonic m)
    {
        switch (m)
        {
            case Mnemonic::ADC: return "ADC";
            case Mnemonic::AND: return "AND";
            case Mnemonic::ASL: return "ASL";
            case Mnemonic::BCC: return "BCC";
            case Mnemonic::BCS: return "BCS";
            case Mnemonic::BEQ: return "BEQ";
            case Mnemonic::BIT: return "BIT";
            case Mnemonic::BMI: return "BMI";
            case Mnemonic::BNE: return "BNE";
            case Mnemonic::BPL: return "BPL";
            case Mnemonic::BRK: return "BRK";
            case Mnemonic::BVC: return "BVC";
            case Mnemonic::BVS: return "BVS";
            case Mnemonic::CLC: return "CLC";
            case Mnemonic::CLD: return "CLD";
            case Mnemonic::CLI: return "CLI";
            case Mnemonic::CLV: return "CLV";
            case Mnemonic::CMP: return "CMP";
            case Mnemonic::CPX: return "CPX";
            case Mnemonic::CPY: return "CPY";
            case Mnemonic::DEC: return "DEC";
            case Mnemonic::DEX: return "DEX";
            case Mnemonic::DEY: return "DEY";
            case Mnemonic::EOR: return "EOR";
            case Mnemonic::INC: return "INC";
            case Mnemonic::INX: return "INX";
            case Mnemonic::INY: return "INY";
            case Mnemonic::JMP: return "JMP";
            case Mnemonic::JSR: return "JSR";
            case Mnemonic::LDA: return "LDA";
            case Mnemonic::LDX: return "LDX";
            case Mnemonic::LDY: return "LDY";
            case Mnemonic::LSR: return "LSR";
            case Mnemonic::NOP: return "NOP";
            case Mnemonic::ORA: return "ORA";
            case Mnemonic::PHA: return "PHA";
            case Mnemonic::PHP: return "PHP";
            case Mnemonic::PLA: return "PLA";
            case Mnemonic::PLP: return "PLP";
            case Mnemonic::ROL: return "ROL";
            case Mnemonic::ROR: return "ROR";
            case Mnemonic::RTI: return "RTI";
            case Mnemonic::RTS: return "RTS";
            case Mnemonic::SBC: return "SBC";
            case Mnemonic::SEC: return "SEC";
            case Mnemonic::SED: return "SED";
            case Mnemonic::SEI: return "SEI";
            case Mnemonic::STA: return "STA";
            case Mnemonic::STX: return "STX";
            case Mnemonic::STY: return "STY";
            case Mnemonic::TAX: return "TAX";
            case Mnemonic::TAY: return "TAY";
            case Mnemonic::TSX: return "TSX";
            case Mnemonic::TXA: return "TXA";
            case Mnemonic::TXS: return "TXS";
            case Mnemonic::TYA: return "TYA";
            case Mnemonic::none: return "none";
            default: return "INVALID";
        }
    }

    inline std::string to_string(AddressingMode mode)
    {
        switch (mode)
            {
            case AddressingMode::A:     return "A";
            case AddressingMode::abs:   return "abs";
            case AddressingMode::absX:  return "abs,X";
            case AddressingMode::absY:  return "abs,Y";
            case AddressingMode::imm:   return "#imm";
            case AddressingMode::impl:  return "impl";
            case AddressingMode::ind:   return "(ind)";
            case AddressingMode::Xind:  return "(X,ind)";
            case AddressingMode::indY:  return "(ind),Y";
            case AddressingMode::rel:   return "rel";
            case AddressingMode::zpg:   return "zpg";
            case AddressingMode::zpgX:  return "zpg,X";
            case AddressingMode::zpgY:  return "zpg,Y";
            case AddressingMode::none:  return "none";
            default:                    return "INVALID";
        }
    }

}
