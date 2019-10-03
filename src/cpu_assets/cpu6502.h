#pragma once

#include "abstract_cpu.h"
#include "6502_instruction_set.h"
#include "abstract_instructions_impl.h"

#include <stdint.h>

namespace vm
{
    class CPU6502 : public AbstractCPU
    {
        friend class InstructionSetFor6502;

        DECLARE_INSTRUCTION(CPU6502, BRK);
        DECLARE_INSTRUCTION(CPU6502, BPL);

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

        inline void setFlags(int8_t flags, bool state = true);
        inline void unsetFlags(int8_t flags);

    private:
        AbstractInstructionSet *__instruction_set;
        int16_t __program_counter;
        int8_t __accumulator;
        int8_t __x_register;
        int8_t __y_register;
        int8_t __flags;
        int8_t __stack_pointer;
        AbstractInstructionSet::executor_t *__executor;
    };

    inline void CPU6502::setFlags(int8_t flags, bool state)
    {
        if(state)
            __flags |= flags;
        else
            __flags &= ~flags;
    }

    inline void CPU6502::unsetFlags(int8_t flags)
    {
        setFlags(flags, false);
    }
}