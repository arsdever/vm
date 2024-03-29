#include "6502.h"
#include <assert.h>

namespace vm
{
    DEFINE_INSTRUCTION_DURATION(CPU6502, ADC)
    {
        
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, AND)
    {
        switch (opcode())
        {
            case 0x29: return 2;
            case 0x25: return 3;
            case 0x35:
            case 0x2d:
            case 0x3d:
            case 0x39: return 4;
            case 0x21: return 6;
            case 0x31: return 5;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, ASL)
    {
        switch (opcode())
        {
            case 0x0a: return 2;
            case 0x06: return 5;
            case 0x16:
            case 0x0e: return 6;
            case 0x1e: return 7;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BCC)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BCS)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BEQ)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BIT)
    {
        switch (opcode())
        {
        case 0x24: return 3;
        case 0x2c: return 4;
        default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BMI)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BNE)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BPL)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BRK)
    {
        return 7;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BVC)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BVS)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLC)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLD)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLI)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLV)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CMP)
    {
        switch (opcode())
        {
            case 0xc9: return 2;
            case 0xc5: return 3;
            case 0xd5:
            case 0xcd:
            case 0xdd:
            case 0xd9: return 4;
            case 0xc1: return 6;
            case 0xd1: return 5;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CPX)
    {
        switch (opcode())
        {
            case 0xe0: return 2;
            case 0xe4: return 3;
            case 0xec: return 4;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CPY)
    {
        switch (opcode())
        {
            case 0xc0: return 2;
            case 0xc4: return 3;
            case 0xcc: return 4;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, DEC)
    {
        switch (opcode())
        {
            case 0xc6:
            case 0xd6: return 2;
            case 0xce:
            case 0xde: return 3;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, DEX)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, DEY)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, EOR)
    {
        switch (opcode())
        {
            case 0x49: return 2;
            case 0x45: return 3;
            case 0x55:
            case 0x4d:
            case 0x5d:
            case 0x59: return 4;
            case 0x41: return 6;
            case 0x51: return 5;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, INC)
    {
        switch (opcode())
        {
            case 0xe6:
            case 0xf6: return 2;
            case 0xee:
            case 0xfe: return 3;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, INX)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, INY)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, JMP)
    {
        switch (opcode())
        {
            case 0x4c: return 3;
            case 0x6c: return 5;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, JSR)
    {
        return 6;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LDA)
    {
        switch (opcode())
        {
            case 0xa9: return 2;
            case 0xa5: return 3;
            case 0xb5:
            case 0xad:
            case 0xbd:
            case 0xb9: return 4;
            case 0xa1: return 6;
            case 0xb1: return 5;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LDX)
    {
        switch (opcode())
        {
            case 0xa2: return 2;
            case 0xa6: return 3;
            case 0xb6:
            case 0xae:
            case 0xbe: return 4;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LDY)
    {
        switch (opcode())
        {
            case 0xa0: return 2;
            case 0xa4: return 3;
            case 0xb4:
            case 0xac:
            case 0xbc: return 4;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LSR)
    {
        switch (opcode())
        {
            case 0x4a: return 2;
            case 0x46: return 5;
            case 0x56:
            case 0x4e: return 6;
            case 0x5e: return 7;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, NOP)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, ORA)
    {
        switch (opcode())
        {
            case 0x09: return 2;
            case 0x05: return 3;
            case 0x15:
            case 0x0d:
            case 0x1d:
            case 0x19: return 4;
            case 0x01: return 6;
            case 0x11: return 5;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, PHA)
    {
        return 3;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, PHP)
    {
        return 3;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, PLA)
    {
        return 4;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, PLP)
    {
        return 4;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, ROL)
    {
        switch (opcode())
        {
            case 0x2a: return 2;
            case 0x26: return 5;
            case 0x36:
            case 0x2e: return 6;
            case 0x3e: return 7;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, ROR)
    {
        switch (opcode())
        {
            case 0x6a: return 2;
            case 0x66: return 5;
            case 0x76:
            case 0x6e: return 6;
            case 0x7e: return 7;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, RTI)
    {
        return 6;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, RTS)
    {
        return 6;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SEC)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SED)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SEI)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, STA)
    {
        switch (opcode())
        {
            case 0x85: return 3;
            case 0x95:
            case 0x8d: return 4;
            case 0x9d:
            case 0x99: return 5;
            case 0x81:
            case 0x91: return 6;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, STX)
    {
        switch (opcode())
        {
            case 0x86: return 3;
            case 0x96:
            case 0x8e: return 4;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, STY)
    {
        switch (opcode())
        {
            case 0x84: return 3;
            case 0x94:
            case 0x8c: return 4;
            default: assert("Mustn't reach the statement");
        }
        return 0;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TAX)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TAY)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TSX)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TXA)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TXS)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TYA)
    {
        return 2;
    }
}