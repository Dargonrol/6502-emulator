#pragma once

#include <array>
#include <cstdint>
#include <cstdlib>

namespace _6502 {

    using Byte = std::uint8_t;
    using Word = std::uint16_t;

    struct Memory64k
    {
    public:
        Memory64k();

        std::array<Byte, 0x10000> data_{};
    };

    struct Register8
    {
    public:
        Byte read() const;
        void write(Byte data);

        void reset();

    private:
        Byte data_ = rand() % 0xFF;
    };

    struct Register16
    {
    public:
        Word read() const;
        void write(Word data);

        void reset();

    private:
        Word data_ = rand() % 0xFFFF;
    };
}