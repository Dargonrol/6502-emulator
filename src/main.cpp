#include <algorithm>
#include <iostream>
#include <ctime> // only to generate random values
#include <random>

#include "processor.h"

int main() 
{
    srand(time(nullptr));
    std::cout << "Welcome to the 6502 emulator <3";

    _6502::CPU cpu;

    return 0;
}
