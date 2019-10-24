#include "6502.h"
#include <assert.h>

namespace vm
{
    DEFINE_INSTRUCTION_SIZE(CPU6502, ADC)
    {
        
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, AND)
    {
        switch (opcode())
        {
            case 0x29:
            case 0x25:
            case 0x35: return 2;
            case 0x2d:
            case 0x3d:
            case 0x39: return 3;
            case 0x21:
            case 0x31: return 2;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, ASL)
    {
        switch (opcode())
        {
            case 0x0a: return 1;
            case 0x06:
            case 0x16: return 2;
            case 0x0e:
            case 0x1e: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BCC)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BCS)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BEQ)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BIT)
    {
        switch (opcode())
        {
        case 0x24: return 2;
        case 0x2c: return 3;
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BMI)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BNE)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BPL)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BRK)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BVC)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, BVS)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, CLC)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, CLD)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, CLI)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, CLV)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, CMP)
    {
        switch (opcode())
        {
            case 0xc9:
            case 0xc5:
            case 0xd5: return 2;
            case 0xcd:
            case 0xdd:
            case 0xd9: return 3;
            case 0xc1:
            case 0xd1: return 2;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, CPX)
    {
        switch (opcode())
        {
            case 0xe0:
            case 0xe4: return 2;
            case 0xec: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, CPY)
    {
        switch (opcode())
        {
            case 0xc0:
            case 0xc4: return 2;
            case 0xcc: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, DEC)
    {
        switch (opcode())
        {
            case 0xc6: return 5;
            case 0xd6: return 6;
            case 0xce: return 6;
            case 0xde: return 7;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, DEX)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, DEY)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, EOR)
    {
        switch (opcode())
        {
            case 0x49:
            case 0x45:
            case 0x55:
            case 0x41:
            case 0x51: return 2;
            case 0x4d:
            case 0x5d:
            case 0x59: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, INC)
    {
        switch (opcode())
        {
            case 0xe6: return 5;
            case 0xf6: return 6;
            case 0xee: return 6;
            case 0xfe: return 7;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, INX)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, INY)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, JMP)
    {
        return 3;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, JSR)
    {
        return 3;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, LDA)
    {
        switch (opcode())
        {
            case 0xa9:
            case 0xa5:
            case 0xb5: return 2;
            case 0xad:
            case 0xbd:
            case 0xb9: return 3;
            case 0xa1:
            case 0xb1: return 2;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, LDX)
    {
        switch (opcode())
        {
            case 0xa2:
            case 0xa6:
            case 0xb6: return 2;
            case 0xae:
            case 0xbe: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, LDY)
    {
        switch (opcode())
        {
            case 0xa0:
            case 0xa4:
            case 0xb4: return 2;
            case 0xac:
            case 0xbc: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, LSR)
    {
        switch (opcode())
        {
            case 0x4a: return 1;
            case 0x46:
            case 0x56: return 2;
            case 0x4e:
            case 0x5e: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, NOP)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, ORA)
    {
        switch (opcode())
        {
            case 0x09:
            case 0x05:
            case 0x15:
            case 0x01:
            case 0x11: return 2;
            case 0x0d:
            case 0x1d:
            case 0x19: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, PHA)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, PHP)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, PLA)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, PLP)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, ROL)
    {
        switch (opcode())
        {
            case 0x2a: return 1;
            case 0x26:
            case 0x36: return 2;
            case 0x2e:
            case 0x3e: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, ROR)
    {
        switch (opcode())
        {
            case 0x6a: return 1;
            case 0x66:
            case 0x76: return 2;
            case 0x6e:
            case 0x7e: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, RTI)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, RTS)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SEC)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SED)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SEI)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, STA)
    {
        switch (opcode())
        {
            case 0x85:
            case 0x95: return 2;
            case 0x8d:
            case 0x9d:
            case 0x99: return 3;
            case 0x81:
            case 0x91: return 2;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, STX)
    {
        switch (opcode())
        {
            case 0x86:
            case 0x96: return 2;
            case 0x8e: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, STY)
    {
        switch (opcode())
        {
            case 0x84:
            case 0x94: return 2;
            case 0x8c: return 3;
            default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TAX)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TAY)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TSX)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TXA)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TXS)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TYA)
    {
        return 1;
    }
}