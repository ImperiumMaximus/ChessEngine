#include "test_suite.h"

#include <board.h>

START_TEST(test_board_new) {
    Board* b;

    b = board_new();

    board_free(b);
}
END_TEST

Suite* board_suite() {
    Suite* s;
    TCase* tc;

    s = suite_create("Board");

    tc = tcase_create("Test Case Container");

    tcase_add_test(tc, test_board_new);

    suite_add_tcase(s, tc);

    return s;
}
