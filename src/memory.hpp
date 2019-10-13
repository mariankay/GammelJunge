//
// Created by mrn on 06.10.19.
//

#include "common.h"

#include "cartridge.hpp"


class Memory {
public:
    Cartridge* cartridge;

    func read(u16 addr) -> u8 {
    //    if(is_cartridge_memory(addr)) return cartridge->read(addr);
    //    else return mem[addr];
        return mem[addr];
    }

    func write(u16 addr, u8 val) -> void {
        mem[addr] = val;
    }


    u8 mem[64 kB];
private:

    func is_cartridge_memory(u16 addr) -> bool {
        return (addr <= ROM1_END) || (addr > RAM_START && addr < RAM_END);
    }
};