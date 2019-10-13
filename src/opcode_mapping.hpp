//
// Created by mrn on 13/10/2019.
//

#pragma once
#include "common.h"
#include "cpu.hpp"
#include <map>



func init(CPU& cpu) -> void {

    cpu.opcodes[0x3E] = &CPU::ld_a_n;
    cpu.opcodes[0x06] = &CPU::ld_b_n;
    cpu.opcodes[0x0E] = &CPU::ld_c_n;
    cpu.opcodes[0x16] = &CPU::ld_d_n;
    cpu.opcodes[0x1E] = &CPU::ld_e_n;
    cpu.opcodes[0x26] = &CPU::ld_h_n;
    cpu.opcodes[0x2E] = &CPU::ld_l_n;
    cpu.opcodes[0x7F] = &CPU::ld_a_a;
    cpu.opcodes[0x47] = &CPU::ld_b_a;
    cpu.opcodes[0x4F] = &CPU::ld_c_a;
    cpu.opcodes[0x57] = &CPU::ld_d_a;
    cpu.opcodes[0x5F] = &CPU::ld_e_a;
    cpu.opcodes[0x67] = &CPU::ld_h_a;
    cpu.opcodes[0x6F] = &CPU::ld_l_a;
    cpu.opcodes[0x78] = &CPU::ld_a_b;
    cpu.opcodes[0x79] = &CPU::ld_a_c;
    cpu.opcodes[0x7A] = &CPU::ld_a_d;
    cpu.opcodes[0x7B] = &CPU::ld_a_e;
    cpu.opcodes[0x7C] = &CPU::ld_a_h;
    cpu.opcodes[0x7D] = &CPU::ld_a_l;
    cpu.opcodes[0x40] = &CPU::ld_b_b;
    cpu.opcodes[0x41] = &CPU::ld_b_c;
    cpu.opcodes[0x42] = &CPU::ld_b_d;
    cpu.opcodes[0x43] = &CPU::ld_b_e;
    cpu.opcodes[0x44] = &CPU::ld_b_h;
    cpu.opcodes[0x45] = &CPU::ld_b_l;
    cpu.opcodes[0x48] = &CPU::ld_c_b;
    cpu.opcodes[0x49] = &CPU::ld_c_c;
    cpu.opcodes[0x4A] = &CPU::ld_c_d;
    cpu.opcodes[0x4B] = &CPU::ld_c_e;
    cpu.opcodes[0x4C] = &CPU::ld_c_h;
    cpu.opcodes[0x4D] = &CPU::ld_c_l;
    cpu.opcodes[0x50] = &CPU::ld_d_b;
    cpu.opcodes[0x51] = &CPU::ld_d_c;
    cpu.opcodes[0x52] = &CPU::ld_d_d;
    cpu.opcodes[0x53] = &CPU::ld_d_e;
    cpu.opcodes[0x54] = &CPU::ld_d_h;
    cpu.opcodes[0x55] = &CPU::ld_d_l;
    cpu.opcodes[0x58] = &CPU::ld_e_b;
    cpu.opcodes[0x59] = &CPU::ld_e_c;
    cpu.opcodes[0x5A] = &CPU::ld_e_d;
    cpu.opcodes[0x5B] = &CPU::ld_e_e;
    cpu.opcodes[0x5C] = &CPU::ld_e_h;
    cpu.opcodes[0x5D] = &CPU::ld_e_l;
    cpu.opcodes[0x60] = &CPU::ld_h_b;
    cpu.opcodes[0x61] = &CPU::ld_h_c;
    cpu.opcodes[0x62] = &CPU::ld_h_d;
    cpu.opcodes[0x63] = &CPU::ld_h_e;
    cpu.opcodes[0x64] = &CPU::ld_h_h;
    cpu.opcodes[0x65] = &CPU::ld_h_l;
    cpu.opcodes[0x68] = &CPU::ld_l_b;
    cpu.opcodes[0x69] = &CPU::ld_l_c;
    cpu.opcodes[0x6A] = &CPU::ld_l_d;
    cpu.opcodes[0x6B] = &CPU::ld_l_e;
    cpu.opcodes[0x6C] = &CPU::ld_l_h;
    cpu.opcodes[0x6D] = &CPU::ld_l_l;
    cpu.opcodes[0x7E] = &CPU::ld_a_hl;
    cpu.opcodes[0x46] = &CPU::ld_b_hl;
    cpu.opcodes[0x4E] = &CPU::ld_c_hl;
    cpu.opcodes[0x56] = &CPU::ld_d_hl;
    cpu.opcodes[0x5E] = &CPU::ld_e_hl;
    cpu.opcodes[0x66] = &CPU::ld_h_hl;
    cpu.opcodes[0x6E] = &CPU::ld_l_hl;
    cpu.opcodes[0x77] = &CPU::ld_hl_a;
    cpu.opcodes[0x70] = &CPU::ld_hl_b;
    cpu.opcodes[0x71] = &CPU::ld_hl_c;
    cpu.opcodes[0x72] = &CPU::ld_hl_d;
    cpu.opcodes[0x73] = &CPU::ld_hl_e;
    cpu.opcodes[0x74] = &CPU::ld_hl_h;
    cpu.opcodes[0x75] = &CPU::ld_hl_l;
    cpu.opcodes[0x36] = &CPU::ld_hl_n;
    cpu.opcodes[0x0A] = &CPU::ld_a_bc;
    cpu.opcodes[0x1A] = &CPU::ld_a_de;
    cpu.opcodes[0xFA] = &CPU::ld_a_nn;
    cpu.opcodes[0x02] = &CPU::ld_bc_a;
    cpu.opcodes[0x12] = &CPU::ld_de_a;
    cpu.opcodes[0xEA] = &CPU::ld_nn_a;
    cpu.opcodes[0xE2] = &CPU::ldh_c_a;
    cpu.opcodes[0xF2] = &CPU::ldh_a_c;
    cpu.opcodes[0x3A] = &CPU::ld_a_hld;
    cpu.opcodes[0x32] = &CPU::ld_hld_a;
    cpu.opcodes[0x2A] = &CPU::ld_a_hli;
    cpu.opcodes[0x22] = &CPU::ld_hli_a;
    cpu.opcodes[0xE0] = &CPU::ldh_n_a;
    cpu.opcodes[0xF0] = &CPU::ldh_a_n;
    cpu.opcodes[0x01] = &CPU::ld_bc_nn;
    cpu.opcodes[0x11] = &CPU::ld_de_nn;
    cpu.opcodes[0x21] = &CPU::ld_hl_nn;
    cpu.opcodes[0x31] = &CPU::ld_sp_nn;
    cpu.opcodes[0xF9] = &CPU::ld_sp_hl;
    cpu.opcodes[0xF8] = &CPU::ldhl_sp_n;
    cpu.opcodes[0x08] = &CPU::ld_nn_sp;
    cpu.opcodes[0xF5] = &CPU::push_af;
    cpu.opcodes[0xC5] = &CPU::push_bc;
    cpu.opcodes[0xD5] = &CPU::push_de;
    cpu.opcodes[0xE5] = &CPU::push_hl;
    cpu.opcodes[0xF1] = &CPU::pop_af;
    cpu.opcodes[0xC1] = &CPU::pop_bc;
    cpu.opcodes[0xD1] = &CPU::pop_de;
    cpu.opcodes[0xE1] = &CPU::pop_hl;
    cpu.opcodes[0x87] = &CPU::add_a_a;
    cpu.opcodes[0x80] = &CPU::add_a_b;
    cpu.opcodes[0x81] = &CPU::add_a_c;
    cpu.opcodes[0x82] = &CPU::add_a_d;
    cpu.opcodes[0x83] = &CPU::add_a_e;
    cpu.opcodes[0x84] = &CPU::add_a_h;
    cpu.opcodes[0x85] = &CPU::add_a_l;
    cpu.opcodes[0x86] = &CPU::add_a_hl_ref;
    cpu.opcodes[0xC6] = &CPU::add_a_n;
    cpu.opcodes[0x8F] = &CPU::adc_a_a;
    cpu.opcodes[0x88] = &CPU::adc_a_b;
    cpu.opcodes[0x89] = &CPU::adc_a_c;
    cpu.opcodes[0x8A] = &CPU::adc_a_d;
    cpu.opcodes[0x8B] = &CPU::adc_a_e;
    cpu.opcodes[0x8C] = &CPU::adc_a_h;
    cpu.opcodes[0x8D] = &CPU::adc_a_l;
    cpu.opcodes[0x8E] = &CPU::adc_a_hl_ref;
    cpu.opcodes[0xCE] = &CPU::adc_a_n;
    cpu.opcodes[0x97] = &CPU::sub_a_a;
    cpu.opcodes[0x90] = &CPU::sub_a_b;
    cpu.opcodes[0x91] = &CPU::sub_a_c;
    cpu.opcodes[0x92] = &CPU::sub_a_d;
    cpu.opcodes[0x93] = &CPU::sub_a_e;
    cpu.opcodes[0x94] = &CPU::sub_a_h;
    cpu.opcodes[0x95] = &CPU::sub_a_l;
    cpu.opcodes[0x96] = &CPU::sub_a_hl_ref;
    cpu.opcodes[0xD6] = &CPU::sub_a_n;
    cpu.opcodes[0x9F] = &CPU::sbc_a_a;
    cpu.opcodes[0x98] = &CPU::sbc_a_b;
    cpu.opcodes[0x99] = &CPU::sbc_a_c;
    cpu.opcodes[0x9A] = &CPU::sbc_a_d;
    cpu.opcodes[0x9B] = &CPU::sbc_a_e;
    cpu.opcodes[0x9C] = &CPU::sbc_a_h;
    cpu.opcodes[0x9D] = &CPU::sbc_a_l;
    cpu.opcodes[0x9E] = &CPU::sbc_a_hl_ref;
    cpu.opcodes[0xDE] = &CPU::sbc_a_n;
    cpu.opcodes[0xA7] = &CPU::and_a_a;
    cpu.opcodes[0xA0] = &CPU::and_a_b;
    cpu.opcodes[0xA1] = &CPU::and_a_c;
    cpu.opcodes[0xA2] = &CPU::and_a_d;
    cpu.opcodes[0xA3] = &CPU::and_a_e;
    cpu.opcodes[0xA4] = &CPU::and_a_h;
    cpu.opcodes[0xA5] = &CPU::and_a_l;
    cpu.opcodes[0xA6] = &CPU::and_a_hl_ref;
    cpu.opcodes[0xE6] = &CPU::and_a_n;
    cpu.opcodes[0xB7] = &CPU::or_a_a;
    cpu.opcodes[0xB0] = &CPU::or_a_b;
    cpu.opcodes[0xB1] = &CPU::or_a_c;
    cpu.opcodes[0xB2] = &CPU::or_a_d;
    cpu.opcodes[0xB3] = &CPU::or_a_e;
    cpu.opcodes[0xB4] = &CPU::or_a_h;
    cpu.opcodes[0xB5] = &CPU::or_a_l;
    cpu.opcodes[0xB6] = &CPU::or_a_hl_ref;
    cpu.opcodes[0xF6] = &CPU::or_a_n;
    cpu.opcodes[0xAF] = &CPU::xor_a_a;
    cpu.opcodes[0xA8] = &CPU::xor_a_b;
    cpu.opcodes[0xA9] = &CPU::xor_a_c;
    cpu.opcodes[0xAA] = &CPU::xor_a_d;
    cpu.opcodes[0xAB] = &CPU::xor_a_e;
    cpu.opcodes[0xAC] = &CPU::xor_a_h;
    cpu.opcodes[0xAD] = &CPU::xor_a_l;
    cpu.opcodes[0xAE] = &CPU::xor_a_hl_ref;
    cpu.opcodes[0xEE] = &CPU::xor_a_n;
    cpu.opcodes[0xBF] = &CPU::cp_a_a;
    cpu.opcodes[0xB8] = &CPU::cp_a_b;
    cpu.opcodes[0xB9] = &CPU::cp_a_c;
    cpu.opcodes[0xBA] = &CPU::cp_a_d;
    cpu.opcodes[0xBB] = &CPU::cp_a_e;
    cpu.opcodes[0xBC] = &CPU::cp_a_h;
    cpu.opcodes[0xBD] = &CPU::cp_a_l;
    cpu.opcodes[0xBE] = &CPU::cp_a_hl_ref;
    cpu.opcodes[0xFE] = &CPU::cp_a_n;
    cpu.opcodes[0x3C] = &CPU::inc_a;
    cpu.opcodes[0x04] = &CPU::inc_b;
    cpu.opcodes[0x0C] = &CPU::inc_c;
    cpu.opcodes[0x14] = &CPU::inc_d;
    cpu.opcodes[0x1C] = &CPU::inc_e;
    cpu.opcodes[0x24] = &CPU::inc_h;
    cpu.opcodes[0x2C] = &CPU::inc_l;
    cpu.opcodes[0x34] = &CPU::inc_hl_ref;
    cpu.opcodes[0x3D] = &CPU::dec_a;
    cpu.opcodes[0x05] = &CPU::dec_b;
    cpu.opcodes[0x0D] = &CPU::dec_c;
    cpu.opcodes[0x15] = &CPU::dec_d;
    cpu.opcodes[0x1D] = &CPU::dec_e;
    cpu.opcodes[0x25] = &CPU::dec_h;
    cpu.opcodes[0x2D] = &CPU::dec_l;
    cpu.opcodes[0x35] = &CPU::dec_hl_ref;
    cpu.opcodes[0x09] = &CPU::add_hl_bc;
    cpu.opcodes[0x19] = &CPU::add_hl_de;
    cpu.opcodes[0x29] = &CPU::add_hl_hl;
    cpu.opcodes[0x39] = &CPU::add_hl_sp;
    cpu.opcodes[0xE8] = &CPU::add_sp_n;
    cpu.opcodes[0x03] = &CPU::inc_bc;
    cpu.opcodes[0x13] = &CPU::inc_de;
    cpu.opcodes[0x23] = &CPU::inc_hl;
    cpu.opcodes[0x33] = &CPU::inc_sp;
    cpu.opcodes[0x0B] = &CPU::dec_bc;
    cpu.opcodes[0x1B] = &CPU::dec_de;
    cpu.opcodes[0x2B] = &CPU::dec_hl;
    cpu.opcodes[0x3B] = &CPU::dec_sp;
    cpu.opcodes[0x27] = &CPU::daa;
    cpu.opcodes[0x2F] = &CPU::cpl;
    cpu.opcodes[0x3F] = &CPU::ccf;
    cpu.opcodes[0x37] = &CPU::scf;
    cpu.opcodes[0x00] = &CPU::nop;
    cpu.opcodes[0x76] = &CPU::halt;
    cpu.opcodes[0x10] = &CPU::stop;
    cpu.opcodes[0xF3] = &CPU::di;
    cpu.opcodes[0xFB] = &CPU::ei;
    cpu.opcodes[0x07] = &CPU::rlca;
    cpu.opcodes[0x17] = &CPU::rla;
    cpu.opcodes[0x0F] = &CPU::rrca;
    cpu.opcodes[0x1F] = &CPU::rra;
    cpu.opcodes[0xC3] = &CPU::jp_nn;
    cpu.opcodes[0xC2] = &CPU::jp_nz_nn;
    cpu.opcodes[0xCA] = &CPU::jp_z_nn;
    cpu.opcodes[0xD2] = &CPU::jp_nc_nn;
    cpu.opcodes[0xDA] = &CPU::jp_c_nn;
    cpu.opcodes[0xE9] = &CPU::jp_hl;
    cpu.opcodes[0x18] = &CPU::jr_n;
    cpu.opcodes[0x20] = &CPU::jr_nz_n;
    cpu.opcodes[0x28] = &CPU::jr_z_n;
    cpu.opcodes[0x30] = &CPU::jr_nc_n;
    cpu.opcodes[0x38] = &CPU::jr_c_n;
    cpu.opcodes[0xCD] = &CPU::call_nn;
    cpu.opcodes[0xC4] = &CPU::call_nz_nn;
    cpu.opcodes[0xCC] = &CPU::call_z_nn;
    cpu.opcodes[0xD4] = &CPU::call_nc_nn;
    cpu.opcodes[0xDC] = &CPU::call_c_nn;
    cpu.opcodes[0xC7] = &CPU::rst_00;
    cpu.opcodes[0xCF] = &CPU::rst_08;
    cpu.opcodes[0xD7] = &CPU::rst_10;
    cpu.opcodes[0xDF] = &CPU::rst_18;
    cpu.opcodes[0xE7] = &CPU::rst_20;
    cpu.opcodes[0xEF] = &CPU::rst_28;
    cpu.opcodes[0xF7] = &CPU::rst_30;
    cpu.opcodes[0xFF] = &CPU::rst_38;
    cpu.opcodes[0xC9] = &CPU::ret;
    cpu.opcodes[0xC0] = &CPU::ret_nz;
    cpu.opcodes[0xC8] = &CPU::ret_z;
    cpu.opcodes[0xD0] = &CPU::ret_nc;
    cpu.opcodes[0xD8] = &CPU::ret_c;
    cpu.opcodes[0xD9] = &CPU::reti;

    // EXT (CB Prefix)

    cpu.ext_opcodes[0x37] = &CPU::swap_a;
    cpu.ext_opcodes[0x30] = &CPU::swap_b;
    cpu.ext_opcodes[0x31] = &CPU::swap_c;
    cpu.ext_opcodes[0x32] = &CPU::swap_d;
    cpu.ext_opcodes[0x33] = &CPU::swap_e;
    cpu.ext_opcodes[0x34] = &CPU::swap_h;
    cpu.ext_opcodes[0x35] = &CPU::swap_l;
    cpu.ext_opcodes[0x36] = &CPU::swap_hl_ref;
    cpu.ext_opcodes[0x07] = &CPU::rlc_a;
    cpu.ext_opcodes[0x00] = &CPU::rlc_b;
    cpu.ext_opcodes[0x01] = &CPU::rlc_c;
    cpu.ext_opcodes[0x02] = &CPU::rlc_d;
    cpu.ext_opcodes[0x03] = &CPU::rlc_e;
    cpu.ext_opcodes[0x04] = &CPU::rlc_h;
    cpu.ext_opcodes[0x05] = &CPU::rlc_l;
    cpu.ext_opcodes[0x06] = &CPU::rlc_hl_ref;
    cpu.ext_opcodes[0x17] = &CPU::rl_a;
    cpu.ext_opcodes[0x10] = &CPU::rl_b;
    cpu.ext_opcodes[0x11] = &CPU::rl_c;
    cpu.ext_opcodes[0x12] = &CPU::rl_d;
    cpu.ext_opcodes[0x13] = &CPU::rl_e;
    cpu.ext_opcodes[0x14] = &CPU::rl_h;
    cpu.ext_opcodes[0x15] = &CPU::rl_l;
    cpu.ext_opcodes[0x16] = &CPU::rl_hl_ref;
    cpu.ext_opcodes[0x0F] = &CPU::rrc_a;
    cpu.ext_opcodes[0x08] = &CPU::rrc_b;
    cpu.ext_opcodes[0x09] = &CPU::rrc_c;
    cpu.ext_opcodes[0x0A] = &CPU::rrc_d;
    cpu.ext_opcodes[0x0B] = &CPU::rrc_e;
    cpu.ext_opcodes[0x0C] = &CPU::rrc_h;
    cpu.ext_opcodes[0x0D] = &CPU::rrc_l;
    cpu.ext_opcodes[0x0E] = &CPU::rrc_hl_ref;
    cpu.ext_opcodes[0x1F] = &CPU::rr_a;
    cpu.ext_opcodes[0x18] = &CPU::rr_b;
    cpu.ext_opcodes[0x19] = &CPU::rr_c;
    cpu.ext_opcodes[0x1A] = &CPU::rr_d;
    cpu.ext_opcodes[0x1B] = &CPU::rr_e;
    cpu.ext_opcodes[0x1C] = &CPU::rr_h;
    cpu.ext_opcodes[0x1D] = &CPU::rr_l;
    cpu.ext_opcodes[0x1E] = &CPU::rr_hl_ref;
    cpu.ext_opcodes[0x27] = &CPU::sla_a;
    cpu.ext_opcodes[0x20] = &CPU::sla_b;
    cpu.ext_opcodes[0x21] = &CPU::sla_c;
    cpu.ext_opcodes[0x22] = &CPU::sla_d;
    cpu.ext_opcodes[0x23] = &CPU::sla_e;
    cpu.ext_opcodes[0x24] = &CPU::sla_h;
    cpu.ext_opcodes[0x25] = &CPU::sla_l;
    cpu.ext_opcodes[0x26] = &CPU::sla_hl_ref;
    cpu.ext_opcodes[0x2F] = &CPU::sra_a;
    cpu.ext_opcodes[0x28] = &CPU::sra_b;
    cpu.ext_opcodes[0x29] = &CPU::sra_c;
    cpu.ext_opcodes[0x2A] = &CPU::sra_d;
    cpu.ext_opcodes[0x2B] = &CPU::sra_e;
    cpu.ext_opcodes[0x2C] = &CPU::sra_h;
    cpu.ext_opcodes[0x2D] = &CPU::sra_l;
    cpu.ext_opcodes[0x2E] = &CPU::sra_hl_ref;
    cpu.ext_opcodes[0x3F] = &CPU::srl_a;
    cpu.ext_opcodes[0x38] = &CPU::srl_b;
    cpu.ext_opcodes[0x39] = &CPU::srl_c;
    cpu.ext_opcodes[0x3A] = &CPU::srl_d;
    cpu.ext_opcodes[0x3B] = &CPU::srl_e;
    cpu.ext_opcodes[0x3C] = &CPU::srl_h;
    cpu.ext_opcodes[0x3D] = &CPU::srl_l;
    cpu.ext_opcodes[0x3E] = &CPU::srl_hl_ref;
    cpu.ext_opcodes[0x47] = &CPU::bit_a_0;
    cpu.ext_opcodes[0x40] = &CPU::bit_b_0;
    cpu.ext_opcodes[0x41] = &CPU::bit_c_0;
    cpu.ext_opcodes[0x42] = &CPU::bit_d_0;
    cpu.ext_opcodes[0x43] = &CPU::bit_e_0;
    cpu.ext_opcodes[0x44] = &CPU::bit_h_0;
    cpu.ext_opcodes[0x45] = &CPU::bit_l_0;
    cpu.ext_opcodes[0x46] = &CPU::bit_hl_ref_0;
    cpu.ext_opcodes[0x4F] = &CPU::bit_a_1;
    cpu.ext_opcodes[0x48] = &CPU::bit_b_1;
    cpu.ext_opcodes[0x49] = &CPU::bit_c_1;
    cpu.ext_opcodes[0x4A] = &CPU::bit_d_1;
    cpu.ext_opcodes[0x4B] = &CPU::bit_e_1;
    cpu.ext_opcodes[0x4C] = &CPU::bit_h_1;
    cpu.ext_opcodes[0x4D] = &CPU::bit_l_1;
    cpu.ext_opcodes[0x4E] = &CPU::bit_hl_ref_1;
    cpu.ext_opcodes[0x57] = &CPU::bit_a_2;
    cpu.ext_opcodes[0x50] = &CPU::bit_b_2;
    cpu.ext_opcodes[0x51] = &CPU::bit_c_2;
    cpu.ext_opcodes[0x52] = &CPU::bit_d_2;
    cpu.ext_opcodes[0x53] = &CPU::bit_e_2;
    cpu.ext_opcodes[0x54] = &CPU::bit_h_2;
    cpu.ext_opcodes[0x55] = &CPU::bit_l_2;
    cpu.ext_opcodes[0x56] = &CPU::bit_hl_ref_2;
    cpu.ext_opcodes[0x5F] = &CPU::bit_a_3;
    cpu.ext_opcodes[0x58] = &CPU::bit_b_3;
    cpu.ext_opcodes[0x59] = &CPU::bit_c_3;
    cpu.ext_opcodes[0x5A] = &CPU::bit_d_3;
    cpu.ext_opcodes[0x5B] = &CPU::bit_e_3;
    cpu.ext_opcodes[0x5C] = &CPU::bit_h_3;
    cpu.ext_opcodes[0x5D] = &CPU::bit_l_3;
    cpu.ext_opcodes[0x5E] = &CPU::bit_hl_ref_3;
    cpu.ext_opcodes[0x67] = &CPU::bit_a_4;
    cpu.ext_opcodes[0x60] = &CPU::bit_b_4;
    cpu.ext_opcodes[0x61] = &CPU::bit_c_4;
    cpu.ext_opcodes[0x62] = &CPU::bit_d_4;
    cpu.ext_opcodes[0x63] = &CPU::bit_e_4;
    cpu.ext_opcodes[0x64] = &CPU::bit_h_4;
    cpu.ext_opcodes[0x65] = &CPU::bit_l_4;
    cpu.ext_opcodes[0x66] = &CPU::bit_hl_ref_4;
    cpu.ext_opcodes[0x6F] = &CPU::bit_a_5;
    cpu.ext_opcodes[0x68] = &CPU::bit_b_5;
    cpu.ext_opcodes[0x69] = &CPU::bit_c_5;
    cpu.ext_opcodes[0x6A] = &CPU::bit_d_5;
    cpu.ext_opcodes[0x6B] = &CPU::bit_e_5;
    cpu.ext_opcodes[0x6C] = &CPU::bit_h_5;
    cpu.ext_opcodes[0x6D] = &CPU::bit_l_5;
    cpu.ext_opcodes[0x6E] = &CPU::bit_hl_ref_5;
    cpu.ext_opcodes[0x77] = &CPU::bit_a_6;
    cpu.ext_opcodes[0x70] = &CPU::bit_b_6;
    cpu.ext_opcodes[0x71] = &CPU::bit_c_6;
    cpu.ext_opcodes[0x72] = &CPU::bit_d_6;
    cpu.ext_opcodes[0x73] = &CPU::bit_e_6;
    cpu.ext_opcodes[0x74] = &CPU::bit_h_6;
    cpu.ext_opcodes[0x75] = &CPU::bit_l_6;
    cpu.ext_opcodes[0x76] = &CPU::bit_hl_ref_6;
    cpu.ext_opcodes[0x7F] = &CPU::bit_a_7;
    cpu.ext_opcodes[0x78] = &CPU::bit_b_7;
    cpu.ext_opcodes[0x79] = &CPU::bit_c_7;
    cpu.ext_opcodes[0x7A] = &CPU::bit_d_7;
    cpu.ext_opcodes[0x7B] = &CPU::bit_e_7;
    cpu.ext_opcodes[0x7C] = &CPU::bit_h_7;
    cpu.ext_opcodes[0x7D] = &CPU::bit_l_7;
    cpu.ext_opcodes[0x7E] = &CPU::bit_hl_ref_7;
    cpu.ext_opcodes[0x87] = &CPU::res_a_0;
    cpu.ext_opcodes[0x80] = &CPU::res_b_0;
    cpu.ext_opcodes[0x81] = &CPU::res_c_0;
    cpu.ext_opcodes[0x82] = &CPU::res_d_0;
    cpu.ext_opcodes[0x83] = &CPU::res_e_0;
    cpu.ext_opcodes[0x84] = &CPU::res_h_0;
    cpu.ext_opcodes[0x85] = &CPU::res_l_0;
    cpu.ext_opcodes[0x86] = &CPU::res_hl_ref_0;
    cpu.ext_opcodes[0x8F] = &CPU::res_a_1;
    cpu.ext_opcodes[0x88] = &CPU::res_b_1;
    cpu.ext_opcodes[0x89] = &CPU::res_c_1;
    cpu.ext_opcodes[0x8A] = &CPU::res_d_1;
    cpu.ext_opcodes[0x8B] = &CPU::res_e_1;
    cpu.ext_opcodes[0x8C] = &CPU::res_h_1;
    cpu.ext_opcodes[0x8D] = &CPU::res_l_1;
    cpu.ext_opcodes[0x8E] = &CPU::res_hl_ref_1;
    cpu.ext_opcodes[0x97] = &CPU::res_a_2;
    cpu.ext_opcodes[0x90] = &CPU::res_b_2;
    cpu.ext_opcodes[0x91] = &CPU::res_c_2;
    cpu.ext_opcodes[0x92] = &CPU::res_d_2;
    cpu.ext_opcodes[0x93] = &CPU::res_e_2;
    cpu.ext_opcodes[0x94] = &CPU::res_h_2;
    cpu.ext_opcodes[0x95] = &CPU::res_l_2;
    cpu.ext_opcodes[0x96] = &CPU::res_hl_ref_2;
    cpu.ext_opcodes[0x9F] = &CPU::res_a_3;
    cpu.ext_opcodes[0x98] = &CPU::res_b_3;
    cpu.ext_opcodes[0x99] = &CPU::res_c_3;
    cpu.ext_opcodes[0x9A] = &CPU::res_d_3;
    cpu.ext_opcodes[0x9B] = &CPU::res_e_3;
    cpu.ext_opcodes[0x9C] = &CPU::res_h_3;
    cpu.ext_opcodes[0x9D] = &CPU::res_l_3;
    cpu.ext_opcodes[0x9E] = &CPU::res_hl_ref_3;
    cpu.ext_opcodes[0xA7] = &CPU::res_a_4;
    cpu.ext_opcodes[0xA0] = &CPU::res_b_4;
    cpu.ext_opcodes[0xA1] = &CPU::res_c_4;
    cpu.ext_opcodes[0xA2] = &CPU::res_d_4;
    cpu.ext_opcodes[0xA3] = &CPU::res_e_4;
    cpu.ext_opcodes[0xA4] = &CPU::res_h_4;
    cpu.ext_opcodes[0xA5] = &CPU::res_l_4;
    cpu.ext_opcodes[0xA6] = &CPU::res_hl_ref_4;
    cpu.ext_opcodes[0xAF] = &CPU::res_a_5;
    cpu.ext_opcodes[0xA8] = &CPU::res_b_5;
    cpu.ext_opcodes[0xA9] = &CPU::res_c_5;
    cpu.ext_opcodes[0xAA] = &CPU::res_d_5;
    cpu.ext_opcodes[0xAB] = &CPU::res_e_5;
    cpu.ext_opcodes[0xAC] = &CPU::res_h_5;
    cpu.ext_opcodes[0xAD] = &CPU::res_l_5;
    cpu.ext_opcodes[0xAE] = &CPU::res_hl_ref_5;
    cpu.ext_opcodes[0xB7] = &CPU::res_a_6;
    cpu.ext_opcodes[0xB0] = &CPU::res_b_6;
    cpu.ext_opcodes[0xB1] = &CPU::res_c_6;
    cpu.ext_opcodes[0xB2] = &CPU::res_d_6;
    cpu.ext_opcodes[0xB3] = &CPU::res_e_6;
    cpu.ext_opcodes[0xB4] = &CPU::res_h_6;
    cpu.ext_opcodes[0xB5] = &CPU::res_l_6;
    cpu.ext_opcodes[0xB6] = &CPU::res_hl_ref_6;
    cpu.ext_opcodes[0xBF] = &CPU::res_a_7;
    cpu.ext_opcodes[0xB8] = &CPU::res_b_7;
    cpu.ext_opcodes[0xB9] = &CPU::res_c_7;
    cpu.ext_opcodes[0xBA] = &CPU::res_d_7;
    cpu.ext_opcodes[0xBB] = &CPU::res_e_7;
    cpu.ext_opcodes[0xBC] = &CPU::res_h_7;
    cpu.ext_opcodes[0xBD] = &CPU::res_l_7;
    cpu.ext_opcodes[0xBE] = &CPU::res_hl_ref_7;
    cpu.ext_opcodes[0xC7] = &CPU::set_a_0;
    cpu.ext_opcodes[0xC0] = &CPU::set_b_0;
    cpu.ext_opcodes[0xC1] = &CPU::set_c_0;
    cpu.ext_opcodes[0xC2] = &CPU::set_d_0;
    cpu.ext_opcodes[0xC3] = &CPU::set_e_0;
    cpu.ext_opcodes[0xC4] = &CPU::set_h_0;
    cpu.ext_opcodes[0xC5] = &CPU::set_l_0;
    cpu.ext_opcodes[0xC6] = &CPU::set_hl_ref_0;
    cpu.ext_opcodes[0xCF] = &CPU::set_a_1;
    cpu.ext_opcodes[0xC8] = &CPU::set_b_1;
    cpu.ext_opcodes[0xC9] = &CPU::set_c_1;
    cpu.ext_opcodes[0xCA] = &CPU::set_d_1;
    cpu.ext_opcodes[0xCB] = &CPU::set_e_1;
    cpu.ext_opcodes[0xCC] = &CPU::set_h_1;
    cpu.ext_opcodes[0xCD] = &CPU::set_l_1;
    cpu.ext_opcodes[0xCE] = &CPU::set_hl_ref_1;
    cpu.ext_opcodes[0xD7] = &CPU::set_a_2;
    cpu.ext_opcodes[0xD0] = &CPU::set_b_2;
    cpu.ext_opcodes[0xD1] = &CPU::set_c_2;
    cpu.ext_opcodes[0xD2] = &CPU::set_d_2;
    cpu.ext_opcodes[0xD3] = &CPU::set_e_2;
    cpu.ext_opcodes[0xD4] = &CPU::set_h_2;
    cpu.ext_opcodes[0xD5] = &CPU::set_l_2;
    cpu.ext_opcodes[0xD6] = &CPU::set_hl_ref_2;
    cpu.ext_opcodes[0xDF] = &CPU::set_a_3;
    cpu.ext_opcodes[0xD8] = &CPU::set_b_3;
    cpu.ext_opcodes[0xD9] = &CPU::set_c_3;
    cpu.ext_opcodes[0xDA] = &CPU::set_d_3;
    cpu.ext_opcodes[0xDB] = &CPU::set_e_3;
    cpu.ext_opcodes[0xDC] = &CPU::set_h_3;
    cpu.ext_opcodes[0xDD] = &CPU::set_l_3;
    cpu.ext_opcodes[0xDE] = &CPU::set_hl_ref_3;
    cpu.ext_opcodes[0xE7] = &CPU::set_a_4;
    cpu.ext_opcodes[0xE0] = &CPU::set_b_4;
    cpu.ext_opcodes[0xE1] = &CPU::set_c_4;
    cpu.ext_opcodes[0xE2] = &CPU::set_d_4;
    cpu.ext_opcodes[0xE3] = &CPU::set_e_4;
    cpu.ext_opcodes[0xE4] = &CPU::set_h_4;
    cpu.ext_opcodes[0xE5] = &CPU::set_l_4;
    cpu.ext_opcodes[0xE6] = &CPU::set_hl_ref_4;
    cpu.ext_opcodes[0xEF] = &CPU::set_a_5;
    cpu.ext_opcodes[0xE8] = &CPU::set_b_5;
    cpu.ext_opcodes[0xE9] = &CPU::set_c_5;
    cpu.ext_opcodes[0xEA] = &CPU::set_d_5;
    cpu.ext_opcodes[0xEB] = &CPU::set_e_5;
    cpu.ext_opcodes[0xEC] = &CPU::set_h_5;
    cpu.ext_opcodes[0xED] = &CPU::set_l_5;
    cpu.ext_opcodes[0xEE] = &CPU::set_hl_ref_5;
    cpu.ext_opcodes[0xF7] = &CPU::set_a_6;
    cpu.ext_opcodes[0xF0] = &CPU::set_b_6;
    cpu.ext_opcodes[0xF1] = &CPU::set_c_6;
    cpu.ext_opcodes[0xF2] = &CPU::set_d_6;
    cpu.ext_opcodes[0xF3] = &CPU::set_e_6;
    cpu.ext_opcodes[0xF4] = &CPU::set_h_6;
    cpu.ext_opcodes[0xF5] = &CPU::set_l_6;
    cpu.ext_opcodes[0xF6] = &CPU::set_hl_ref_6;
    cpu.ext_opcodes[0xFF] = &CPU::set_a_7;
    cpu.ext_opcodes[0xF8] = &CPU::set_b_7;
    cpu.ext_opcodes[0xF9] = &CPU::set_c_7;
    cpu.ext_opcodes[0xFA] = &CPU::set_d_7;
    cpu.ext_opcodes[0xFB] = &CPU::set_e_7;
    cpu.ext_opcodes[0xFC] = &CPU::set_h_7;
    cpu.ext_opcodes[0xFD] = &CPU::set_l_7;
    cpu.ext_opcodes[0xFE] = &CPU::set_hl_ref_7;
}