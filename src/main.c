#include <stdio.h>

#include <board.h>
#include <cpu.h>
#include <bitscan.h>

extern void bit_reset(uint64_t* value, uint32_t pos);
extern void bit_set(uint64_t* value, uint32_t pos);

int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

    board_free(b);

    return 0;
}
