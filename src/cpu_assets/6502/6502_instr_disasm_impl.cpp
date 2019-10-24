#include "6502.h"
#include <sstream>
#include <assert.h>

namespace vm
{
    inline std::string uint8_to_hex(uint8_t number)
    {
        std::stringstream stm;
        stm << std::hex << (unsigned)number;
        return stm.str();
    }

    inline std::string uint16_to_hex(uint16_t number)
    {
        std::stringstream stm;
        stm << std::hex << number;
        return stm.str();
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, ADC)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, AND)
    {
        std::string command("and ");
        switch (opcode())
        {
        case 0x29: return command + "#$" + uint8_to_hex(operand());
        case 0x25: return command + '$' + uint8_to_hex(operand());
        case 0x35: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x2d: return command + '$' + uint16_to_hex(operand16());
        case 0x3d: return command + '$' + uint16_to_hex(operand16()) + ", x";
        case 0x39: return command + '$' + uint16_to_hex(operand16()) + ", y";
        case 0x21: return command + "($" + uint8_to_hex(operand()) + ", x)";
        case 0x31: return command + "($" + uint8_to_hex(operand()) + "), y";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, ASL)
    {
        std::string command("asl ");
        switch (opcode())
        {
        case 0x0a: return command + "a";
        case 0x06: return command + '$' + uint8_to_hex(operand());
        case 0x16: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x0e: return command + '$' + uint16_to_hex(operand16());
        case 0x1e: return command + '$' + uint16_to_hex(operand16()) + ", x";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BCC)
    {
        return "bcc";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BCS)
    {
        return "bcs";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BEQ)
    {
        return "beq";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BIT)
    {
        std::string command = "bit ";
        switch (opcode())
        {
        case 0x24: return command + "$" + uint8_to_hex(operand());
        case 0x2c: return command + '$' + uint16_to_hex(operand());
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BMI)
    {
        return "bmi";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BNE)
    {
        return "bne";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BPL)
    {
        return "bpl";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BRK)
    {
        return "brk";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BVC)
    {
        return "bvc";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BVS)
    {
        return "bvs";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLC)
    {
        return "clc";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLD)
    {
        return "cld";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLI)
    {
        return "cli";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLV)
    {
        return "clv";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CMP)
    {
        std::string command("cmp ");
        switch (opcode())
        {
        case 0x29: return command + "#$" + uint8_to_hex(operand());
        case 0x25: return command + '$' + uint8_to_hex(operand());
        case 0x35: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x2d: return command + '$' + uint16_to_hex(operand16());
        case 0x3d: return command + '$' + uint16_to_hex(operand16()) + ", x";
        case 0x39: return command + '$' + uint16_to_hex(operand16()) + ", y";
        case 0x21: return command + "($" + uint8_to_hex(operand()) + ", x)";
        case 0x31: return command + "($" + uint8_to_hex(operand()) + "), y";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CPX)
    {
        std::string command("cpx ");
        switch (opcode())
        {
        case 0xe0: return command + "#$" + uint8_to_hex(operand());
        case 0xe4: return command + '$' + uint8_to_hex(operand());
        case 0xec: return command + '$' + uint16_to_hex(operand16());
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CPY)
    {
        std::string command("cpy ");
        switch (opcode())
        {
        case 0xc0: return command + "#$" + uint8_to_hex(operand());
        case 0xc4: return command + '$' + uint8_to_hex(operand());
        case 0xcc: return command + '$' + uint16_to_hex(operand16());
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, DEC)
    {
        std::string command("inc ");
        switch (opcode())
        {
        case 0xc6: return command + "$" + uint8_to_hex(operand());
        case 0xd6: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0xce: return command + '$' + uint16_to_hex(operand16());
        case 0xde: return command + '$' + uint16_to_hex(operand16()) + ", x";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, DEX)
    {
        return "dec";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, DEY)
    {
        return "dec";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, EOR)
    {
        std::string command("eor ");
        switch (opcode())
        {
        case 0x49: return command + "#$" + uint8_to_hex(operand());
        case 0x45: return command + '$' + uint8_to_hex(operand());
        case 0x55: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x4d: return command + '$' + uint16_to_hex(operand16());
        case 0x5d: return command + '$' + uint16_to_hex(operand16()) + ", x";
        case 0x59: return command + '$' + uint16_to_hex(operand16()) + ", y";
        case 0x41: return command + "($" + uint8_to_hex(operand()) + ", x)";
        case 0x51: return command + "($" + uint8_to_hex(operand()) + "), y";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, INC)
    {
        std::string command("inc ");
        switch (opcode())
        {
        case 0xe6: return command + "$" + uint8_to_hex(operand());
        case 0xf6: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0xee: return command + '$' + uint16_to_hex(operand16());
        case 0xfe: return command + '$' + uint16_to_hex(operand16()) + ", x";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, INX)
    {
        return "inc";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, INY)
    {
        return "inc";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, JMP)
    {
        std::string command("jmp ");
        switch (opcode())
        {
        case 0x4c: return command + "$" + uint16_to_hex(operand16());
        case 0x6c: return command + "($" + uint16_to_hex(operand16()) + ')';
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, JSR)
    {
        return std::string("jsr") + uint16_to_hex(operand16());
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LDA)
    {
        std::string command("lda ");
        switch (opcode())
        {
        case 0xa9: return command + "#$" + uint8_to_hex(operand());
        case 0xa5: return command + '$' + uint8_to_hex(operand());
        case 0xb5: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0xad: return command + '$' + uint16_to_hex(operand16());
        case 0xbd: return command + '$' + uint16_to_hex(operand16()) + ", x";
        case 0xb9: return command + '$' + uint16_to_hex(operand16()) + ", y";
        case 0xa1: return command + "($" + uint8_to_hex(operand()) + ", x)";
        case 0xb1: return command + "($" + uint8_to_hex(operand()) + "), y";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LDX)
    {
        std::string command("ldx ");
        switch (opcode())
        {
        case 0xa2: return command + "#$" + uint8_to_hex(operand());
        case 0xa6: return command + '$' + uint8_to_hex(operand());
        case 0xb6: return command + '$' + uint8_to_hex(operand()) + ", y";
        case 0xae: return command + '$' + uint16_to_hex(operand16());
        case 0xbe: return command + '$' + uint16_to_hex(operand16()) + ", y";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LDY)
    {
        std::string command("ldx ");
        switch (opcode())
        {
        case 0xa0: return command + "#$" + uint8_to_hex(operand());
        case 0xa4: return command + '$' + uint8_to_hex(operand());
        case 0xb4: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0xac: return command + '$' + uint16_to_hex(operand16());
        case 0xbc: return command + '$' + uint16_to_hex(operand16()) + ", x";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LSR)
    {
        std::string command("lsr ");
        switch (opcode())
        {
        case 0x4a: return command + "a";
        case 0x46: return command + '$' + uint8_to_hex(operand());
        case 0x56: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x4e: return command + '$' + uint16_to_hex(operand16());
        case 0x5e: return command + '$' + uint16_to_hex(operand16()) + ", x";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, NOP)
    {
        return "nop";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, ORA)
    {
        std::string command("ora ");
        switch (opcode())
        {
        case 0x09: return command + "#$" + uint8_to_hex(operand());
        case 0x05: return command + '$' + uint8_to_hex(operand());
        case 0x15: return command + '$' + uint8_to_hex(operand());
        case 0x0d: return command + '$' + uint16_to_hex(operand16());
        case 0x1d: return command + '$' + uint16_to_hex(operand16());
        case 0x19: return command + '$' + uint16_to_hex(operand16());
        case 0x01: return command + "($" + uint8_to_hex(operand()) + ", x)";
        case 0x11: return command + "($" + uint8_to_hex(operand()) + "), y";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, PHA)
    {
        return "push A";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, PHP)
    {
        return "push SR";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, PLA)
    {
        return "pull A";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, PLP)
    {
        return "pull SR";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, ROL)
    {
        std::string command("rol ");
        switch (opcode())
        {
        case 0x2a: return command + "a";
        case 0x26: return command + '$' + uint8_to_hex(operand());
        case 0x36: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x2e: return command + '$' + uint16_to_hex(operand16());
        case 0x3e: return command + '$' + uint16_to_hex(operand16()) + ", x";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, ROR)
    {
        std::string command("ror ");
        switch (opcode())
        {
        case 0x6a: return command + "a";
        case 0x66: return command + '$' + uint8_to_hex(operand());
        case 0x76: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x6e: return command + '$' + uint16_to_hex(operand16());
        case 0x7e: return command + '$' + uint16_to_hex(operand16()) + ", x";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, RTI)
    {
        return "rti";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, RTS)
    {
        return "rts";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SEC)
    {
        return "sec";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SED)
    {
        return "sed";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SEI)
    {
        return "sei";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, STA)
    {
        std::string command("sta ");
        switch (opcode())
        {
        case 0x85: return command + '$' + uint8_to_hex(operand());
        case 0x95: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x8d: return command + '$' + uint16_to_hex(operand16());
        case 0x9d: return command + '$' + uint16_to_hex(operand16()) + ", x";
        case 0x99: return command + '$' + uint16_to_hex(operand16()) + ", y";
        case 0x81: return command + "($" + uint8_to_hex(operand()) + ", x)";
        case 0x91: return command + "($" + uint8_to_hex(operand()) + "), y";
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, STX)
    {
        std::string command("stx ");
        switch (opcode())
        {
        case 0x86: return command + '$' + uint8_to_hex(operand());
        case 0x96: return command + '$' + uint8_to_hex(operand()) + ", y";
        case 0x8e: return command + '$' + uint16_to_hex(operand16());
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, STY)
    {
        std::string command("sty ");
        switch (opcode())
        {
        case 0x84: return command + '$' + uint8_to_hex(operand());
        case 0x94: return command + '$' + uint8_to_hex(operand()) + ", x";
        case 0x8c: return command + '$' + uint16_to_hex(operand16());
        default: assert("Mustn't reach the statement");
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, TAX)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, TAY)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, TSX)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, TXA)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, TXS)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, TYA)
    {

    }
}