#pragma once

#include <string>

namespace vm
{
    class RAM;

    class CPU
    {
    public:
        virtual bool start(bool debug = false) = 0;
        virtual bool isRunning() const = 0;
        virtual void tick() = 0;
        virtual RAM* ram() const = 0;
        virtual std::string dump() = 0;

    protected:
        virtual void fetch() = 0;
        virtual void decode() = 0;
        virtual void execute() = 0;
    };
}