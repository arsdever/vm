#include <iostream>

#include "../src/cpu_assets/cpu_model.h"
#include "../src/cpu_assets/ram.h"

int main()
{
    vm::RAM ram(0x7fff);
    ram[0] = 0;
    ram[1] = 1;
    ram[2] = 2;
    ram[3] = 3;
    ram[4] = 4;
    vm::CPUModel cpu(&ram);
    cpu.start();
    cpu.tick();
    cpu.tick();
    return 0;
}