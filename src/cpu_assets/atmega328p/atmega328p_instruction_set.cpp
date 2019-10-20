#include "atmega328p_instruction_set.h"
#include "atmega328p.h"

namespace vm
{
    void InstructionSetForATmega328P::initMapping(AbstractCPU &cpu)
    {
        ATmega328P &rcpu = static_cast<ATmega328P &>(cpu);
        AbstractInstructionSet::executor_t *exec;
        for(uint8_t i = 0; i < 255; ++i)
        {
            if(!i)
                exec = &rcpu.NOP_impl;
            else if(i == 0x01)
                exec = &rcpu.MOVW_impl;
            else if(i == 0x02)
                exec = &rcpu.MULS_impl;
            else if(i == 0x03)
            {

            }
            __instruction_set.insert({i, *exec});
        }
    }

    std::unordered_map<int, AbstractInstructionSet::executor_t&> const& InstructionSetForATmega328P::getInstructionMapping() const { return __instruction_set; }
}