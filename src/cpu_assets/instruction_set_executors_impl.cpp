#include "instruction_set_executors_impl.h"
#include "abstract_cpu.h"

namespace vm
{
    DEFINE_INSTRUCTION_IMPLEMENTER(ADD)
    {
        int a = cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]);
        int b = cpu.getRegister(((char *)&cpu.getInstructionRegister())[2]);
        int result = a + b;
        cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]) = result;
    }
    DEFINE_INSTRUCTION_DISASSEMBLER(ADD)
    {
        return "add " + std::to_string(((char *)&cpu.getInstructionRegister())[1]) + ", " + std::to_string(((char *)&cpu.getInstructionRegister())[2]);
    }

    DEFINE_INSTRUCTION_IMPLEMENTER(ADC)
    {
        int a = cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]);
        int b = cpu.getRegister(((char *)&cpu.getInstructionRegister())[2]);
        int result = a + b + (__flags | 1);
        cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]) = result;
    }
    DEFINE_INSTRUCTION_DISASSEMBLER(ADC)
    {
        return "adc " + std::to_string(((char *)&cpu.getInstructionRegister())[1]) + ", " + std::to_string(((char *)&cpu.getInstructionRegister())[2]);
    }

    DEFINE_INSTRUCTION_IMPLEMENTER(MUL)
    {
        int a = cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]);
        int b = cpu.getRegister(((char *)&cpu.getInstructionRegister())[2]);
        int result = a * b;
        cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]) = result;
    }
    DEFINE_INSTRUCTION_DISASSEMBLER(MUL)
    {
        return "mul " + std::to_string(((char *)&cpu.getInstructionRegister())[1]) + ", " + std::to_string(((char *)&cpu.getInstructionRegister())[2]);
    }

    DEFINE_INSTRUCTION_IMPLEMENTER(SUB)
    {
        int a = cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]);
        int b = cpu.getRegister(((char *)&cpu.getInstructionRegister())[2]);
        int result = a - b;
        cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]) = result;
    }
    DEFINE_INSTRUCTION_DISASSEMBLER(SUB)
    {
        return "sub " + std::to_string(((char *)&cpu.getInstructionRegister())[1]) + ", " + std::to_string(((char *)&cpu.getInstructionRegister())[2]);
    }

    DEFINE_INSTRUCTION_IMPLEMENTER(ASG)
    {
        int a = cpu.getRegister(((char *)&cpu.getInstructionRegister())[1]) = (short&)((char *)&cpu.getInstructionRegister())[2];
    }
    DEFINE_INSTRUCTION_DISASSEMBLER(ASG)
    {
        return "asg " + std::to_string(((char *)&cpu.getInstructionRegister())[1]) + ", " + std::to_string(((char *)&cpu.getInstructionRegister())[2]);
    }
}