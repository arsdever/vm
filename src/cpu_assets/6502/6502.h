#pragma once

#include <cpu_assets/ram.h>
#include <cpu_assets/abstract_cpu.h>
#include "6502_instruction_set.h"
#include <cpu_assets/abstract_instructions_impl.h>

#include <stdint.h>

#undef DECLARE_INSTRUCTION
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

#define DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(__cpu__, __instruction__) \
void __cpu__::Instruction_##__instruction__::fetch(uint64_t pc, RAM *ram) \
{ \
    __instruction[0] = ram->operator[]((uint16_t)pc); \
    __instruction[1] = ram->operator[]((uint16_t)pc + 1); \
    __instruction[2] = ram->operator[]((uint16_t)pc + 2); \
} \
DEFINE_INSTRUCTION_EXECUTOR(__cpu__, __instruction__)

namespace vm
{
    class CPUOptions;

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
            INVALID_FLAG = 0x20,
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
    
    public:
        static CPU6502* fromOptions(CPUOptions const &opts);
        static const int UUID = 328;

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
        template <typename NUMBER_TYPE>
        inline void push(NUMBER_TYPE value);
        
        template <typename NUMBER_TYPE>
        inline NUMBER_TYPE pop();

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

    template <>
    inline void CPU6502::push<uint8_t>(uint8_t value)
    {
        __ram->operator[](__stack_pointer-- + 0x0100) = value;
    }

    template <>
    inline void CPU6502::push<uint16_t>(uint16_t value)
    {
        __ram->operator[](__stack_pointer-- + 0x0100) = uint8_t(value & 0xff);
        __ram->operator[](__stack_pointer-- + 0x0100) = uint8_t(value >> 8 & 0xff);
    }

    template <>
    inline uint8_t CPU6502::pop<uint8_t>()
    {
        return __ram->operator[](__stack_pointer++ + 0x0100);
    }

    template <>
    inline uint16_t CPU6502::pop<uint16_t>()
    {
        uint16_t value = 0;
        value |= __ram->operator[](__stack_pointer++ + 0x0100);
        value <<= 8;
        value |= __ram->operator[](__stack_pointer++ + 0x0100);
        return value;
    }
}