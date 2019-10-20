#include "6502.h"

namespace vm
{
    DEFINE_INSTRUCTION_DURATION(CPU6502, ADC)
    {
        
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, AND)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, ASL)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BCC)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BCS)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BEQ)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BIT)
    {
        switch (opcode())
        {
        case 0x24: return 3;
        case 0x2c: return 4;
        default: return 1;
        }
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BMI)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BNE)
    {

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

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, BVS)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLC)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLD)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLI)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CLV)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CMP)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CPX)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, CPY)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, DEC)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, DEX)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, DEY)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, EOR)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, INC)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, INX)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, INY)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, JMP)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, JSR)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LDA)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LDX)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LDY)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, LSR)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, NOP)
    {
        return 2;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, ORA)
    {
        switch (opcode())
        {
            case 0x09:
                return 2;
            case 0x05:
                return 3;
            case 0x15:
            case 0x0d:
            case 0x1d:
            case 0x19:
                return 4;
            case 0x01:
                return 6;
            case 0x11:
                return 5;
            default:
                return 2;
        }
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

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, ROR)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, RTI)
    {
        return 6;
    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, RTS)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SEC)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SED)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, SEI)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, STA)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, STX)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, STY)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TAX)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TAY)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TSX)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TXA)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TXS)
    {

    }

    DEFINE_INSTRUCTION_DURATION(CPU6502, TYA)
    {

    }
}