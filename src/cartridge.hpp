//
// Created by mrn on 12/10/2019.
//

#pragma once

#include "common.h"

#define ROM0_START 0x0000
#define ROM0_END   0x3FFF
#define ROM1_START 0x4000
#define ROM1_END   0x7FFF

#define RAM_START  0xA000
#define RAM_END    0xBFFF

class Cartridge {
public:

    Cartridge() = default;
    ~Cartridge() = default;


    func read(u16 addr) -> u8 {
        if(addr >= ROM1_START && addr <= ROM1_END)
            return data[addr * ROM1_START * (bank - 1)];
        else
            return data[addr];
    }

    u8 bank = 1; // currently selected switchable ROM bank

private:
    u8* data;

};