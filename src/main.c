#include <stdio.h>

#include <board.h>
#include <cpu.h>
#include <bitscan.h>

extern void bit_reset(uint64_t* value, uint32_t pos);
extern void bit_set(uint64_t* value, uint32_t pos);

int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

    uint64_t x = 0xaa55;
    x = __builtin_bswap64(x);

    printf("%lx\n", x);

    board_free(b);

    return 0;
}
