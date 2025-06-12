#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <ctime> // only to generate random values

using Byte = std::uint8_t;
using Word = std::uint16_t;

struct Register8
{
public:
    Byte read() const
    {
        return data_;
    }

    void write(const Byte data)
    {
        data_ = data;
    }

    void reset()
    {
        data_ = 0x00;
    }

private:
    Byte data_ = rand() % 0xFF;
};

struct Register16
{
public:
    Word read() const
    {
        return data_;
    }

    void write(const Word data)
    {
        data_ = data;
    }

    void reset()
    {
        data_ = 0x0000;
    }

private:
    Word data_ = rand() % 0xFFFF;
};

struct CPU 
{
    // Registers
    Register16 PC;  // program counter
    Register16 SP;  // stack pointer
    Register8 ACC;  // accumulator
    Register8 IX;   // index register x
    Register8 IY;   // index register y
    Register8 FLAGS;// processor status register (flags)


};


int main() 
{
    srand(time(nullptr));
    std::cout << "Hello World";
    return 0;
}
