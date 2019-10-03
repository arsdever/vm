#include "abstract_cpu.h"
#include "ram.h"
#include "abstract_instruction_set.h"
#include "../exceptions/instruction_not_found_ex.h"

namespace vm
{
    AbstractCPU::AbstractCPU(RAM *ram)
        : __ram(ram)
        , __is_running(false)
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

    bool AbstractCPU::isRunning() const
    {
        return __is_running;
    }

    std::string AbstractCPU::disassemble() const
    {
        AbstractInstructionSet::instruction_mapping_t const &mapping = getInstructionSet()->getInstructionMapping();
        AbstractInstructionSet::instruction_mapping_t::const_iterator exec_iterator = mapping.find(*((int64_t*)getInstructionRegister()));
        if(exec_iterator == mapping.cend())
            throw InstructionNotFound();

        return exec_iterator->second.disassemble();
    }

    void AbstractCPU::fetch()
    {
        *((int*)getInstructionRegister()) = __ram->operator[](*((int*)getProgramCounter()));
    }

    void AbstractCPU::execute()
    {
        AbstractInstructionSet::instruction_mapping_t const &mapping = getInstructionSet()->getInstructionMapping();
        AbstractInstructionSet::instruction_mapping_t::const_iterator exec_iterator = mapping.find(*((int64_t*)getInstructionRegister()));
        if(exec_iterator == mapping.cend())
            throw InstructionNotFound();

        exec_iterator->second.execute();
    }
}