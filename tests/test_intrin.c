#include "test_suite.h"

#include <bitscan.h>

START_TEST(test_bit_set) {
    uint64_t value = 0;
    uint32_t pos = 10;

    bit_set(&value, pos);

    ck_assert_int_eq(value, 1024);

    bit_reset(&value, pos);
    ck_assert_int_eq(value, 0);

    value = 1024;
    ck_assert_int_eq(10, bit_scan_forward_intrin(value));
    ck_assert_int_eq(10, bit_scan_reverse_intrin(value));
}
END_TEST

Suite* intrin_suite() {
    Suite* s;
    TCase* tc;

    s = suite_create("Intrin");

    tc = tcase_create("Test Case Container");

    tcase_add_test(tc, test_bit_set);

    suite_add_tcase(s, tc);

    return s;
}
