#include <iostream>
#include <ctime> // only to generate random values

#include "CPU.h"

int main() 
{
    srand(time(nullptr));
    std::cout << "Hello World";

    CPU cpu;

    return 0;
}
