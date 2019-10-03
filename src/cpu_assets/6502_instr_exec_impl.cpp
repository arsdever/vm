#include "cpu6502.h"

namespace vm
{
    // Instruction set executors implementation --- BEGIN

    DEFINE_INSTRUCTION_EXECUTOR(CPU6502, BRK)
    {
        __cpu->setFlags(B_FLAG);
    }

    DEFINE_INSTRUCTION_EXECUTOR(CPU6502, BPL)
    {
        __cpu->__is_running = false;
    }

    // Instruction set executors implementation --- END
}