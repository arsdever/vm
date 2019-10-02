#include "abstract_cpu.h"
#include "ram.h"
#include <sstream>

namespace vm
{
    AbstractCPU::AbstractCPU(RAM *ram)
        : __ram(ram)
        , __instruction_register(0)
        , __instruction_pointer(0)
        , __registers(new int[8])
        , __is_running(false)
        , __debug_mode(false)
    {}

    void AbstractCPU::setRam(RAM *ram)
    {
        __ram = ram;
    }

    RAM* AbstractCPU::ram() const
    {
        return __ram;
    }

    bool AbstractCPU::start(bool debug)
    {
        if(isRunning()) return false;

        __debug_mode = debug;
        __is_running = true;
        return true;
    }

    void AbstractCPU::tick()
    {
        if(__is_running)
        {
            fetch();
            decode();
            execute();
        }
    }

    std::string AbstractCPU::dump()
    {
        std::stringstream stm;
        stm << "--===== DUMPING CPU STATE =====--\n";
        stm << "Instruction pointer: " << __instruction_pointer << "\n";
        stm << "Instruction register: " << __instruction_register << "\n";
        stm << "Registers: R0: " << __registers[0] << "\n";
        stm << "Registers: R1: " << __registers[1] << "\n";
        stm << "Registers: R2: " << __registers[2] << "\n";
        stm << "Registers: R3: " << __registers[3] << "\n";
        stm << "Registers: R4: " << __registers[4] << "\n";
        stm << "Registers: R5: " << __registers[5] << "\n";
        stm << "Registers: R6: " << __registers[6] << "\n";
        stm << "Registers: R7: " << __registers[7] << "\n";
        stm << "--===== \\/\\/\\/\\/\\/\\/\\/\\/\\ =====--\n";
        return stm.str();
    }

    bool AbstractCPU::isRunning() const
    {
        return __is_running;
    }

    int& AbstractCPU::getInstructionRegister() { return __instruction_register; }

    int& AbstractCPU::getRegister(unsigned char reg_number) { return __registers[reg_number]; }

    void AbstractCPU::fetch()
    {
        __instruction_register = __ram->operator[](__instruction_pointer);
    }
}