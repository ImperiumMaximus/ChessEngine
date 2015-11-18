#include <stdio.h>

#include <board.h>
#include <cpu.h>

int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

    int i;
    uint64_t bbWhite = 0;
    uint64_t bbBlack = 0;
    for(i = 0; i < MAX_TYPE; i++) {
        bbWhite |= b->piecesType[WHITE + 1][i];
    }

    for(i = 0; i < MAX_TYPE; i++) {
        bbBlack |= b->piecesType[BLACK][i];
    }

    printf("%lx, %lx\n", bbWhite, bbBlack);

    getchar();
    return 0;
}
