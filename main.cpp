#include <iostream>
#include "src/common.h"
#include "src/cpu.hpp"

func main() -> int {

    CPU* cpu = new CPU();
    cpu->nop();

    cpu->A = 0;
    cpu->add_a_a();
    return 0;
}
