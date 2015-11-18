#ifndef __BOARD_H__
#define __BOARD_H__

#include <stdint.h>

typedef enum PieceType {
    FREE = 0,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    MAX_TYPE = KING
} PieceType;

typedef enum PieceColor {
    WHITE = -1,
    BLACK = +1,
    MAX_COLOR = 2
} PieceColor;

enum {
    BoardRowSize = 8,
    BoardColumnSize = 8
};

typedef struct Board {
    // pieces bitboards
    uint64_t piecesType[MAX_COLOR][MAX_TYPE];
    uint64_t piecesColor[MAX_COLOR];

    // mailbox
    uint8_t mailbox[BoardRowSize][BoardColumnSize];

    // color
    PieceColor turnColor;
} Board;

Board* board_new(void);
Board* board_dup(Board* other_board);
void   board_free(Board* b);

static inline void board_change_turn(Board* b) {
    b->turnColor = -(b->turnColor);
}

#endif /* __BOARD_H__ */
