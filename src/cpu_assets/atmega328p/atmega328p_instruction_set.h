#pragma once

#include <cpu_assets/abstract_instruction_set.h>

namespace vm
{
    class InstructionSetForATmega328P : public AbstractInstructionSet
    {
    public:
        InstructionSetForATmega328P() {}
        void initMapping(AbstractCPU &cpu) override;
        std::unordered_map<int, executor_t&> const& getInstructionMapping() const override;

    public:
        std::unordered_map<int, executor_t&> __instruction_set;
    };
}