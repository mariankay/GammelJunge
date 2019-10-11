//
// Created by mrn on 06.10.19.
//

// See: http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf


#pragma once

#include <memory.h>
#include "common.h"
#include "memory.hpp"



class CPU {
public:

    CPU()  {
        mem = new Memory();
        PC = 0x100;  // "On power up, the GameBoy Program Counter isinitialized to $100 (100 hex)[...] p. 63
        SP = 0xFFFE; // "The GameBoy stack pointer is initialized to $FFFE onpower up[...]" p. 64
        AF = 0;
        BC = 0;
        DE = 0;
        HL = 0;
    }

    Memory* mem;
    /*************
     * Registers *
     *************/
    union {
        struct {
            union { // F is the Flags-Register; give single bits their flag-name via union
                u8 F;
                struct {
                private:
                    u8 reserved : 4;
                public:
                    bool c : 1;
                    bool h : 1;
                    bool n : 1;
                    bool z : 1;

               } flags;
            };
            u8 A = 0;
        };
            u16 AF;
    };

    union {
        struct {
            u8 C;
            u8 B;
        };
        u16 BC;
    };

    union {
        struct {
            u8 E;
            u8 D;
        };
        u16 DE;
    };

    union {
        struct {
            u8 L;
            u8 H;
        };
        u16 HL;
    };


    u16 SP;
    u16 PC;


    /****************************************************************************
     *                                                                          *
     * CPU Commands are listened in Section 3.3 / Page 65 of the GBC CPU manual *
     *                                                                          *
     ****************************************************************************/


    /*************************************
     * Section 3.3.1, p. 65: 8-Bit Loads *
     *************************************/

    // LD R,n
    func ld_b_n()    -> void { B = read_pc(); } // 0x06
    func ld_c_n()    -> void { C = read_pc(); } // 0x0E
    func ld_d_n()    -> void { D = read_pc(); } // 0x16
    func ld_e_n()    -> void { E = read_pc(); } // 0x1E
    func ld_h_n()    -> void { H = read_pc(); } // 0x26
    func ld_l_n()    -> void { L = read_pc(); } // 0x2E


    // LD R,R
    func ld_a_a() -> void { A = A; } // 0x7F
    func ld_b_a() -> void { B = A; } // 0x47
    func ld_c_a() -> void { C = A; } // 0x4F
    func ld_d_a() -> void { D = A; } // 0x57
    func ld_e_a() -> void { E = A; } // 0x5F
    func ld_h_a() -> void { H = A; } // 0x67
    func ld_l_a() -> void { L = A; } // 0x6F

    func ld_a_b() -> void { A = B; } // 0x78
    func ld_a_c() -> void { A = C; } // 0x79
    func ld_a_d() -> void { A = D; } // 0x7A
    func ld_a_e() -> void { A = E; } // 0x7B
    func ld_a_h() -> void { A = H; } // 0x7C
    func ld_a_l() -> void { A = L; } // 0x7D

    func ld_b_b() -> void { B = B; } // 0x40
    func ld_b_c() -> void { B = C; } // 0x41
    func ld_b_d() -> void { B = D; } // 0x42
    func ld_b_e() -> void { B = E; } // 0x43
    func ld_b_h() -> void { B = H; } // 0x44
    func ld_b_l() -> void { B = L; } // 0x45

    func ld_c_b() -> void { C = B; } // 0x48
    func ld_c_c() -> void { C = C; } // 0x49
    func ld_c_d() -> void { C = D; } // 0x4A
    func ld_c_e() -> void { C = E; } // 0x4B
    func ld_c_h() -> void { C = H; } // 0x4C
    func ld_c_l() -> void { C = L; } // 0x4D

    func ld_d_b() -> void { D = B; } // 0x50
    func ld_d_c() -> void { D = C; } // 0x51
    func ld_d_d() -> void { D = D; } // 0x52
    func ld_d_e() -> void { D = E; } // 0x53
    func ld_d_h() -> void { D = H; } // 0x54
    func ld_d_l() -> void { D = L; } // 0x55

    func ld_e_b() -> void { E = B; } // 0x58
    func ld_e_c() -> void { E = C; } // 0x59
    func ld_e_d() -> void { E = D; } // 0x5A
    func ld_e_e() -> void { E = E; } // 0x5B
    func ld_e_h() -> void { E = H; } // 0x5C
    func ld_e_l() -> void { E = L; } // 0x5D

    func ld_h_b() -> void { H = B; } // 0x60
    func ld_h_c() -> void { H = C; } // 0x61
    func ld_h_d() -> void { H = D; } // 0x62
    func ld_h_e() -> void { H = E; } // 0x63
    func ld_h_h() -> void { H = H; } // 0x64
    func ld_h_l() -> void { H = L; } // 0x65

    func ld_l_b() -> void { L = B; } // 0x68
    func ld_l_c() -> void { L = C; } // 0x69
    func ld_l_d() -> void { L = D; } // 0x6A
    func ld_l_e() -> void { L = E; } // 0x6B
    func ld_l_h() -> void { L = H; } // 0x6C
    func ld_l_l() -> void { L = L; } // 0x6D

    // LD R,(RR)
    func ld_a_hl() -> void { A = read(HL); } // 0x7E
    func ld_b_hl() -> void { B = read(HL); } // 0x46
    func ld_c_hl() -> void { C = read(HL); } // 0x4E
    func ld_d_hl() -> void { D = read(HL); } // 0x56
    func ld_e_hl() -> void { E = read(HL); } // 0x5E
    func ld_h_hl() -> void { H = read(HL); } // 0x66
    func ld_l_hl() -> void { L = read(HL); } // 0x6E

    // LD (RR),R
    func lc_hl_a() -> void { write(HL, A); } // 0x77
    func lc_hl_b() -> void { write(HL, B); } // 0x70
    func lc_hl_c() -> void { write(HL, C); } // 0x71
    func lc_hl_d() -> void { write(HL, D); } // 0x72
    func lc_hl_e() -> void { write(HL, E); } // 0x73
    func lc_hl_h() -> void { write(HL, H); } // 0x74
    func lc_hl_l() -> void { write(HL, L); } // 0x75

    // LD R,(RR)
    func ld_a_bc()   -> void { A = read(BC); }          // 0x0A
    func ld_a_de()   -> void { A = read(DE); }          // 0x1A
    func ld_a_nn()   -> void { A = read(read16_pc()); } // 0xFA

    func ld_bc_a()   -> void { write(BC, A); }           // 0x02
    func ld_de_a()   -> void { write(DE, A); }           // 0x12
    func ld_hl_a()   -> void { write(HL, A); }           // 0x77
    func ld_nn_a()   -> void { write(read16_pc(), A); }  // 0xEA
    func ldh_c_a()   -> void { write(0xFF00 + C, A); }   // 0xE2

    func ld_a_hld() -> void { A = read(HL); HL--; }     // 0x3A
    func ld_hld_a() -> void { write(HL, A); HL--; } // 0x32
    func ld_a_hli() -> void { A = read(HL); H++; }      // 0x2A
    func ld_hli_a() -> void { write(HL, A); HL++; } // 0x22

    func ldh_n_a() -> void { write(0xFF00 + read_pc(), A); } // 0xE0
    func ldh_a_n() -> void { A = read(0xFF00 + read_pc()); }     // 0xF0

    /**************************************
     * Section 3.3.2, p. 76: 16-Bit Loads *
     **************************************/

    // LD RR,nn
    func ld_bc_nn()  -> void {  BC = read16_pc(); } // 0x01
    func ld_de_nn()  -> void {  DE = read16_pc(); } // 0x11
    func ld_hl_nn()  -> void {  HL = read16_pc(); } // 0x21
    func ld_sp_nn()  -> void {  SP = read16_pc(); } // 0x31

    func ld_sp_hl() -> void { SP = HL; } // 0xF9


    /** Surprisingly, this one Load-Command affects the flag register
        while all other load-command don't care for the flags **/
    func ldhl_sp_n() -> void { // 0xF8
        u8 n = read_pc();
        u32 result = SP + n;
        flags.z = false;
        flags.n = false;
        flags.c = 0x100 == ((SP ^ n ^ result) & 0x100u);
        flags.h = 0x10 == ((SP ^ n ^ result) & 0x10u);
    }

    func ld_nn_sp() -> void { write16(read16_pc(), SP); } // 0x08

    func push_af() -> void { write16_sp(AF); } // 0xF5
    func push_bc() -> void { write16_sp(BC); } // 0xC5
    func push_de() -> void { write16_sp(DE); } // 0xD5
    func push_hl() -> void { write16_sp(HL); } // 0xE5

    func pop_af() -> void { AF = read16_sp(); } // 0xF1
    func pop_bc() -> void { BC = read16_sp(); } // 0xC1
    func pop_de() -> void { DE = read16_sp(); } // 0xD!
    func pop_hl() -> void { HL = read16_sp(); } // 0xE1

    /***********************************
     * Section 3.3.3, p. 80: 8-Bit ALU *
     ***********************************/

    // ADD A,n
    func add_a_a()  ->  void { A = add8bit(A, A); } // 0x87
    func add_a_b()  ->  void { A = add8bit(A, B); } // 0x80
    func add_a_c()  ->  void { A = add8bit(A, C); } // 0x81
    func add_a_d()  ->  void { A = add8bit(A, D); } // 0x82
    func add_a_e()  ->  void { A = add8bit(A, E); } // 0x83
    func add_a_h()  ->  void { A = add8bit(A, H); } // 0x84
    func add_a_l()  ->  void { A = add8bit(A, L); } // 0x85
    func add_a_hl() ->  void { A = add8bit(A, read(HL)); } // 0x86
    func add_a_n()  ->  void { A = add8bit(A, read_pc()); } // 0xC6

    // ADC A,n
    func adc_a_a()  ->  void { A = adc8bit(A, A); } // 0x8F
    func adc_a_b()  ->  void { A = adc8bit(A, B); } // 0x88
    func adc_a_c()  ->  void { A = adc8bit(A, C); } // 0x89
    func adc_a_d()  ->  void { A = adc8bit(A, D); } // 0x8A
    func adc_a_e()  ->  void { A = adc8bit(A, E); } // 0x8B
    func adc_a_h()  ->  void { A = adc8bit(A, H); } // 0x8C
    func adc_a_l()  ->  void { A = add8bit(A, L); } // 0x8D
    func adc_a_hl() ->  void { A = adc8bit(A, read(HL)); } // 0x8E
    func adc_a_n()  ->  void { A = adc8bit(A, read_pc()); } // 0xCE

    // SUB A, n
    func sub_a_a()  -> void { A = sub8bit(A, A); } // 0x97
    func sub_a_b()  -> void { A = sub8bit(A, B); } // 0x90
    func sub_a_c()  -> void { A = sub8bit(A, C); } // 0x91
    func sub_a_d()  -> void { A = sub8bit(A, D); } // 0x92
    func sub_a_e()  -> void { A = sub8bit(A, E); } // 0x93
    func sub_a_h()  -> void { A = sub8bit(A, H); } // 0x94
    func sub_a_l()  -> void { A = sub8bit(A, L); } // 0x95
    func sub_a_hl() -> void { A = sub8bit(A, read(HL)); } // 0x96
    func sub_a_n()  -> void { A = sub8bit(A, read_pc()); } // 0xD6

    // SBC A, n
    func sbc_a_a()  -> void { A = sbc8bit(A, A); } // 0x97
    func sbc_a_b()  -> void { A = sbc8bit(A, B); } // 0x90
    func sbc_a_c()  -> void { A = sbc8bit(A, C); } // 0x91
    func sbc_a_d()  -> void { A = sbc8bit(A, D); } // 0x92
    func sbc_a_e()  -> void { A = sbc8bit(A, E); } // 0x93
    func sbc_a_h()  -> void { A = sbc8bit(A, H); } // 0x94
    func sbc_a_l()  -> void { A = sbc8bit(A, L); } // 0x95
    func sbc_a_hl() -> void { A = sbc8bit(A, read(HL)); } // 0x96
    func sbc_a_n()  -> void { A = sbc8bit(A, read_pc()); } // 0xD6

    // AND A, n
    func and_a_a()  -> void { A = and8bit(A, A); } // 0xA7
    func and_a_b()  -> void { A = and8bit(A, B); } // 0xA0
    func and_a_c()  -> void { A = and8bit(A, C); } // 0xA1
    func and_a_d()  -> void { A = and8bit(A, D); } // 0xA2
    func and_a_e()  -> void { A = and8bit(A, E); } // 0xA3
    func and_a_h()  -> void { A = and8bit(A, H); } // 0xA4
    func and_a_l()  -> void { A = and8bit(A, L); } // 0xA5
    func and_a_hl() -> void { A = and8bit(A, read(HL)); } // 0xA6
    func and_a_n()  -> void { A = and8bit(A, read_pc()); } // 0xE6

    // OR A, n
    func or_a_a()  -> void { A = or8bit(A, A); } // 0xB7
    func or_a_b()  -> void { A = or8bit(A, B); } // 0xB0
    func or_a_c()  -> void { A = or8bit(A, C); } // 0xB1
    func or_a_d()  -> void { A = or8bit(A, D); } // 0xB2
    func or_a_e()  -> void { A = or8bit(A, E); } // 0xB3
    func or_a_h()  -> void { A = or8bit(A, H); } // 0xB4
    func or_a_l()  -> void { A = or8bit(A, L); } // 0xB5
    func or_a_hl() -> void { A = or8bit(A, read(HL)); } // 0xB6
    func or_a_n()  -> void { A = or8bit(A, read_pc()); } // 0xF6

    // XOR A, n
    func xor_a_a()  -> void { A = xor8bit(A, A); } // 0xAF
    func xor_a_b()  -> void { A = xor8bit(A, B); } // 0xA8
    func xor_a_c()  -> void { A = xor8bit(A, C); } // 0xA9
    func xor_a_d()  -> void { A = xor8bit(A, D); } // 0xAA
    func xor_a_e()  -> void { A = xor8bit(A, E); } // 0xAB
    func xor_a_h()  -> void { A = xor8bit(A, H); } // 0xAC
    func xor_a_l()  -> void { A = xor8bit(A, L); } // 0xAD
    func xor_a_hl() -> void { A = xor8bit(A, read(HL)); } // 0xAE
    func xor_a_n()  -> void { A = xor8bit(A, read_pc()); } // 0xEE

    // CP A,n
    /* Description of CP command on p. 87:
     * "This is basically an A - n  subtraction instruction but the results are thrown  away."
     */
    func cp_a_a()  -> void { (void)sub8bit(A, A); }
    func cp_a_b()  -> void { (void)sub8bit(A, B); }
    func cp_a_c()  -> void { (void)sub8bit(A, C); }
    func cp_a_d()  -> void { (void)sub8bit(A, D); }
    func cp_a_e()  -> void { (void)sub8bit(A, E); }
    func cp_a_h()  -> void { (void)sub8bit(A, H); }
    func cp_a_l()  -> void { (void)sub8bit(A, L); }
    func cp_a_hl() -> void { (void)sub8bit(A, read(HL)); }
    func cp_a_n()  -> void { (void)sub8bit(A, read_pc()); }

    // INC R
    func inc_a()  -> void { inc(&A); } // 0x3D
    func inc_b()  -> void { inc(&B); } // 0x04
    func inc_c()  -> void { inc(&C); } // 0x0C
    func inc_d()  -> void { inc(&D); } // 0x14
    func inc_e()  -> void { inc(&E); } // 0x1C
    func inc_h()  -> void { inc(&H); } // 0x24
    func inc_l()  -> void { inc(&L); } // 0x2C
    func inc_hl() -> void { u8 val = read(HL); inc(&val); write(HL, val); } // 0x34

    // DEC R
    func dec_a()  -> void { dec(&A); } // 0x3D
    func dec_b()  -> void { dec(&B); } // 0x05
    func dec_c()  -> void { dec(&C); } // 0x0D
    func dec_d()  -> void { dec(&D); } // 0x15
    func dec_e()  -> void { dec(&E); } // 0x1D
    func dec_h()  -> void { dec(&H); } // 0x25
    func dec_l()  -> void { dec(&L); } // 0x2D
    func dec_hl() -> void { u8 val = read(HL); dec(&val); write(HL, val); } // 0x35



    func nop()       -> void { } // 0x00
    func daa() {  printf("Error: Command DAA not implemented. Stopping. "); _stop = true;}
    func stop() { _stop = true; }



private:
    bool _stop = false;

    [[nodiscard]] inline func add8bit(u8 op1, u8 op2) -> u8 {
        u16 result = op1 + op2;
        flags.c = 0x100u == ((op1 ^ op2 ^ result) & 0x100u);
        flags.h = 0x10u == ((op1 ^ op2 ^ result) & 0x10u);
        flags.z = result == 0;
        flags.n = false;
        return (u8)(result & 0xFFu);

    }

    [[nodiscard]] inline func adc8bit(u8 op1, u8 op2) -> u8 {
        u16 result = op1 + op2 + flags.c;
        flags.c = 0x100u == ((op1 ^ op2 ^ result) & 0x100u);
        flags.h = 0x10u == ((op1 ^ op2 ^ result) & 0x10u);
        flags.z = result == 0;
        flags.n = false;
        return (u8)(result & 0xFFu);
    }

    [[nodiscard]] inline func sub8bit(u8 op1, u8 op2) -> u8 {
        flags.c = op1 < op2;
        flags.h = (op1 & 0x0F) < (op2 & 0x0F);
        flags.z = op1 == op2;
        flags.n = true;
        return (u8)(op1 - op2);
    }

    [[nodiscard]] inline func sbc8bit(u8 op1, u8 op2) -> u8 {
        op2 = op2 + flags.c;
        flags.c = op1 < op2;
        flags.h = (op1 & 0x0F) < (op2 & 0x0F);
        flags.z = op1 == op2;
        flags.n = true;
        return (u8)(op1 - op2);
    }

    [[nodiscard]] inline func and8bit(u8 op1, u8 op2) -> u8 {
        u8 result = op1 & op2;
        flags.z = result == 0;
        flags.n = false;
        flags.h = true;
        flags.c = false;
        return result;
    };

    [[nodiscard]] inline func or8bit(u8 op1, u8 op2) -> u8 {
        u8 result = op1 | op2;
        flags.z = result == 0;
        flags.n = false;
        flags.h = false;
        flags.c = false;
        return result;
    }

    [[nodiscard]] inline func xor8bit(u8 op1, u8 op2) -> u8 {
        u8 result = op1 ^ op2;
        flags.z = op1 == 0;
        flags.n = false;
        flags.h = false;
        flags.c = false;
        return result;
    }

    inline func inc(u8* addr) -> void {
        flags.z = 0xFF == *addr;
        flags.n = false;
        flags.h = 0x0F == (*addr & 0x0Fu);
        (*addr)++;
    }

    inline func dec(u8* addr) -> void {
        (*addr)--;
        flags.z = 0 == *addr;
        flags.n = true;
        flags.h = (*addr & 0x0Fu) == 0x0F;
    }


    // Read Program Counter
    [[nodiscard]] inline func read_pc() -> u8 {
        u8 val =  *(mem->mem+PC);
        PC++;
        return val;
    }


    [[nodiscard]] inline func read16_pc() -> u16 {
        u16 val = read_pc();
        val |= (u8)(read_pc() << 8u);
        return val;
    }

    // Read Stack
    [[nodiscard]] inline func read_sp() -> u8 {
        SP++;
        return *(mem->mem+SP);
    }

    [[nodiscard]] inline func read16_sp() -> u16 {
        u16 val = read_sp() << 8u;
        val |= read_sp();
        return val;
    }

    // Write Stack
    inline func write_sp(u8 val) -> void {
        *(mem->mem+SP) = val;
        SP--;
    }

    inline func write16_sp(u16 val) -> void {
        write_sp(val & 0xFFu);
        write_sp(val >> 8u);
    }

    inline func read(u16 addr) -> u8 {
        return (*(mem->mem)+addr);
    }

    inline func write(i16 addr, u8 val) -> void {
        *(mem->mem+addr) = val;
    }

    inline func write16(u16 addr, u16 val) -> void {
        *(mem->mem+addr)   = (val & 0xFFu);
        *(mem->mem+addr+1) = (val >> 8u);

    }
};