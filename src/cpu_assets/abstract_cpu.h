#pragma once

#include "cpu.h"

namespace vm
{
    class RAM;

    class AbstractCPU : public CPU
    {
        friend class AbstractInstructionSet;

    public:
        AbstractCPU(RAM *ram);

        virtual void setRam(RAM *ram);
        virtual RAM* ram() const override;

        bool start(bool debug = false) override;
        void tick() override;
        std::string dump();
        bool isRunning() const override;

        int& getInstructionRegister();
        int& getRegister(unsigned char reg_number);

    protected:
        virtual void fetch() override;

    protected:
        RAM *__ram;
        int __instruction_register;
        int __instruction_pointer;
        int __flags;
        int *__registers;
        bool __is_running;
        bool __debug_mode;
    };
}