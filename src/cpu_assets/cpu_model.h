#pragma once

#include "abstract_cpu.h"
#include "abstract_instruction_set.h"

namespace vm
{
    class CPUModel : public AbstractCPU
    {
    public:
        inline CPUModel(RAM *ram) : AbstractCPU(ram) {}

    protected:
        void decode() override;
        void execute() override;

    private:
        AbstractInstructionSet __instruction_set;
    };
}