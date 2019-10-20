#pragma once

#include <cpu_assets/abstract_instruction_set.h>

namespace vm
{
    class InstructionSetFor6502 : public AbstractInstructionSet
    {
    public:
        InstructionSetFor6502() {}
        void initMapping(AbstractCPU &cpu) override;
        std::unordered_map<int, executor_t&> const& getInstructionMapping() const override;

    public:
        std::unordered_map<int, executor_t&> __instruction_set;
    };
}