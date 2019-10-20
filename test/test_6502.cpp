#include <iostream>

#include <cpu_assets/6502/6502.h>
#include <cpu_assets/ram.h>

#include <assert.h>

int main()
{
    vm::RAM ram(0x7fff);
    vm::CPU6502 cpu(&ram);
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
    int clocks = 0;
    while(cpu.isRunning())
    {
        std::cout << cpu.disassemble() << std::endl;
        int skip = cpu.tick();
        std::cout << "Expression takes " << skip << " clocks. Skipping" << std::flush;
        while (skip > 0)
        {
            ++clocks;
            std::cout << ' ' << skip << std::flush;
            skip = cpu.tick();
        }
        std::cout << std::endl << cpu.dump() << std::endl;
        std::cout << "--- CLOCK TICKS " << clocks << " ---" << std::endl;
    }
       
    return 0;
}