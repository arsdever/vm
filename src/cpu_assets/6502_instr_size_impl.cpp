#include "cpu6502.h"

namespace vm
{
    DEFINE_INSTRUCTION_SIZE(CPU6502, BRK)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BPL)
    {
        return 2;
    }
}