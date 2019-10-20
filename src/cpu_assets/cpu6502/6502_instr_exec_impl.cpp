#include "cpu6502.h"
#include <cpu_assets/ram.h>

namespace vm
{
    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ADC)
    {
        int8_t value;
        switch (opcode())
        {
        case 0x69: value = (int8_t)operand(); break;
        case 0x65: value = __cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0x75: value = __cpu->__ram->operator[]<int8_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x6d: value = __cpu->__ram->operator[]<int8_t>(operand16()); break;
        case 0x7d: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__x_register); break;
        case 0x79: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__y_register); break;
        case 0x61: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->readDataLSB<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0x71: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->readDataLSB<uint16_t>(operand()) + __cpu->__y_register); break;
        default:
            break;
        }
        int16_t result = (int16_t)__cpu->__accumulator + value + bool(__cpu->__flags & Z_FLAG);
        if(result == 0)
            __cpu->setFlags(Z_FLAG);
        else
            __cpu->unsetFlags(Z_FLAG);

        if(result & 0x0100)
            __cpu->setFlags(C_FLAG);
        else
            __cpu->unsetFlags(C_FLAG);

        if(result & 0x80)
            __cpu->setFlags(N_FLAG);
        else
            __cpu->unsetFlags(N_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, AND)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ASL)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BCC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BCS)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BEQ)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BIT)
    {
        uint8_t value;
        switch (opcode())
        {
        case 0x24: value = __cpu->__ram->operator[](operand()); break;
        case 0x2c: value = __cpu->__ram->operator[](operand16()); break;
        default:
            break;
        }
        __cpu->setFlags(N_FLAG, value & 0x80);
        __cpu->setFlags(V_FLAG, value & 0x40);
        __cpu->setFlags(Z_FLAG, value & __cpu->__accumulator);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BMI)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BNE)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BPL)
    {
        __cpu->__is_running = false;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BRK)
    {
        int16_t pc_incremented = __cpu->__program_counter + 1;
        __cpu->push<uint16_t>(pc_incremented);
        __cpu->push<uint8_t>(__cpu->__flags);
        __cpu->setFlags(B_FLAG);
        __cpu->setFlags(I_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BVC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BVS)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLD)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLI)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLV)
    {
        __cpu->setFlags(V_FLAG, false);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CMP)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CPX)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CPY)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, DEC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, DEX)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, DEY)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, EOR)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, INC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, INX)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, INY)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, JMP)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, JSR)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LDA)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LDX)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LDY)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LSR)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, NOP)
    {
        return;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ORA)
    {
        uint8_t value;
        switch (opcode())
        {
        case 0x09: value = operand(); break;
        case 0x05: value = __cpu->__ram->operator[](operand()); break;
        case 0x15: value = __cpu->__ram->operator[](((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x0d: value = __cpu->__ram->operator[](operand16()); break;
        case 0x1d: value = __cpu->__ram->operator[](operand16() + __cpu->__x_register); break;
        case 0x19: value = __cpu->__ram->operator[](operand16() + __cpu->__y_register); break;
        case 0x01: value = __cpu->__ram->operator[](__cpu->__ram->readDataLSB<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0x11: value = __cpu->__ram->operator[](__cpu->__ram->readDataLSB<uint16_t>(operand()) + __cpu->__y_register); break;
        default:
            break;
        }
        __cpu->__accumulator |= value;
        if((int8_t)__cpu->__accumulator == 0)
            __cpu->setFlags(Z_FLAG & ~N_FLAG);
        else if((int8_t)__cpu->__accumulator < 0)
            __cpu->setFlags(~Z_FLAG & N_FLAG);
        else
            __cpu->unsetFlags(Z_FLAG | N_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, PHA)
    {
        __cpu->__ram->operator[](__cpu->__stack_pointer) = __cpu->__accumulator;
        __cpu->__stack_pointer -= 1;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, PHP)
    {
        __cpu->__ram->operator[](__cpu->__stack_pointer) = __cpu->__flags;
        __cpu->__stack_pointer -= 1;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, PLA)
    {
        __cpu->__accumulator = __cpu->__ram->operator[](__cpu->__stack_pointer);
        __cpu->__stack_pointer += 1;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, PLP)
    {
        __cpu->__flags = __cpu->__ram->operator[](__cpu->__stack_pointer);
        __cpu->__stack_pointer += 1;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ROL)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ROR)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, RTI)
    {
        __cpu->__flags = __cpu->pop<uint8_t>();
        __cpu->__program_counter = __cpu->pop<uint16_t>();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, RTS)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SEC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SED)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SEI)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, STA)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, STX)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, STY)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TAX)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TAY)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TSX)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TXA)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TXS)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TYA)
    {

    }
}