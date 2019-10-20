#include "6502.h"
#include <sstream>

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

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, ASL)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BCC)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BCS)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BEQ)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BIT)
    {
        std::string command = "bit ";
        switch (opcode())
        {
        case 0x24: return command + "$" + uint8_to_hex(operand());
        case 0x2c: return command + '$' + uint16_to_hex(operand());
        default: return command;
        }
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BMI)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BNE)
    {

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

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, BVS)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLC)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLD)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLI)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CLV)
    {
        return "clv";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CMP)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CPX)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, CPY)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, DEC)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, DEX)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, DEY)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, EOR)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, INC)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, INX)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, INY)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, JMP)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, JSR)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LDA)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LDX)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LDY)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, LSR)
    {

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
        case 0x01: return command + "($" + uint8_to_hex(operand()) + ", X)";
        case 0x11: return command + "($" + uint8_to_hex(operand()) + "), Y";
        default: return command;
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

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, ROR)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, RTI)
    {
        return "rti";
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, RTS)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SBC)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SEC)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SED)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, SEI)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, STA)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, STX)
    {

    }

    DEFINE_INSTRUCTION_DISASSEMBLER(CPU6502, STY)
    {

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