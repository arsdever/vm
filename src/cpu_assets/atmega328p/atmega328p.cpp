#include "atmega328p.h"
#include "atmega328p_instruction_set.h"
#include <cpu_assets/ram.h>
#include <exceptions/instruction_not_found_ex.h>
#include "atmega328p_opts.h"

#ifdef DEBUGGING
#include <sstream>
#include <bitset>
#endif

namespace vm
{
    ATmega328P::ATmega328P(RAM *ram)
        : AbstractCPU(ram)
        , __instruction_set(new InstructionSetForATmega328P())
        , __program_counter(0)
        , __accumulator(0)
        , __x_register(0)
        , __y_register(0)
        , __flags(0)
        , __stack_pointer(0x01ff)
        , __skip_ticks(0)
    {
        __instruction_set->initMapping(*this);
    }

    bool ATmega328P::isRunning() const
    {
        return true;
    }

    std::string ATmega328P::disassemble() const
    {
        AbstractInstructionSet::instruction_mapping_t const &mapping = getInstructionSet()->getInstructionMapping();
        uint8_t const &opcode = __ram->operator[](__program_counter);
        AbstractInstructionSet::instruction_mapping_t::const_iterator exec_iterator = mapping.find(opcode);
        if(exec_iterator == mapping.cend())
            throw InstructionNotFound();

        exec_iterator->second.fetch(__program_counter, __ram);
        return exec_iterator->second.disassemble();
    }

    void* ATmega328P::getInstructionRegister() const
    {
        return (void*)&(*__ram)[__program_counter];
    }

    void* ATmega328P::getProgramCounter() const
    {
        return (void*)&__program_counter;
    }

    void* ATmega328P::getRegister(unsigned char reg_number) const
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

    bool ATmega328P::start(bool debug)
    {
        if(isRunning())
            return false;

        unsetFlags(I_FLAG);
        __is_running = true;
        __debug_mode = debug;
        __skip_ticks = 0;
        return true;
    }

    int ATmega328P::tick()
    {
        if(!isRunning())
            return 0;

        if(__skip_ticks--)
            return __skip_ticks;

        fetch();
        decode();
        execute();
        return __skip_ticks;
    }

    void ATmega328P::fetch()
    {
        AbstractInstructionSet::instruction_mapping_t const &mapping = getInstructionSet()->getInstructionMapping();
        uint8_t const &opcode = __ram->operator[](__program_counter);
        AbstractInstructionSet::instruction_mapping_t::const_iterator exec_iterator = mapping.find(opcode);
        if(exec_iterator == mapping.cend())
            throw InstructionNotFound();

        __executor = &exec_iterator->second;
        __executor->fetch(__program_counter, __ram);
    }

    AbstractInstructionSet* ATmega328P::getInstructionSet() const
    {
        return __instruction_set;
    }

    void ATmega328P::decode()
    {
        __program_counter += __executor->instructionSize();
    }

    void ATmega328P::execute()
    {
        __executor->execute();
        __skip_ticks += __executor->instructionDuration();
    }

    ATmega328P* ATmega328P::fromOptions(CPUOptions const &opts)
    {
        ATmega328POptions const &o = reinterpret_cast<ATmega328POptions const &>(opts);
        return new ATmega328P(new RAM(o.ram_size));
    }

#ifdef DEBUGGING
    std::string ATmega328P::dump() const
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