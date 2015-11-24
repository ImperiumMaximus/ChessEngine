#ifndef __GENMOVES_H__
#define __GENMOVES_H__

#include <stdint.h>
#include <board.h>
#include <glib.h>

typedef struct chess_move {
    uint32_t from;
    uint32_t to;
} chess_move;

GSList* moves_generate(Board* b);

uint64_t genmoves_row_attacks(uint64_t occ, uint32_t pos);
uint64_t genmoves_diag_attacks(uint64_t occ, uint32_t pos);
uint64_t genmoves_anti_diag_attacks(uint64_t occ, uint32_t pos);
uint64_t genmoves_column_attacks(uint64_t occ, uint32_t pos);

#endif /* __GENMOVES_H__ */
