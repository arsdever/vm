#pragma once

#include "cpu.h"

namespace vm
{
    class RAM;
    class AbstractInstructionSet;

    class AbstractCPU : public CPU
    {
        friend class AbstractInstructionSet;

    public:
        AbstractCPU(RAM *ram);

        virtual void setRam(RAM *ram);
        virtual RAM* ram() const override;

        bool start(bool debug = false) override;
        int tick() override;
        bool isRunning() const override;
        std::string disassemble() const override;

        virtual void* getInstructionRegister() const = 0;
        virtual void* getProgramCounter() const = 0;
        virtual void* getRegister(unsigned char reg_number) const = 0;
        virtual AbstractInstructionSet* getInstructionSet() const = 0;

    protected:
        virtual void fetch() override;
        virtual void execute() override;

    protected:
        RAM *__ram;
        bool __is_running;
        bool __debug_mode;
    };
}