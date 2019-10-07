#include "cpu6502.h"
#include "ram.h"
#include "../exceptions/instruction_not_found_ex.h"

#ifdef DEBUGGING
#include <sstream>
#include <bitset>
#endif

namespace vm
{
    CPU6502::CPU6502(RAM *ram)
        : AbstractCPU(ram)
        , __instruction_set(new InstructionSetFor6502())
        , __program_counter(0)
        , __accumulator(0)
        , __x_register(0)
        , __y_register(0)
        , __flags(0)
        , __stack_pointer(0)
    {
        __instruction_set->initMapping(*this);
    }

    bool CPU6502::isRunning() const
    {
        return !(__flags & B_FLAG);
    }

    std::string CPU6502::disassemble() const
    {
        AbstractInstructionSet::instruction_mapping_t const &mapping = getInstructionSet()->getInstructionMapping();
        uint8_t const &opcode = __ram->operator[](__program_counter);
        AbstractInstructionSet::instruction_mapping_t::const_iterator exec_iterator = mapping.find(opcode);
        if(exec_iterator == mapping.cend())
            throw InstructionNotFound();

        exec_iterator->second.fetch(__program_counter, __ram);
        return exec_iterator->second.disassemble();
    }

    void* CPU6502::getInstructionRegister() const
    {
        return (void*)&(*__ram)[__program_counter];
    }

    void* CPU6502::getProgramCounter() const
    {
        return (void*)&__program_counter;
    }

    void* CPU6502::getRegister(unsigned char reg_number) const
    {
        switch(reg_number)
        {
            case 0: return (void*)(&__accumulator);
            case 1: return (void*)(&__x_register);
            case 2: return (void*)(&__y_register);
            case 3: return (void*)(&__flags);
            case 4: return (void*)(&__stack_pointer);
            default: return nullptr;
        }
    }

    bool CPU6502::start(bool debug)
    {
        if(isRunning())
            return false;

        unsetFlags(B_FLAG);
        __is_running = true;
        __debug_mode = debug;
        return true;
    }

    void CPU6502::tick()
    {
        if(!isRunning())
            return;

        fetch();
        decode();
        execute();
    }

    void CPU6502::fetch()
    {
        AbstractInstructionSet::instruction_mapping_t const &mapping = getInstructionSet()->getInstructionMapping();
        uint8_t const &opcode = __ram->operator[](__program_counter);
        AbstractInstructionSet::instruction_mapping_t::const_iterator exec_iterator = mapping.find(opcode);
        if(exec_iterator == mapping.cend())
            throw InstructionNotFound();

        __executor = &exec_iterator->second;
        __executor->fetch(__program_counter, __ram);
    }

    AbstractInstructionSet* CPU6502::getInstructionSet() const
    {
        return __instruction_set;
    }

    void CPU6502::decode()
    {
        __program_counter += __executor->instructionSize();
    }

    void CPU6502::execute()
    {
        __executor->execute();
    }

#ifdef DEBUGGING
    std::string CPU6502::dump() const
    {
        std::stringstream dump_stm;
        dump_stm << "-[ INFO ]- Dumping 6502 processor state" << std::endl;
        dump_stm << "Program counter:   " << std::bitset<16>(__program_counter ) << std::endl;
        dump_stm << "Accumulator:       " << std::bitset<8>(*(uint8_t*)getRegister(0)) << std::endl;
        dump_stm << "X register:        " << std::bitset<8>(*(uint8_t*)getRegister(1)) << std::endl;
        dump_stm << "Y register:        " << std::bitset<8>(*(uint8_t*)getRegister(2)) << std::endl;
        dump_stm << "Flag register:     " << std::bitset<8>(*(uint8_t*)getRegister(3)) << std::endl;
        dump_stm << "Stack pointer:     " << std::bitset<8>(*(uint8_t*)getRegister(4)) << std::endl;
        dump_stm << "-[ INFO ]- Processor state dumping completed" << std::endl;
        return dump_stm.str();
    }
#endif
}