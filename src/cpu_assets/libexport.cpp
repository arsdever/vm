#include "cpu_model.h"
#include "ram.h"

extern "C"
{
    vm::CPU* getCPUInstance()
    {
        vm::RAM *ram = new vm::RAM(0x7fff);
        return (vm::CPU*)new vm::CPUModel(ram);
    }
}