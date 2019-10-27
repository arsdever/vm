#include "6502.h"
#include <cpu_assets/ram.h>
#include <assert.h>

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
        case 0x61: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0x71: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(operand()) + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        int16_t result = (int16_t)__cpu->__accumulator + value + bool(__cpu->__flags & Z_FLAG);
        __cpu->setFlags(Z_FLAG, !result);
        __cpu->setFlags(C_FLAG, result & 0x0100);
        __cpu->setFlags(N_FLAG, result & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, AND)
    {
        int8_t value;
        switch (opcode())
        {
        case 0x29: value = (int8_t)operand(); break;
        case 0x25: value = __cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0x35: value = __cpu->__ram->operator[]<int8_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x2d: value = __cpu->__ram->operator[]<int8_t>(operand16()); break;
        case 0x3d: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__x_register); break;
        case 0x39: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__y_register); break;
        case 0x21: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0x31: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(operand()) + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->__accumulator = (int16_t)__cpu->__accumulator & value;
        __cpu->setFlags(Z_FLAG, !__cpu->__accumulator);
        __cpu->setFlags(N_FLAG, __cpu->__accumulator & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ASL)
    {
        uint16_t address;
        switch (opcode())
        {
        case 0x0a:
            __cpu->setFlags(C_FLAG, __cpu->__accumulator & 0x80);
            __cpu->setFlags(Z_FLAG, !(__cpu->__accumulator <<= 1));
            __cpu->setFlags(N_FLAG, __cpu->__accumulator & 0x01);
            return;
        case 0x06: address = operand(); break;
        case 0x16: address = ((uint16_t)operand() + __cpu->__x_register) & 0xff; break;
        case 0x0e: address = operand16(); break;
        case 0x1e: address = operand16() + __cpu->__x_register; break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->setFlags(C_FLAG, __cpu->__ram->operator[](address) & 0x80);
        __cpu->setFlags(Z_FLAG, !(__cpu->__ram->operator[](address) <<= 1));
        __cpu->setFlags(N_FLAG, __cpu->__ram->operator[](address) & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BCC)
    {
        if(!(__cpu->__flags & CPU6502::C_FLAG))
            __cpu->__program_counter += (int8_t) operand();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BCS)
    {
        if(__cpu->__flags & CPU6502::C_FLAG)
            __cpu->__program_counter += (int8_t) operand();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BEQ)
    {
        if(__cpu->__flags & CPU6502::Z_FLAG)
            __cpu->__program_counter += (int8_t) operand();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BIT)
    {
        uint8_t value;
        switch (opcode())
        {
        case 0x24: value = __cpu->__ram->operator[](operand()); break;
        case 0x2c: value = __cpu->__ram->operator[](operand16()); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->setFlags(N_FLAG, value & 0x80);
        __cpu->setFlags(V_FLAG, value & 0x40);
        __cpu->setFlags(Z_FLAG, value & __cpu->__accumulator);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BMI)
    {
        if(__cpu->__flags & CPU6502::N_FLAG)
            __cpu->__program_counter += (int8_t) operand();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BNE)
    {
        if(!(__cpu->__flags & CPU6502::Z_FLAG))
            __cpu->__program_counter += (int8_t) operand();
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
        if(!(__cpu->__flags & CPU6502::V_FLAG))
            __cpu->__program_counter += (int8_t) operand();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, BVS)
    {
        if(__cpu->__flags & CPU6502::V_FLAG)
            __cpu->__program_counter += (int8_t) operand();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLC)
    {
        __cpu->unsetFlags(C_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLD)
    {
        __cpu->unsetFlags(D_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLI)
    {
        __cpu->unsetFlags(I_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CLV)
    {
        __cpu->setFlags(V_FLAG, false);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CMP)
    {
        int8_t value;
        switch (opcode())
        {
        case 0xc9: value = (int8_t)operand(); break;
        case 0xc5: value = __cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0xd5: value = __cpu->__ram->operator[]<int8_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0xcd: value = __cpu->__ram->operator[]<int8_t>(operand16()); break;
        case 0xdd: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__x_register); break;
        case 0xd9: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__y_register); break;
        case 0xc1: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0xd1: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(operand()) + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->setFlags(C_FLAG, __cpu->__accumulator >= value);
        __cpu->setFlags(Z_FLAG, __cpu->__accumulator == value);
        __cpu->setFlags(N_FLAG, __cpu->__accumulator < value);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CPX)
    {
        int8_t value;
        switch (opcode())
        {
        case 0xe0: value = (int8_t)operand(); break;
        case 0xe4: value = __cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0xec: value = __cpu->__ram->operator[]<int8_t>(operand16()); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->setFlags(C_FLAG, __cpu->__x_register >= value);
        __cpu->setFlags(Z_FLAG, __cpu->__x_register == value);
        __cpu->setFlags(N_FLAG, __cpu->__x_register < value);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, CPY)
    {
        int8_t value;
        switch (opcode())
        {
        case 0xc0: value = (int8_t)operand(); break;
        case 0xc4: value = __cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0xcc: value = __cpu->__ram->operator[]<int8_t>(operand16()); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->setFlags(C_FLAG, __cpu->__y_register >= value);
        __cpu->setFlags(Z_FLAG, __cpu->__y_register == value);
        __cpu->setFlags(N_FLAG, __cpu->__y_register < value);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, DEC)
    {
        int8_t* value;
        switch (opcode())
        {
        case 0xc6: value = &__cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0xd6: value = &__cpu->__ram->operator[]<int8_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0xce: value = &__cpu->__ram->operator[]<int8_t>(operand16()); break;
        case 0xde: value = &__cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__x_register); break;
        default: assert("Mustn't reach the statement");
        }
        --*value;
        __cpu->setFlags(Z_FLAG, !(*value));
        __cpu->setFlags(N_FLAG, *value & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, DEX)
    {
        --__cpu->__x_register;
        __cpu->setFlags(Z_FLAG, !__cpu->__x_register);
        __cpu->setFlags(N_FLAG, __cpu->__x_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, DEY)
    {
        --__cpu->__y_register;
        __cpu->setFlags(Z_FLAG, !__cpu->__y_register);
        __cpu->setFlags(N_FLAG, __cpu->__y_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, EOR)
    {
        int8_t value;
        switch (opcode())
        {
        case 0x49: value = (int8_t)operand(); break;
        case 0x45: value = __cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0x55: value = __cpu->__ram->operator[]<int8_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x4d: value = __cpu->__ram->operator[]<int8_t>(operand16()); break;
        case 0x5d: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__x_register); break;
        case 0x59: value = __cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__y_register); break;
        case 0x41: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0x51: value = __cpu->__ram->operator[]<int8_t>(__cpu->__ram->operator[]<uint16_t>(operand()) + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->__accumulator = (int16_t)__cpu->__accumulator ^ value;
        __cpu->setFlags(Z_FLAG, !__cpu->__accumulator);
        __cpu->setFlags(N_FLAG, __cpu->__accumulator & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, INC)
    {
        int8_t* value;
        switch (opcode())
        {
        case 0xe6: value = &__cpu->__ram->operator[]<int8_t>(operand()); break;
        case 0xf6: value = &__cpu->__ram->operator[]<int8_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0xee: value = &__cpu->__ram->operator[]<int8_t>(operand16()); break;
        case 0xfe: value = &__cpu->__ram->operator[]<int8_t>(operand16() + __cpu->__x_register); break;
        default: assert("Mustn't reach the statement");
        }
        ++*value;
        __cpu->setFlags(Z_FLAG, !(*value));
        __cpu->setFlags(N_FLAG, *value & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, INX)
    {
        ++__cpu->__x_register;
        __cpu->setFlags(Z_FLAG, !__cpu->__x_register);
        __cpu->setFlags(N_FLAG, __cpu->__x_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, INY)
    {
        ++__cpu->__y_register;
        __cpu->setFlags(Z_FLAG, !__cpu->__y_register);
        __cpu->setFlags(N_FLAG, __cpu->__y_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, JMP)
    {
        uint8_t address;
        switch (opcode())
        {
        case 0x4c: address = operand16(); break;
        case 0x6c: address = (__cpu->__ram->operator[](operand16()) << 8) | __cpu->__ram->operator[](operand16()); break;
        }
        __cpu->__program_counter = address;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, JSR)
    {
        uint8_t address;
        switch (opcode())
        {
        case 0x4c: address = operand16(); break;
        case 0x6c: address = (__cpu->__ram->operator[](operand16()) << 8) | __cpu->__ram->operator[](operand16()); break;
        }
        __cpu->push<uint16_t>(__cpu->__program_counter + 2);
        __cpu->__program_counter = address;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LDA)
    {
        uint8_t value;
        switch (opcode())
        {
        case 0xa9: value = operand(); break;
        case 0xa5: value = __cpu->__ram->operator[](operand()); break;
        case 0xb5: value = __cpu->__ram->operator[](((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0xad: value = __cpu->__ram->operator[](operand16()); break;
        case 0xbd: value = __cpu->__ram->operator[](operand16() + __cpu->__x_register); break;
        case 0xb9: value = __cpu->__ram->operator[](operand16() + __cpu->__y_register); break;
        case 0xa1: value = __cpu->__ram->operator[](__cpu->__ram->operator[]<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0xb1: value = __cpu->__ram->operator[](__cpu->__ram->operator[]<uint16_t>(operand()) + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->__accumulator = value;
        __cpu->setFlags(Z_FLAG, !__cpu->__accumulator);
        __cpu->setFlags(N_FLAG, __cpu->__accumulator & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LDX)
    {
        uint8_t value;
        switch (opcode())
        {
        case 0xa2: value = operand(); break;
        case 0xa6: value = __cpu->__ram->operator[](operand()); break;
        case 0xb6: value = __cpu->__ram->operator[](((uint16_t)operand() + __cpu->__y_register) & 0xff); break;
        case 0xae: value = __cpu->__ram->operator[](operand16()); break;
        case 0xbe: value = __cpu->__ram->operator[](operand16() + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->__x_register = value;
        __cpu->setFlags(Z_FLAG, !__cpu->__x_register);
        __cpu->setFlags(N_FLAG, __cpu->__x_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LDY)
    {
        uint8_t value;
        switch (opcode())
        {
        case 0xa0: value = operand(); break;
        case 0xa4: value = __cpu->__ram->operator[](operand()); break;
        case 0xb4: value = __cpu->__ram->operator[](((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0xac: value = __cpu->__ram->operator[](operand16()); break;
        case 0xbc: value = __cpu->__ram->operator[](operand16() + __cpu->__x_register); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->__y_register = value;
        __cpu->setFlags(Z_FLAG, !__cpu->__y_register);
        __cpu->setFlags(N_FLAG, __cpu->__y_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, LSR)
    {
        uint16_t address;
        switch (opcode())
        {
        case 0x4a:
            __cpu->setFlags(C_FLAG, __cpu->__accumulator & 0x01);
            __cpu->setFlags(Z_FLAG, !(__cpu->__accumulator >>= 1));
            __cpu->unsetFlags(N_FLAG);
            return;
        case 0xa4: address = operand(); break;
        case 0xb4: address = ((uint16_t)operand() + __cpu->__x_register) & 0xff; break;
        case 0xac: address = operand16(); break;
        case 0xbc: address = operand16() + __cpu->__x_register; break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->setFlags(C_FLAG, __cpu->__ram->operator[](address) & 0x01);
        __cpu->setFlags(Z_FLAG, !(__cpu->__ram->operator[](address) >>= 1));
        __cpu->unsetFlags(N_FLAG);
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
        case 0x01: value = __cpu->__ram->operator[](__cpu->__ram->operator[]<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0x11: value = __cpu->__ram->operator[](__cpu->__ram->operator[]<uint16_t>(operand()) + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        __cpu->__accumulator = (int16_t)__cpu->__accumulator | value;
        __cpu->setFlags(Z_FLAG, !__cpu->__accumulator);
        __cpu->setFlags(N_FLAG, __cpu->__accumulator & 0x80);
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
        uint8_t *value_p;
        switch (opcode())
        {
        case 0x2a: value_p = &__cpu->__accumulator; break;
        case 0x26: value_p = &__cpu->__ram->operator[](operand()); break;
        case 0x36: value_p = &__cpu->__ram->operator[](((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x2e: value_p = &__cpu->__ram->operator[](operand16()); break;
        case 0x3e: value_p = &__cpu->__ram->operator[](operand16() + __cpu->__x_register); break;
        default: assert("Mustn't reach the statement");
        }
        uint8_t &value = *value_p;
        uint8_t cf = __cpu->__flags & C_FLAG;
        __cpu->setFlags(C_FLAG, value & 0x80);
        value <<= 1;
        if (cf) value |= 0x01; else value &= ~0x01;
        __cpu->setFlags(Z_FLAG, !value);
        __cpu->setFlags(N_FLAG, value & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, ROR)
    {
        uint8_t *value_p;
        switch (opcode())
        {
        case 0x6a: value_p = &__cpu->__accumulator; break;
        case 0x66: value_p = &__cpu->__ram->operator[](operand()); break;
        case 0x76: value_p = &__cpu->__ram->operator[](((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x6e: value_p = &__cpu->__ram->operator[](operand16()); break;
        case 0x7e: value_p = &__cpu->__ram->operator[](operand16() + __cpu->__x_register); break;
        default: assert("Mustn't reach the statement");
        }
        uint8_t &value = *value_p;
        uint8_t cf = __cpu->__flags & C_FLAG;
        __cpu->setFlags(C_FLAG, value & 0x80);
        value >>= 1;
        if (cf) value |= 0x80; else value &= ~0x80;
        __cpu->setFlags(Z_FLAG, !value);
        __cpu->setFlags(N_FLAG, value & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, RTI)
    {
        __cpu->__flags = __cpu->pop<uint8_t>();
        __cpu->__program_counter = __cpu->pop<uint16_t>();
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, RTS)
    {
        __cpu->__program_counter = __cpu->pop<uint16_t>();
        ++__cpu->__program_counter;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SEC)
    {
        __cpu->setFlags(C_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SED)
    {
        __cpu->setFlags(D_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, SEI)
    {
        __cpu->setFlags(I_FLAG);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, STA)
    {
        uint8_t *value_p;
        switch (opcode())
        {
        case 0x85: value_p = &__cpu->__ram->operator[](operand()); break;
        case 0x95: value_p = &__cpu->__ram->operator[](((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x8d: value_p = &__cpu->__ram->operator[](operand16()); break;
        case 0x9d: value_p = &__cpu->__ram->operator[](operand16() + __cpu->__x_register); break;
        case 0x99: value_p = &__cpu->__ram->operator[](operand16() + __cpu->__y_register); break;
        case 0x81: value_p = &__cpu->__ram->operator[](__cpu->__ram->operator[]<uint16_t>(((uint16_t)operand() + __cpu->__x_register) & 0xff)); break;
        case 0x91: value_p = &__cpu->__ram->operator[](__cpu->__ram->operator[]<uint16_t>(operand()) + __cpu->__y_register); break;
        default: assert("Mustn't reach the statement");
        }
        *value_p = __cpu->__accumulator;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, STX)
    {
        uint8_t *value_p;
        switch (opcode())
        {
        case 0x86: value_p = &__cpu->__ram->operator[](operand()); break;
        case 0x96: value_p = &__cpu->__ram->operator[](((uint16_t)operand() + __cpu->__y_register) & 0xff); break;
        case 0x8e: value_p = &__cpu->__ram->operator[](operand16()); break;
        default: assert("Mustn't reach the statement");
        }
        *value_p = __cpu->__x_register;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, STY)
    {
        uint8_t *value_p;
        switch (opcode())
        {
        case 0x84: value_p = &__cpu->__ram->operator[](operand()); break;
        case 0x94: value_p = &__cpu->__ram->operator[](((uint16_t)operand() + __cpu->__x_register) & 0xff); break;
        case 0x8c: value_p = &__cpu->__ram->operator[](operand16()); break;
        default: assert("Mustn't reach the statement");
        }
        *value_p = __cpu->__y_register;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TAX)
    {
        __cpu->__x_register = __cpu->__accumulator;
        __cpu->setFlags(Z_FLAG, !__cpu->__x_register);
        __cpu->setFlags(Z_FLAG, __cpu->__x_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TAY)
    {
        __cpu->__y_register = __cpu->__accumulator;
        __cpu->setFlags(Z_FLAG, !__cpu->__y_register);
        __cpu->setFlags(Z_FLAG, __cpu->__y_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TSX)
    {
        __cpu->__x_register = __cpu->__stack_pointer;
        __cpu->setFlags(Z_FLAG, !__cpu->__x_register);
        __cpu->setFlags(Z_FLAG, __cpu->__x_register & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TXA)
    {
        __cpu->__accumulator = __cpu->__x_register;
        __cpu->setFlags(Z_FLAG, !__cpu->__accumulator);
        __cpu->setFlags(Z_FLAG, __cpu->__accumulator & 0x80);
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TXS)
    {
        __cpu->__stack_pointer = __cpu->__x_register;
    }

    DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(CPU6502, TYA)
    {
        __cpu->__accumulator = __cpu->__y_register;
        __cpu->setFlags(Z_FLAG, !__cpu->__accumulator);
        __cpu->setFlags(Z_FLAG, __cpu->__accumulator & 0x80);
    }
}