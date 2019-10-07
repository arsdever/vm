#include <iostream>

#include "../src/cpu_assets/cpu6502.h"
#include "../src/cpu_assets/ram.h"

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
    while(cpu.isRunning())
    {
        std::cout << cpu.disassemble() << std::endl;
        cpu.tick();
        std::cout << cpu.dump() << std::endl;
    }
    
    if(!cpu.isRunning() && (*(uint8_t*)cpu.getRegister(3) & cpu.B_FLAG) && (*(uint8_t*)cpu.getRegister(3) & cpu.I_FLAG))
    {
        std::cout << "CPU finished the execution, because met BRK command." << std::endl;
        std::cout << "Test passed" << std::endl;
    }
    else
    {
        std::cout << "An unknown reason stopped the CPU" << std::endl;
        std::cout << "Test failed" << std::endl;
    }
       
    return 0;
}