//
// Created by mrn on 06.10.19.
//

// See: http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf page 61


#pragma once

#include <memory.h>
#include "common.h"
#include "memory.hpp"



class CPU {
public:

    CPU()  {
        mem = new Memory();
        PC = 0x100;
        SP = 0x0;
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
                    bool c : 1;
                    bool h : 1;
                    bool n : 1;
                    bool z : 1;
                    private: u8 reserved : 4;
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


    /****************
     * CPU Commands *
     ****************/


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

    // LD RR,nn
    func ld_bc_nn()  -> void {  BC = read16_pc(); } // 0x01
    func ld_de_nn()  -> void {  DE = read16_pc(); } // 0x11
    func ld_hl_nn()  -> void {  HL = read16_pc(); } // 0x21
    func ld_sp_nn()  -> void {  SP = read16_pc(); } // 0x31

    func ld_sp_hl() -> void { SP = HL; } // 0xF9

    func ldhl_sp_n() -> void { HL = SP + read_pc(); } // 0xF8 // TODO: Continue here
    // set_flag(FLAG_HALF_CARRY, (((target & 0xF) - (value & 0xF)) < 0));



    func nop()       -> void { } // 0x00
    func daa() {  printf("Error: Command DAA not implemented. Stopping. "); _stop = true;}
    func stop() { _stop = true; }



private:
    bool _stop = false;

    inline func read_pc() -> u8 {

        u8 val =  *(mem->mem+PC);
        PC++;
        return val;
    }

    // TODO: is it correct order?
    inline func read16_pc() -> u16 {
        u16 val;
        val = read_pc() << 8u;
        val |= read_pc();

        return val;
    }

    inline func inc(u8* reg) -> void {
        flags.n = false;
        (*reg)++;
    }

    inline func inc(u16* reg) -> void {

        (*reg)++;
    }

    inline func dec(u8* reg) -> void {
        flags.n = true;
        (*reg)--;
    }

    inline func dec(u16* reg) -> void {
        (*reg)--;
    }


    inline func read(u16 addr) -> u8 {
        return (*(mem->mem)+addr);
    }

    inline func write(i16 addr, u8 val) -> void {
        *(mem->mem+addr) = val;
    }

    inline func write16(u16 addr, u16 val) -> void {
        *(mem->mem+addr) = val;
    }

    inline func sub(u8* reg, u8 val) -> void {
        flags.c = true;
        *reg -= val;
    }

    inline func sub(u16* reg, u8 val) -> void {
        flags.n = true;
        *reg -= val;
    }

    inline func add(u8* reg, u8 val) -> void {
        flags.n = false;
        *reg += val;
    }
    inline func add(u16* reg, u8 val) -> void {
        flags.n = false;
        *reg += val;
    }
};