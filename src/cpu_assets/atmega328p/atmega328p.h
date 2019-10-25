#pragma once

#include <cpu_assets/ram.h>
#include <cpu_assets/abstract_cpu.h>
#include <cpu_assets/abstract_instructions_impl.h>

#include <stdint.h>

#undef EMPTY
#define EMPTY \
{ return 0; }

#undef REGISTER_INDEXES
#define REGISTER_INDEXES \
{ \
    switch(n) \
    { \
        case 0: return uint8_t((__instruction >> 4) & 0x1f); \
        case 1: { \
            uint8_t((__instruction & 0x0200) >> 5 | (__instruction & 0x0f)); \
        } \
    } \
}

#undef DECLARE_INSTRUCTION
#define DECLARE_INSTRUCTION(__cpu__, __instruction__, __operand_getter__) \
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
    inline uint8_t opcode() const { return uint8_t(__instruction >> 8); } \
    inline uint8_t operand(uint8_t n) const __operand_getter__; \
private: \
    __cpu__ *__cpu; \
    uint16_t __instruction; \
} __instruction__##_impl;

#undef DECLARE_INSTRUCTION_DEFAULT
#define DECLARE_INSTRUCTION_DEFAULT(__cpu__, __instruction__) \
DECLARE_INSTRUCTION(__cpu__, __instruction__, EMPTY)

#undef DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR
#define DEFINE_INSTRUCTION_FETCHER_AND_EXECUTOR(__cpu__, __instruction__) \
void __cpu__::Instruction_##__instruction__::fetch(uint64_t pc, RAM *ram) \
{ \
    __instruction = ram->operator[]<uint16_t>(pc); \
} \
DEFINE_INSTRUCTION_EXECUTOR(__cpu__, __instruction__)

namespace vm
{
    class CPUOptions;

    class ATmega328P : public AbstractCPU
    {
        friend class InstructionSetForATmega328P;

        DECLARE_INSTRUCTION_DEFAULT(ATmega328P, NOP);
        DECLARE_INSTRUCTION(ATmega328P, MOVW, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, MULS, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, FMUL, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, FMULS, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, FMULSU, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, MULSU, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, CPC, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SBC, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, ADD, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, CPSE, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, CP, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SUB, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, ADC, REGISTER_INDEXES);
        DECLARE_INSTRUCTION(ATmega328P, AND, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, EOR, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, OR, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, MOV, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, CPI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SBCI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SUBI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, ORI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, ANDI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, LD, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, LDD, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, ST, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, STD, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, ADIW, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SBIW, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, CBI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SBIC, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SBI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, SBIS, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, MUL, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, IN, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, OUT, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, RJMP, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, RCALL, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, LDI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BRCS, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BREQ, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BRMI, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BRVS, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BRLT, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BRHS, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BRTS, EMPTY);
        DECLARE_INSTRUCTION(ATmega328P, BRIE, EMPTY);

    public:
        enum FLAGS6502
        {
            I_FLAG = 0x80,
            T_FLAG = 0x40,
            H_FLAG = 0x20,
            S_FLAG = 0x10,
            V_FLAG = 0x08,
            N_FLAG = 0x04,
            Z_FLAG = 0x02,
            C_FLAG = 0x01
        };
        
    public:
        ATmega328P(RAM *ram);

        void* getInstructionRegister() const override;
        void* getProgramCounter() const override;
        void* getRegister(unsigned char reg_number) const override;
        AbstractInstructionSet* getInstructionSet() const override;
        bool start(bool debug = false) override;
        void reset() override;
        bool isRunning() const override;
        std::string disassemble() const override;
        int tick() override;
        inline RAM* ram() const override { return __ram; }
    
    public:
        static ATmega328P* fromOptions(CPUOptions const &opts);
        static const int UUID = 1;

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

    inline void ATmega328P::setFlags(uint8_t flags, bool state)
    {
        if(state)
            __flags |= flags;
        else
            __flags &= ~flags;
    }

    inline void ATmega328P::unsetFlags(uint8_t flags)
    {
        setFlags(flags, false);
    }

    template <>
    inline void ATmega328P::push<uint8_t>(uint8_t value)
    {
        __ram->operator[](__stack_pointer--) = value;
    }

    template <>
    inline void ATmega328P::push<uint16_t>(uint16_t value)
    {
        __ram->operator[](__stack_pointer--) = uint8_t(value & 0xff);
        __ram->operator[](__stack_pointer--) = uint8_t(value >> 8 & 0xff);
    }

    template <>
    inline uint8_t ATmega328P::pop<uint8_t>()
    {
        return __ram->operator[](__stack_pointer++);
    }

    template <>
    inline uint16_t ATmega328P::pop<uint16_t>()
    {
        uint16_t value = 0;
        value |= __ram->operator[](__stack_pointer++);
        value <<= 9;
        value |= __ram->operator[](__stack_pointer++);
        return value;
    }
}