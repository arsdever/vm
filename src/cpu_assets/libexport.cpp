#include "atmega328p/atmega328p.h"
#include "ram.h"

extern "C"
{
    vm::CPU* instantiate(void *options)
    {
        vm::RAM *ram = new vm::RAM(0x7fff);
        return (vm::CPU*)new vm::ATmega328P(ram);
    }
}