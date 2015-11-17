#ifndef __BOARD_H__
#define __BOARD_H__

#include <stdint.h>

typedef enum PieceType {
    INVALID = 0,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    MAX_TYPE = KING
} PieceType;

typedef enum PieceColor {
    WHITE = 0,
    BLACK,
    MAX_COLOR
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
Board* board_dup(Board* b);
void   board_free(Board* b);

#endif /* __BOARD_H__ */
