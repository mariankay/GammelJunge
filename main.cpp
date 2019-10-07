#include <iostream>
#include "src/common.h"
#include "src/cpu.hpp"

func main() -> int {

    CPU* cpu = new CPU();
    cpu->nop();
    return 0;
}