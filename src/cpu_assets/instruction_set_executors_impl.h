#pragma once

#include "abstract_instruction_set.h"

#define DECLARE_INSTRUCTION_IMPLEMENTER(__instruction__) \
class Instruction_##__instruction__ : public AbstractInstructionSet::InstructionExecutor \
{ \
public: \
    Instruction_##__instruction__() : InstructionExecutor(this) {} \
    void operator() (AbstractCPU &cpu) override; \
    std::string disassemble(AbstractCPU &cpu) const override; \
};

#define DEFINE_INSTRUCTION_IMPLEMENTER(__instruction__) \
void Instruction_##__instruction__::operator() (AbstractCPU &cpu)

#define DEFINE_INSTRUCTION_DISASSEMBLER(__instruction__) \
std::string Instruction_##__instruction__::disassemble(AbstractCPU &cpu) const

namespace vm
{
    DECLARE_INSTRUCTION_IMPLEMENTER(ADC)
    DECLARE_INSTRUCTION_IMPLEMENTER(ADD)
    DECLARE_INSTRUCTION_IMPLEMENTER(MUL)
    DECLARE_INSTRUCTION_IMPLEMENTER(SUB)
    DECLARE_INSTRUCTION_IMPLEMENTER(ASG)
}