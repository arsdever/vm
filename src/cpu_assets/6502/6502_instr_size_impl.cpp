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

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, DEX)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, DEY)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, EOR)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, INC)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, INX)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, INY)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, JMP)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, JSR)
    {

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

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, ROR)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, RTI)
    {
        return 1;
    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, RTS)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SEC)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SED)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, SEI)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, STA)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, STX)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, STY)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TAX)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TAY)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TSX)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TXA)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TXS)
    {

    }

    DEFINE_INSTRUCTION_SIZE(CPU6502, TYA)
    {

    }
}