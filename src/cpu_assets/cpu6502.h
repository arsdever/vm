#pragma once

#include "abstract_cpu.h"
#include "6502_instruction_set.h"
#include "abstract_instructions_impl.h"

#include <stdint.h>
#include <stack>

#define DECLARE_INSTRUCTION(__cpu__, __instruction__) \
class Instruction_##__instruction__ : public AbstractInstructionSet::executor_t \
{ \
public: \
    Instruction_##__instruction__() \
        : __cpu((__cpu__*)((uint64_t)this - (uint64_t)&(((__cpu__*)(0x0))->__instruction__##_impl))) \
        , __instruction{ 0 } \
    {} \
    void execute() const override; \
    std::string disassemble() const override; \
    int instructionSize() const override; \
    int instructionDuration() const override; \
    void fetch(uint64_t pc, RAM *ram) override; \
    inline uint8_t opcode() const { return __instruction[0]; } \
    inline uint8_t operand() const { return __instruction[1]; } \
    inline uint8_t operand16() const { return (((int16_t)__instruction[2] << 8) & 0xff00) | __instruction[1]; } \
private: \
    __cpu__ *__cpu; \
    uint8_t __instruction[3]; \
} __instruction__##_impl;

namespace vm
{
    class CPU6502 : public AbstractCPU
    {
        friend class InstructionSetFor6502;

        DECLARE_INSTRUCTION(CPU6502, ADC);
        DECLARE_INSTRUCTION(CPU6502, AND);
        DECLARE_INSTRUCTION(CPU6502, ASL);
        DECLARE_INSTRUCTION(CPU6502, BCC);
        DECLARE_INSTRUCTION(CPU6502, BCS);
        DECLARE_INSTRUCTION(CPU6502, BEQ);
        DECLARE_INSTRUCTION(CPU6502, BIT);
        DECLARE_INSTRUCTION(CPU6502, BMI);
        DECLARE_INSTRUCTION(CPU6502, BNE);
        DECLARE_INSTRUCTION(CPU6502, BPL);
        DECLARE_INSTRUCTION(CPU6502, BRK);
        DECLARE_INSTRUCTION(CPU6502, BVC);
        DECLARE_INSTRUCTION(CPU6502, BVS);
        DECLARE_INSTRUCTION(CPU6502, CLC);
        DECLARE_INSTRUCTION(CPU6502, CLD);
        DECLARE_INSTRUCTION(CPU6502, CLI);
        DECLARE_INSTRUCTION(CPU6502, CLV);
        DECLARE_INSTRUCTION(CPU6502, CMP);
        DECLARE_INSTRUCTION(CPU6502, CPX);
        DECLARE_INSTRUCTION(CPU6502, CPY);
        DECLARE_INSTRUCTION(CPU6502, DEC);
        DECLARE_INSTRUCTION(CPU6502, DEX);
        DECLARE_INSTRUCTION(CPU6502, DEY);
        DECLARE_INSTRUCTION(CPU6502, EOR);
        DECLARE_INSTRUCTION(CPU6502, INC);
        DECLARE_INSTRUCTION(CPU6502, INX);
        DECLARE_INSTRUCTION(CPU6502, INY);
        DECLARE_INSTRUCTION(CPU6502, JMP);
        DECLARE_INSTRUCTION(CPU6502, JSR);
        DECLARE_INSTRUCTION(CPU6502, LDA);
        DECLARE_INSTRUCTION(CPU6502, LDX);
        DECLARE_INSTRUCTION(CPU6502, LDY);
        DECLARE_INSTRUCTION(CPU6502, LSR);
        DECLARE_INSTRUCTION(CPU6502, NOP);
        DECLARE_INSTRUCTION(CPU6502, ORA);
        DECLARE_INSTRUCTION(CPU6502, PHA);
        DECLARE_INSTRUCTION(CPU6502, PHP);
        DECLARE_INSTRUCTION(CPU6502, PLA);
        DECLARE_INSTRUCTION(CPU6502, PLP);
        DECLARE_INSTRUCTION(CPU6502, ROL);
        DECLARE_INSTRUCTION(CPU6502, ROR);
        DECLARE_INSTRUCTION(CPU6502, RTI);
        DECLARE_INSTRUCTION(CPU6502, RTS);
        DECLARE_INSTRUCTION(CPU6502, SBC);
        DECLARE_INSTRUCTION(CPU6502, SEC);
        DECLARE_INSTRUCTION(CPU6502, SED);
        DECLARE_INSTRUCTION(CPU6502, SEI);
        DECLARE_INSTRUCTION(CPU6502, STA);
        DECLARE_INSTRUCTION(CPU6502, STX);
        DECLARE_INSTRUCTION(CPU6502, STY);
        DECLARE_INSTRUCTION(CPU6502, TAX);
        DECLARE_INSTRUCTION(CPU6502, TAY);
        DECLARE_INSTRUCTION(CPU6502, TSX);
        DECLARE_INSTRUCTION(CPU6502, TXA);
        DECLARE_INSTRUCTION(CPU6502, TXS);
        DECLARE_INSTRUCTION(CPU6502, TYA);

    public:
        enum FLAGS6502
        {
            N_FLAG = 0x80,
            V_FLAG = 0x40,
            B_FLAG = 0x10,
            D_FLAG = 0x08,
            I_FLAG = 0x04,
            Z_FLAG = 0x02,
            C_FLAG = 0x01
        };
        
    public:
        CPU6502(RAM *ram);

        void* getInstructionRegister() const override;
        void* getProgramCounter() const override;
        void* getRegister(unsigned char reg_number) const override;
        AbstractInstructionSet* getInstructionSet() const override;
        bool start(bool debug = false) override;
        bool isRunning() const override;
        std::string disassemble() const override;
        void tick() override;
        inline RAM* ram() const override { return __ram; }

#ifdef DEBUGGING
        std::string dump() const override;
#endif

    protected:
        void fetch() override;
        void decode() override;
        void execute() override;

        inline void setFlags(uint8_t flags, bool state = true);
        inline void unsetFlags(uint8_t flags);

    private:
        AbstractInstructionSet *__instruction_set;
        int16_t __program_counter;
        uint8_t __accumulator;
        uint8_t __x_register;
        uint8_t __y_register;
        uint8_t __flags;
        uint8_t __stack_pointer;
        uint8_t __skip_ticks;
        AbstractInstructionSet::executor_t *__executor;
        std::stack<uint8_t> __stack;
    };

    inline void CPU6502::setFlags(uint8_t flags, bool state)
    {
        if(state)
            __flags |= flags;
        else
            __flags &= ~flags;
    }

    inline void CPU6502::unsetFlags(uint8_t flags)
    {
        setFlags(flags, false);
    }
}