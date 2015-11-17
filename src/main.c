#include <stdio.h>

#include "board.h"

int main (int argc, char** argv) {
    PieceColor color = WHITE;
    printf("%d, %d\n", color, (~color)&1);
    color = BLACK;
    printf("%d, %d\n", color, (~color)&1);
    printf("%d\n", sizeof(Board));
    getchar();
    return 0;
}
