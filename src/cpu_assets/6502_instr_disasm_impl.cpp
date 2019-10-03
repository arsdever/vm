#include "cpu6502.h"

namespace vm
{
    // Instruction set disassembly implementation --- BEGIN

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BRK)
    {
        return "brk";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BPL)
    {
        return "bpl";
    }

    // Instruction set disassembly implementation --- END
}