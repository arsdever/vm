#include <iostream>

#include "../src/cpu_assets/cpu6502.h"
#include "../src/cpu_assets/ram.h"

#include <assert.h>

int main()
{
    vm::RAM ram(0x7fff);
    ram[0] = 0x00;
    ram[1] = 0x10;
    ram[2] = 0x00;
    ram[3] = 0x10;
    ram[4] = 0x00;
    ram[5] = 0x10;
    ram[6] = 0x00;
    ram[7] = 0x10;
    vm::CPU6502 cpu(&ram);
    cpu.start();
    std::cout << cpu.disassemble() << std::endl;
    cpu.tick();
    std::cout << cpu.dump() << std::endl;
    std::cout << cpu.disassemble() << std::endl;
    cpu.tick();
    std::cout << cpu.dump() << std::endl;
    cpu.start();
    std::cout << cpu.disassemble() << std::endl;
    cpu.tick();
    std::cout << cpu.dump() << std::endl;
    std::cout << cpu.disassemble() << std::endl;
    cpu.tick();
    std::cout << cpu.dump() << std::endl;
    cpu.start();
    std::cout << cpu.disassemble() << std::endl;
    cpu.tick();
    std::cout << cpu.dump() << std::endl;

    assert(cpu.getRegister(5) == nullptr);
    return 0;
}