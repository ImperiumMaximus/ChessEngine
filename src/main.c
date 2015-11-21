#include <stdio.h>

#include <board.h>
#include <cpu.h>
#include <bitscan.h>

int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

    printf("%d, %d", bit_scan_forward_ll(14), bit_scan_reverse_ll(14));

    getchar();

    board_free(b);

    return 0;
}
