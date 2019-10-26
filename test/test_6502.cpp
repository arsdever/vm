#include <fstream>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define TEST
#include <cpu_assets/6502/6502.h>
#include <cpu_assets/ram.h>

int executeUntilNextInstruction(vm::CPU6502 &cpu)
{
    int ticks = 0;
    while(cpu.tick()) ++ticks;
    return ticks;
}

#define CHECK_CPU_STATE(__program_counter__, __accumulator__, __x_register__, __y_register__, __flags__, __stack_pointer__, __clock__) \
CHECK((unsigned int)cpu.program_counter() == (unsigned int)__program_counter__); \
CHECK((unsigned int)cpu.accumulator() == (unsigned int)__accumulator__); \
CHECK((unsigned int)cpu.x_register() == (unsigned int)__x_register__); \
CHECK((unsigned int)cpu.y_register() == (unsigned int)__y_register__); \
CHECK((unsigned int)cpu.flags() == (unsigned int)__flags__); \
CHECK((unsigned int)cpu.stack_pointer() == (unsigned int)__stack_pointer__); \
CHECK(clocks == __clock__)

TEST_CASE("Testing instructions", "[instructions]")
{
    vm::RAM *ram_p;
    vm::CPU6502 *cpu_p;
    long clocks = 0;

    SECTION("Initialization")
    {
        ram_p = new vm::RAM(0x7fff);
        cpu_p = new vm::CPU6502(ram_p);
        clocks = 0;
        REQUIRE(ram_p != nullptr);
        REQUIRE(cpu_p != nullptr);
    }

    vm::RAM &ram = *ram_p;
    vm::CPU6502 &cpu = *cpu_p;

    SECTION("Testing instruction ADC")
    {

    }

    SECTION("Testing instruction AND")
    {

    }

    SECTION("Testing instruction ASL")
    {

    }

    SECTION("Testing instruction BCC")
    {

    }

    SECTION("Testing instruction BCS")
    {

    }

    SECTION("Testing instruction BEQ")
    {

    }

    SECTION("Testing instruction BIT")
    {

    }

    SECTION("Testing instruction BMI")
    {

    }

    SECTION("Testing instruction BNE")
    {

    }

    SECTION("Testing instruction BPL")
    {

    }

    SECTION("Testing instruction BRK")
    {

    }

    SECTION("Testing instruction BVC")
    {

    }

    SECTION("Testing instruction BVS")
    {

    }

    SECTION("Testing instruction CLC")
    {

    }

    SECTION("Testing instruction CLD")
    {

    }

    SECTION("Testing instruction CLI")
    {

    }

    SECTION("Testing instruction CLV")
    {

    }

    SECTION("Testing instruction CMP")
    {

    }

    SECTION("Testing instruction CPX")
    {

    }

    SECTION("Testing instruction CPY")
    {

    }

    SECTION("Testing instruction DEC")
    {

    }

    SECTION("Testing instruction DEX")
    {

    }

    SECTION("Testing instruction DEY")
    {

    }

    SECTION("Testing instruction EOR")
    {

    }

    SECTION("Testing instruction INC")
    {

    }

    SECTION("Testing instruction INX")
    {

    }

    SECTION("Testing instruction INY")
    {

    }

    SECTION("Testing instruction JMP")
    {

    }

    SECTION("Testing instruction JSR")
    {

    }

    SECTION("Testing instruction LDA")
    {
        ram = {
            0xa9, 0x01, 0xa9, 0xf0, 0xa9, 0x00, 0xa5, 0x01,
            0xa2, 0x05, 0xb5, 0x01, 0xa0, 0x02, 0xad, 0x0a,
            0x00, 0xbd, 0x0a, 0x00, 0xb9, 0x0a, 0x00, 0xa1,
            0x0a, 0xb1, 0x0a, 0x00 };
        cpu.reset();
        cpu.start();
        REQUIRE(cpu.isRunning());
        //               PC    ACC  XREG  YREG   SR    SP   CLOCK
        CHECK_CPU_STATE(0x00, 0x00, 0x00, 0x00, 0x20, 0xff, 0); // initial
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x02, 0x01, 0x00, 0x00, 0x20, 0xff, 2); // a9 01        -> lda #$01     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x04, 0xf0, 0x00, 0x00, 0xa0, 0xff, 4); // a9 f0        -> lda #$f0     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x06, 0x00, 0x00, 0x00, 0x22, 0xff, 6); // a9 00        -> lda #$00     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x08, 0x01, 0x00, 0x00, 0x20, 0xff, 9); // a5 01        -> lda $01      | 2 | 3 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x0a, 0x01, 0x05, 0x00, 0x20, 0xff, 11); // a2 05       -> ldx #$05     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x0c, 0xa5, 0x05, 0x00, 0xa0, 0xff, 15); // b5 01       -> lda $01, x   | 2 | 4 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x0e, 0xa5, 0x05, 0x02, 0x20, 0xff, 17); // a0 02       -> ldy #$02     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x11, 0xb5, 0x05, 0x02, 0xa0, 0xff, 21); // ad 0a 00    -> lda $000a    | 3 | 4 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x14, 0x0a, 0x05, 0x02, 0x20, 0xff, 25); // bd 0a 00    -> lda $000a, x | 3 | 4 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x17, 0xa0, 0x05, 0x02, 0xa0, 0xff, 29); // b9 0a 00    -> lda $000a, y | 3 | 4 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x19, 0xb5, 0x05, 0x02, 0xa0, 0xff, 35); // a1 0a       -> lda ($0a, x) | 3 | 4 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x1b, 0x00, 0x05, 0x02, 0x22, 0xff, 40); // b1 0a       -> lda ($0a, y) | 3 | 4 |

        // FIXME: Write tests for * type durations
    }
    
    SECTION("Testing instruction LDX")
    {

    }

    SECTION("Testing instruction LDY")
    {

    }

    SECTION("Testing instruction LSR")
    {

    }

    SECTION("Testing instruction NOP")
    {

    }

    SECTION("Testing instruction ORA")
    {

    }

    SECTION("Testing instruction PHA")
    {

    }

    SECTION("Testing instruction PHP")
    {

    }

    SECTION("Testing instruction PLA")
    {

    }

    SECTION("Testing instruction PLP")
    {

    }

    SECTION("Testing instruction ROL")
    {

    }

    SECTION("Testing instruction ROR")
    {

    }

    SECTION("Testing instruction RTI")
    {

    }

    SECTION("Testing instruction RTS")
    {

    }

    SECTION("Testing instruction SBC")
    {

    }

    SECTION("Testing instruction SEC")
    {

    }

    SECTION("Testing instruction SED")
    {

    }

    SECTION("Testing instruction SEI")
    {

    }

    SECTION("Testing instruction STA")
    {

    }

    SECTION("Testing instruction STX")
    {

    }

    SECTION("Testing instruction STY")
    {

    }

    SECTION("Testing instruction TAX")
    {

    }

    SECTION("Testing instruction TAY")
    {

    }

    SECTION("Testing instruction TSX")
    {

    }

    SECTION("Testing instruction TXA")
    {

    }

    SECTION("Testing instruction TXS")
    {

    }

    SECTION("Testing instruction TYA")
    {

    }
}

/*
int main()
{
    vm::RAM ram(0x7fff);
    vm::CPU6502 cpu(&ram);
    std::ifstream ramfile;
    ramfile.open("ram_model.ram", std::ios::binary | std::ios::in);
    if(!ramfile.is_open())
    {
        std::cerr << "Cannot load RAM model: Cannot open file ram_model.ram." << std::endl;
        return 1;
    }
    
    int i = 0;
    while(!ramfile.eof())
    {
        if(i >= 0x8000)
        {
            std::cerr << "Cannot load RAM model: Model size is bigger than the RAM is." << std::endl;
            return 1;            
        }
        ramfile >> ram[i++];
    }

    cpu.start();
    std::cout << "Initial state" << std::endl;
    std::cout << cpu.dump() << std::endl;
    int clocks = 0;
    while(cpu.isRunning())
    {
        std::cout << cpu.disassemble() << std::endl;
        int skip = cpu.tick();
        std::cout << "Expression takes " << skip << " clocks. Skipping" << std::flush;
        while (skip > 0)
        {
            ++clocks;
            std::cout << ' ' << skip << std::flush;
            skip = cpu.tick();
        }
        std::cout << std::endl << cpu.dump() << std::endl;
        std::cout << "--- CLOCK TICKS " << clocks << " ---" << std::endl;
    }
       
    return 0;
}
*/