#include "atmega328p.h"
#include <sstream>

std::string& __arg(std::string &str, std::string const &arg, std::string const &value)
{
    size_t found = str.find_first_of(arg);
    str.replace(found, arg.size(), value);
    return str;
}

std::string& arg(std::string &str, std::string const &value)
{
    return __arg(str, "%", value);
}

namespace vm
{
    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, NOP)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, MOVW)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, MULS)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, FMUL)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, FMULS)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, FMULSU)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, MULSU)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, CPC)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SBC)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, ADD)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, CPSE)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, CP)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SUB)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, ADC)
    {
        std::string result("adc r%, r%");
        return arg(arg(result, std::to_string(operand(1))), std::to_string(operand(2))); 
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, AND)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, EOR)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, OR)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, MOV)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, CPI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SBCI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SUBI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, ORI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, ANDI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, LD)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, LDD)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, ST)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, STD)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, ADIW)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SBIW)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, CBI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SBIC)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SBI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, SBIS)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, MUL)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, IN)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, OUT)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, RJMP)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, RCALL)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, LDI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BRCS)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BREQ)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BRMI)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BRVS)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BRLT)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BRHS)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BRTS)
    {
        
    }

    DEFINE_INSTRUCTION_DISASSEMBLER(ATmega328P, BRIE)
    {
        
    }
}