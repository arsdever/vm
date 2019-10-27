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
        ram = {
            0xa9, 0x3c, 0x0a, 0x06, 0x00, 0xa6, 0x00, 0xa2,
            0x02, 0x16, 0x01, 0xa6, 0x03, 0x0e, 0x00, 0x00,
            0xa6, 0x00, 0xa2, 0x02, 0x1e, 0x01, 0x00, 0xa6,
            0x03, 0xa9, 0x01, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a,
            0x0a, 0x0a, 0x0a
            };
        cpu.reset();
        cpu.start();
        REQUIRE(cpu.isRunning());
        //               PC    ACC  XREG  YREG   SR    SP   CLOCK
        CHECK_CPU_STATE(0x00, 0x00, 0x00, 0x00, 0x20, 0xff, 0); // initial
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x02, 0x3c, 0x00, 0x00, 0x20, 0xff, 2); // a9 3c        -> lda #$3c     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x03, 0x78, 0x00, 0x00, 0x20, 0xff, 4); // 0a           -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x05, 0x78, 0x00, 0x00, 0x21, 0xff, 9); // 06 00        -> asl $00      | 2 | 5 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x07, 0x78, 0x52, 0x00, 0x21, 0xff, 12); // a6 00       -> ldx $00      | 2 | 3 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x09, 0x78, 0x02, 0x00, 0x21, 0xff, 14); // a2 02       -> ldx #$02     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x0b, 0x78, 0x02, 0x00, 0x20, 0xff, 20); // 16 01       -> asl $01, x   | 2 | 6 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x0d, 0x78, 0x0c, 0x00, 0x20, 0xff, 23); // a6 03       -> ldx $03      | 2 | 3 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x10, 0x78, 0x0c, 0x00, 0xa0, 0xff, 29); // 0e 00 00    -> asl $0000    | 3 | 6 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x12, 0x78, 0xa4, 0x00, 0xa0, 0xff, 32); // a6 00       -> ldx $01      | 2 | 3 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x14, 0x78, 0x02, 0x00, 0x20, 0xff, 34); // a2 02       -> ldx #$02     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x17, 0x78, 0x02, 0x00, 0x20, 0xff, 41); // 1e 01 00    -> asl $0001, x | 3 | 7 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x19, 0x78, 0x18, 0x00, 0x20, 0xff, 44); // a6 03       -> ldx $03      | 2 | 3 |


        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x1b, 0x01, 0x18, 0x00, 0x20, 0xff, 46); // a9 01       -> lda #$01     | 2 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x1c, 0x02, 0x18, 0x00, 0x20, 0xff, 48); // 0a          -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x1d, 0x04, 0x18, 0x00, 0x20, 0xff, 50); // 0a          -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x1e, 0x08, 0x18, 0x00, 0x20, 0xff, 52); // 0a          -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x1f, 0x10, 0x18, 0x00, 0x20, 0xff, 54); // 0a          -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x20, 0x20, 0x18, 0x00, 0x20, 0xff, 56); // 0a          -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x21, 0x40, 0x18, 0x00, 0x20, 0xff, 58); // 0a          -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x22, 0x80, 0x18, 0x00, 0x20, 0xff, 60); // 0a          -> asl A        | 1 | 2 |
        clocks += executeUntilNextInstruction(cpu);
        CHECK_CPU_STATE(0x23, 0x00, 0x18, 0x00, 0x23, 0xff, 62); // 0a          -> asl A        | 1 | 2 |
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
