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
        flags.c = 0x100 == ((SP ^ n ^ result) & 0x100);
        flags.h = 0x10 == ((SP ^ n ^ result) & 0x10);
        HL = result;
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
    func add_a_hl_ref() ->  void { A = add8bit(A, read(HL)); } // 0x86
    func add_a_n()  ->  void { A = add8bit(A, read_pc()); } // 0xC6

    // ADC A,n
    func adc_a_a()  ->  void { A = adc8bit(A, A); } // 0x8F
    func adc_a_b()  ->  void { A = adc8bit(A, B); } // 0x88
    func adc_a_c()  ->  void { A = adc8bit(A, C); } // 0x89
    func adc_a_d()  ->  void { A = adc8bit(A, D); } // 0x8A
    func adc_a_e()  ->  void { A = adc8bit(A, E); } // 0x8B
    func adc_a_h()  ->  void { A = adc8bit(A, H); } // 0x8C
    func adc_a_l()  ->  void { A = add8bit(A, L); } // 0x8D
    func adc_a_hl_ref() ->  void { A = adc8bit(A, read(HL)); } // 0x8E
    func adc_a_n()  ->  void { A = adc8bit(A, read_pc()); } // 0xCE

    // SUB A, n
    func sub_a_a()  -> void { A = sub8bit(A, A); } // 0x97
    func sub_a_b()  -> void { A = sub8bit(A, B); } // 0x90
    func sub_a_c()  -> void { A = sub8bit(A, C); } // 0x91
    func sub_a_d()  -> void { A = sub8bit(A, D); } // 0x92
    func sub_a_e()  -> void { A = sub8bit(A, E); } // 0x93
    func sub_a_h()  -> void { A = sub8bit(A, H); } // 0x94
    func sub_a_l()  -> void { A = sub8bit(A, L); } // 0x95
    func sub_a_hl_ref() -> void { A = sub8bit(A, read(HL)); } // 0x96
    func sub_a_n()  -> void { A = sub8bit(A, read_pc()); } // 0xD6

    // SBC A, n
    func sbc_a_a()  -> void { A = sbc8bit(A, A); } // 0x97
    func sbc_a_b()  -> void { A = sbc8bit(A, B); } // 0x90
    func sbc_a_c()  -> void { A = sbc8bit(A, C); } // 0x91
    func sbc_a_d()  -> void { A = sbc8bit(A, D); } // 0x92
    func sbc_a_e()  -> void { A = sbc8bit(A, E); } // 0x93
    func sbc_a_h()  -> void { A = sbc8bit(A, H); } // 0x94
    func sbc_a_l()  -> void { A = sbc8bit(A, L); } // 0x95
    func sbc_a_hl_ref() -> void { A = sbc8bit(A, read(HL)); } // 0x96
    func sbc_a_n()  -> void { A = sbc8bit(A, read_pc()); } // 0xD6

    // AND A, n
    func and_a_a()  -> void { A = and8bit(A, A); } // 0xA7
    func and_a_b()  -> void { A = and8bit(A, B); } // 0xA0
    func and_a_c()  -> void { A = and8bit(A, C); } // 0xA1
    func and_a_d()  -> void { A = and8bit(A, D); } // 0xA2
    func and_a_e()  -> void { A = and8bit(A, E); } // 0xA3
    func and_a_h()  -> void { A = and8bit(A, H); } // 0xA4
    func and_a_l()  -> void { A = and8bit(A, L); } // 0xA5
    func and_a_hl_ref() -> void { A = and8bit(A, read(HL)); } // 0xA6
    func and_a_n()  -> void { A = and8bit(A, read_pc()); } // 0xE6

    // OR A, n
    func or_a_a()  -> void { A = or8bit(A, A); } // 0xB7
    func or_a_b()  -> void { A = or8bit(A, B); } // 0xB0
    func or_a_c()  -> void { A = or8bit(A, C); } // 0xB1
    func or_a_d()  -> void { A = or8bit(A, D); } // 0xB2
    func or_a_e()  -> void { A = or8bit(A, E); } // 0xB3
    func or_a_h()  -> void { A = or8bit(A, H); } // 0xB4
    func or_a_l()  -> void { A = or8bit(A, L); } // 0xB5
    func or_a_hl_ref() -> void { A = or8bit(A, read(HL)); } // 0xB6
    func or_a_n()  -> void { A = or8bit(A, read_pc()); } // 0xF6

    // XOR A, n
    func xor_a_a()  -> void { A = xor8bit(A, A); } // 0xAF
    func xor_a_b()  -> void { A = xor8bit(A, B); } // 0xA8
    func xor_a_c()  -> void { A = xor8bit(A, C); } // 0xA9
    func xor_a_d()  -> void { A = xor8bit(A, D); } // 0xAA
    func xor_a_e()  -> void { A = xor8bit(A, E); } // 0xAB
    func xor_a_h()  -> void { A = xor8bit(A, H); } // 0xAC
    func xor_a_l()  -> void { A = xor8bit(A, L); } // 0xAD
    func xor_a_hl_ref() -> void { A = xor8bit(A, read(HL)); } // 0xAE
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
    func cp_a_hl_ref() -> void { (void)sub8bit(A, read(HL)); }
    func cp_a_n()  -> void { (void)sub8bit(A, read_pc()); }

    // INC R
    func inc_a()  -> void { inc(&A); } // 0x3D
    func inc_b()  -> void { inc(&B); } // 0x04
    func inc_c()  -> void { inc(&C); } // 0x0C
    func inc_d()  -> void { inc(&D); } // 0x14
    func inc_e()  -> void { inc(&E); } // 0x1C
    func inc_h()  -> void { inc(&H); } // 0x24
    func inc_l()  -> void { inc(&L); } // 0x2C
    func inc_hl_ref() -> void { u8 val = read(HL); inc(&val); write(HL, val); } // 0x34

    // DEC R
    func dec_a()  -> void { dec(&A); } // 0x3D
    func dec_b()  -> void { dec(&B); } // 0x05
    func dec_c()  -> void { dec(&C); } // 0x0D
    func dec_d()  -> void { dec(&D); } // 0x15
    func dec_e()  -> void { dec(&E); } // 0x1D
    func dec_h()  -> void { dec(&H); } // 0x25
    func dec_l()  -> void { dec(&L); } // 0x2D
    func dec_hl_ref() -> void { u8 val = read(HL); dec(&val); write(HL, val); } // 0x35


    /************************************
     * Section 3.3.4, p. 90: 16-Bit ALU *
     ************************************/

    // ADD HL,RR
    func add_hl_bc() -> void { HL = add16bit(HL, BC); } // 0x09
    func add_hl_de() -> void { HL = add16bit(HL, DE); } // 0x19
    func add_hl_hl() -> void { HL = add16bit(HL, HL); } // 0x29
    func add_hl_sp() -> void { HL = add16bit(HL, SP); } // 0x39

    // ADD SP,n
    func add_sp_n() -> void { // 0xE8
        u8 n = read_pc();
        u32 result = SP + n;
        flags.z = false;
        flags.n = false;
        flags.c = 0x100 == ((SP ^ n ^ result) & 0x100);
        flags.h = 0x10 == ((SP ^ n ^ result) & 0x10);
        SP = result;
    }

    // INC RR
    func inc_bc() -> void { BC++; } // 0x03
    func inc_de() -> void { DE++; } // 0x13
    func inc_hl() -> void { HL++; } // 0x23
    func inc_sp() -> void { SP++; } // 0x33

    // DEC RR
    func dec_bc() -> void { BC--; } // 0x0B
    func dec_de() -> void { DE--; } // 0x1B
    func dec_hl() -> void { HL--; } // 0x2B
    func dec_sp() -> void { SP--; } // 0x3B

    /***************************************
     * Section 3.3.5, p. 94: Miscellaneous *
     ***************************************/

    func swap_a() -> void { A = swap(A); } // 0xCB 37
    func swap_b() -> void { B = swap(B); } // 0xCB 30
    func swap_c() -> void { C = swap(C); } // 0xCB 31
    func swap_d() -> void { D = swap(D); } // 0xCB 32
    func swap_e() -> void { E = swap(E); } // 0xCB 33
    func swap_h() -> void { H = swap(H); } // 0xCB 34
    func swap_l() -> void { L = swap(L); } // 0xCB 35
    func swap_hl_ref() -> void { u8 val = read(HL); A = swap(val); write(HL, val); } // 0xCB 36



    func daa() -> void {  // 0x27
        u16 correction = 0;
        if (flags.h || (!flags.n && ((A & 0x0F) > 0x09)))
            correction |= 0x06;
        if (flags.h || (!flags.n && ((A & 0xFF) > 0x99)))
            correction |= 0x60;

        A += flags.n ? -correction : +correction;

        flags.c = A > 0x99;
        flags.z = A == 0;
        flags.h = false;
    }


    func cpl() -> void { A = ~A; } // 0x2F
    func ccf() -> void { flags.c = ! flags.c; } // 0x3F
    func scf() -> void {F |= 0b001'0000; } // 0x37
    func nop() -> void { } // 0x00
    func halt() -> void { _halt = true; } // 0x76
    func stop() -> void { _stop = true; } // 0x10 00
    func di() -> void { interruptable = false; } // 0xF3
    func ei() -> void { interruptable = true; } // 0xFB

    /******************************************
     * Section 3.3.6, p. 99: Rotates & Shifts *
     ******************************************/

    func rlca() -> void { // 0x07
        flags.c = (A & 0x80);
        A <<= 1;
        A |= flags.c;

        flags.z = A == 0;
        flags.n = false;
        flags.h = false;
    }
    func rla() -> void { // 0x17
        bool carry = (A & 0x80);
        A <<= 1;
        A |= flags.c;

        flags.c = carry;
        flags.z = A == 0;
        flags.n = false;
        flags.h = false;
    }

    func rrca() -> void { // 0x0F
        flags.c = A & 0x01;
        A >>= 1;
        A |= (flags.c << 7);

        flags.z = A == 0;
        flags.n = false;
        flags.h = false;
    }

    func rra() -> void { // 0x1F
        bool carry = (A & 0x01);
        A >>= 1;
        A |= (flags.c << 7);

        flags.c = carry;
        flags.z = A == 0;
        flags.n = false;
        flags.h = false;
    }

    // RLC n
    func rlc_a() -> void { A = rlc(A); } // 0xCB 07
    func rlc_b() -> void { B = rlc(B); } // 0xCB 00
    func rlc_c() -> void { C = rlc(C); } // 0xCB 01
    func rlc_d() -> void { D = rlc(D); } // 0xCB 02
    func rlc_e() -> void { E = rlc(E); } // 0xCB 03
    func rlc_h() -> void { H = rlc(H); } // 0xCB 04
    func rlc_l() -> void { L = rlc(L); } // 0xCB 05
    func rlc_hl_ref() -> void { u16 val = rlc(read(HL)); write(HL, val);  } // 0xCB 06

    // RL n
    func rl_a() -> void { A = rl(A); } // 0xCB 17
    func rl_b() -> void { B = rl(B); } // 0xCB 10
    func rl_c() -> void { C = rl(C); } // 0xCB 11
    func rl_d() -> void { D = rl(D); } // 0xCB 12
    func rl_e() -> void { E = rl(E); } // 0xCB 13
    func rl_h() -> void { H = rl(H); } // 0xCB 14
    func rl_l() -> void { L = rl(L); } // 0xCB 15
    func rl_hl_ref() -> void { u16 val = rl(read(HL)); write(HL, val);  } // 0xCB 16

    // RRC n
    func rrc_a() -> void { A = rrc(A); } // 0xCB 0F
    func rrc_b() -> void { B = rrc(B); } // 0xCB 08
    func rrc_c() -> void { C = rrc(C); } // 0xCB 09
    func rrc_d() -> void { D = rrc(D); } // 0xCB 0A
    func rrc_e() -> void { E = rrc(E); } // 0xCB 0B
    func rrc_h() -> void { H = rrc(H); } // 0xCB 0C
    func rrc_l() -> void { L = rrc(L); } // 0xCB 0D
    func rrc_hl_ref() -> void { u16 val = rrc(read(HL)); write(HL, val);  } // 0xCB 0E

    // RR n
    func rr_a() -> void { A = rr(A); } // 0xCB 1F
    func rr_b() -> void { B = rr(B); } // 0xCB 18
    func rr_c() -> void { C = rr(C); } // 0xCB 19
    func rr_d() -> void { D = rr(D); } // 0xCB 1A
    func rr_e() -> void { E = rr(E); } // 0xCB 1B
    func rr_h() -> void { H = rr(H); } // 0xCB 1C
    func rr_l() -> void { L = rr(L); } // 0xCB 1D
    func rr_hl_ref() -> void { u16 val = rr(read(HL)); write(HL, val);  } // 0xCB 1E

    // SLA n
    func sla_a() -> void { A = sla(A); } // 0xCB 27
    func sla_b() -> void { B = sla(B); } // 0xCB 20
    func sla_c() -> void { C = sla(C); } // 0xCB 21
    func sla_d() -> void { D = sla(D); } // 0xCB 22
    func sla_e() -> void { E = sla(E); } // 0xCB 23
    func sla_h() -> void { H = sla(H); } // 0xCB 24
    func sla_l() -> void { L = sla(L); } // 0xCB 25
    func sla_hl_ref() -> void { u8 val = sla(read(HL)); write(HL, val); } // 0xCB 26

    // SRA n
    func sra_a() -> void { A = sra(A); } // 0xCB 2F
    func sra_b() -> void { B = sra(B); } // 0xCB 28
    func sra_c() -> void { C = sra(C); } // 0xCB 29
    func sra_d() -> void { D = sra(D); } // 0xCB 2A
    func sra_e() -> void { E = sra(E); } // 0xCB 2B
    func sra_h() -> void { H = sra(H); } // 0xCB 2C
    func sra_l() -> void { L = sra(L); } // 0xCB 2D
    func sra_hl_ref() -> void { u8 val = sra(read(HL)); write(HL, val); } // 0xCB 2E

    // SRL n
    func srl_a() -> void { A = srl(A); } // 0xCB 2F
    func srl_b() -> void { B = srl(B); } // 0xCB 28
    func srl_c() -> void { C = srl(C); } // 0xCB 29
    func srl_d() -> void { D = srl(D); } // 0xCB 2A
    func srl_e() -> void { E = srl(E); } // 0xCB 2B
    func srl_h() -> void { H = srl(H); } // 0xCB 2C
    func srl_l() -> void { L = srl(L); } // 0xCB 2D
    func srl_hl_ref() -> void { u8 val = srl(read(HL)); write(HL, val); } // 0xCB 2E



private:
    bool _stop = false;
    bool _halt = false;
    bool interruptable = true;

    /************************************************
     * Helper Functions for Read/Write Instructions *
     ************************************************/

    // Read Program Counter, 8-bit
    [[nodiscard]] inline func read_pc() -> u8 {
        u8 val =  *(mem->mem+PC);
        PC++;
        return val;
    }

    // Read Program Ccounter, 16-bit
    [[nodiscard]] inline func read16_pc() -> u16 {
        u16 val = read_pc();
        val |= read_pc() << 8;
        return val;
    }

    // Read Stack, 8-bit
    [[nodiscard]] inline func read_sp() -> u8 {
        SP++;
        return *(mem->mem+SP);
    }

    // Read Stack, 16-bit
    [[nodiscard]] inline func read16_sp() -> u16 {
        u16 val = read_sp() << 8;
        val |= read_sp();
        return val;
    }

    // Write Stack, 8-bit
    inline func write_sp(u8 val) -> void {
        *(mem->mem+SP) = val;
        SP--;
    }

    // Write Stack, 16-bit
    inline func write16_sp(u16 val) -> void {
        write_sp(val & 0xFF);
        write_sp(val >> 8);
    }

    // Read from arbitrary address, 8-bit
    inline func read(u16 addr) -> u8 {
        return (*(mem->mem)+addr);
    }

    // Write to arbitrary address, 8-bit
    inline func write(i16 addr, u8 val) -> void {
        *(mem->mem+addr) = val;
    }

    // Write to arbitrary address, 16-bit
    inline func write16(u16 addr, u16 val) -> void {
        *(mem->mem+addr)   = (val & 0xFF);
        *(mem->mem+addr+1) = (val >> 8);

    }


    /************************************************
     * Helper Functions for Arithmetic Instructions *
     ************************************************/

    [[nodiscard]] inline func add8bit(u8 op1, u8 op2) -> u8 {
        u16 result = op1 + op2;
        flags.c = 0x100 == ((op1 ^ op2 ^ result) & 0x100);
        flags.h = 0x10 == ((op1 ^ op2 ^ result) & 0x10);
        flags.z = result == 0;
        flags.n = false;
        return (u8)(result & 0xFF);

    }

    [[nodiscard]] inline func adc8bit(u8 op1, u8 op2) -> u8 {
        u16 result = op1 + op2 + flags.c;
        flags.c = 0x100 == ((op1 ^ op2 ^ result) & 0x100);
        flags.h = 0x10 == ((op1 ^ op2 ^ result) & 0x10);
        flags.z = result == 0;
        flags.n = false;
        return (u8)(result & 0xFF);
    }

    [[nodiscard]] inline func add16bit(u16 op1, u16 op2) -> u16 {
        u32 result = op1 + op2;
        flags.n = false;
        flags.c = 0x1'00'00 == ((op1 ^ op2 ^ result) & 0x1'00'00);
        flags.h = 0x10'00 == ((op1 ^ op2 ^ result) & 0x10'00);
        return (u16)result;

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
        flags.h = 0x0F == (*addr & 0x0F);
        (*addr)++;
    }

    inline func dec(u8* addr) -> void {
        (*addr)--;
        flags.z = 0 == *addr;
        flags.n = true;
        flags.h = (*addr & 0x0F) == 0x0F;
    }

    /***************************************************
     * Helper Functions for Miscellaneous Instructions *
     ***************************************************/

    [[nodiscard]] inline func swap(u8 val) -> u8 {
        flags.z = val == 0;
        flags.n = false;
        flags.h = false;
        flags.c = false;

        u8 tmp = val & 0x0F;
        val = val >> 4;
        val = val | (tmp << 4);

        return val;
    }

    /****************************************************
     * Helper Functions for Rotate & Shift Instructions *
     ****************************************************/

    [[nodiscard]] inline func rlc(u8 val) -> u8 {
        flags.c = (val & 0x80);
        val <<= 1;
        val |= flags.c;

        flags.z = val == 0;
        flags.n = false;
        flags.h = false;

        return val;
    }

    [[nodiscard]] inline func rl(u8 val) -> u8 {
        bool carry = (val & 0x80);
        val <<= 1;
        val |= flags.c;

        flags.c = carry;
        flags.z = val == 0;
        flags.n = false;
        flags.h = false;

        return val;
    }

    [[nodiscard]] inline func rrc(u8 val) -> u8 {
        flags.c = val & 0x01;
        val >>= 1;
        val |= (flags.c << 7);

        flags.z = val == 0;
        flags.n = false;
        flags.h = false;

        return val;
    }

    [[nodiscard]] func rr(u8 val) -> u8 { // 0x1F
        bool carry = (val & 0x01);
        val >>= 1;
        val |= (flags.c << 7);

        flags.c = carry;
        flags.z = val == 0;
        flags.n = false;
        flags.h = false;

        return val;
    }

    [[nodiscard]] func sla(u8 val) -> u8 {
        flags.c = (val & 0x80);
        val <<= 1;
        flags.z = val == 0;
        flags.n = false;
        flags.h = false;

        return val;
    }

    [[nodiscard]] func sra(u8 val) -> u8 {
        u8 msb = val & 0x80;
        flags.c = (val & 0x01);
        val >>= 1;
        val |= msb;
        flags.z = val == 0;
        flags.n = false;
        flags.h = false;

        return val;
    }

    [[nodiscard]] func srl(u8 val)-> u8 {
        flags.c = val & 0x01;
        val >>= 1;
        flags.z = val == 0;
        flags.n = false;
        flags.h = false;

        return val;
    }



};