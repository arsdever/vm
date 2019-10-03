#pragma once

#include "abstract_instruction_set.h"

#define DECLARE_INSTRUCTION(__cpu__, __instruction__) \
class Instruction_##__instruction__ : public AbstractInstructionSet::executor_t \
{ \
public: \
    Instruction_##__instruction__() \
        : __cpu((__cpu__*)((uint64_t)this - (uint64_t)&(((__cpu__*)(0x0))->__instruction__##_impl))) \
    {} \
    void execute() const override; \
    std::string disassemble() const override; \
    int instructionSize() const override; \
    int instructionDuration() const override; \
private: \
    __cpu__ *__cpu; \
} __instruction__##_impl;

#define DEFINE_INSTRUCTION_EXECUTOR(__cpu__, __instruction__) \
void __cpu__::Instruction_##__instruction__::execute() const

#define DEFINE_INSTRUCTION_DISASSEMBLER(__cpu__, __instruction__) \
std::string __cpu__::Instruction_##__instruction__::disassemble() const

#define DEFINE_INSTRUCTION_SIZE(__cpu__, __instruction__) \
int __cpu__::Instruction_##__instruction__::instructionSize() const

#define DEFINE_INSTRUCTION_DURATION(__cpu__, __instruction__) \
int __cpu__::Instruction_##__instruction__::instructionDuration() const
