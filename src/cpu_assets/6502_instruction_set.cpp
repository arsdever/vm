#include "6502_instruction_set.h"
#include "cpu6502.h"

namespace vm
{
    void InstructionSetFor6502::initMapping(AbstractCPU &cpu)
    {
        CPU6502 &rcpu = static_cast<CPU6502 &>(cpu);
        __instruction_set.insert({ 0x00, (executor_t&)rcpu.BRK_impl });
        __instruction_set.insert({ 0x10, (executor_t&)rcpu.BPL_impl });
    }

    std::unordered_map<int, AbstractInstructionSet::executor_t&> const& InstructionSetFor6502::getInstructionMapping() const { return __instruction_set; }
}