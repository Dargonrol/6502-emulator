#include "memory.h"

Memory64k::Memory64k()
{
    for (Byte byte : data_)
    {
        byte = rand() % 0xFF;
    }
}



Byte Register8::read() const
{
    return data_;
}

void Register8::write(const Byte data)
{
    data_ = data;
}

void Register8::reset()
{
    data_ = 0x00;
}

Word Register16::read() const
{
    return data_;
}

void Register16::write(Word data)
{
    data_ = data:
}

void Register16::reset()
{
    data_ = 0x0000;
}
