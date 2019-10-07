#include "cpu6502.h"
#include "ram.h"

namespace vm
{
    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ADC)
    {
        
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
        __cpu->__stack.push(uint8_t(pc_incremented & 0xff));
        __cpu->__stack.push(uint8_t(pc_incremented >> 8 & 0xff));
        __cpu->__stack.push(__cpu->__flags);
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