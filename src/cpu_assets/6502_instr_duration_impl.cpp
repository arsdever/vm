#include "cpu6502.h"

namespace vm
{
    DEFINE_INSTRUCTION_DURATION(CPU6502, BRK)
    {
        return 7;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BPL)
    {
        return 2;
    }
}