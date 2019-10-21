#include <fstream>
#include <iostream>

#include <cpu_assets/6502/6502.h>
#include <cpu_assets/ram.h>

#include <assert.h>

int main()
{
    vm::RAM ram(0x7fff);
    vm::CPU6502 cpu(&ram);
    std::ifstream ramfile;
    ramfile.open("ram_model.ram", std::ios::binary | std::ios::in);
    if(!ramfile.is_open())
    {
        std::cerr << "Cannot load RAM model: Cannot open file ram_model.ram." << std::endl;
        return 1;
    }
    
    int i = 0;
    while(!ramfile.eof())
    {
        if(i >= 0x8000)
        {
            std::cerr << "Cannot load RAM model: Model size is bigger than the RAM is." << std::endl;
            return 1;            
        }
        ramfile >> ram[i++];
    }

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