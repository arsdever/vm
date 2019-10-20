#include <iostream>

#include "../src/cpu_assets/atmega328p/atmega328p.h"
#include "../src/cpu_assets/ram.h"

#include <assert.h>

int main()
{
    vm::RAM ram(0x7fff);
    vm::ATmega328P cpu(&ram);
    ram[0x00] = 0x09;
    ram[0x01] = 0xab;
    ram[0x02] = 0x05;
    ram[0x03] = 0x10;
    ram[0x04] = 0x0d;
    ram[0x05] = 0x11;
    ram[0x07] = 0xea;
    ram[0x06] = 0x00;
    ram[0x10] = 0xac;
    ram[0x11] = 0xad;
    cpu.start();
    std::cout << "Initial state" << std::endl;
    std::cout << cpu.dump() << std::endl;
    while(cpu.isRunning())
    {
        std::cout << cpu.disassemble() << std::endl;
        cpu.tick();
        std::cout << cpu.dump() << std::endl;
    }
       
    return 0;
}