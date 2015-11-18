#include <check.h>
#include <stdlib.h>
#include "test_suite.h"

int main(void) {
    SRunner* sr;
    int number_failed;

    sr = srunner_create(board_suite());

    //srunner_add_suite(sr, another_suite);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
