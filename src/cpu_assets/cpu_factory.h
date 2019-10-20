#pragma once

namespace vm
{
    class CPU;
    struct CPUOptions;

    class CPUFactory
    {
    private:
        CPUFactory();

    public:
        static CPU* getCPUInstance(CPUOptions const& opts);
        static CPUFactory* factory();
    };
}