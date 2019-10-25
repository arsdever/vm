#pragma once

#include <string>

namespace vm
{
    class RAM;

    class CPU
    {
    public:
        virtual bool start(bool debug = false) = 0;
        virtual void reset() = 0;
        virtual bool isRunning() const = 0;
        virtual int tick() = 0;
        virtual RAM* ram() const = 0;
        virtual std::string disassemble() const = 0;

#ifdef DEBUGGING
        virtual std::string dump() const = 0;
#endif

    protected:
        virtual void fetch() = 0;
        virtual void decode() = 0;
        virtual void execute() = 0;
    };
}