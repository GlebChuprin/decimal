#include "decimal_test.h"

int main(void) {
  int failed = 0;

  Suite* tests[] = {add_test(),
                    dvv_test(),
                    mul_test(),
                    sub_test(),
                    float_to_decimal_test(),
                    decimal_to_float_test(),
                    int_to_decimal_test(),
                    less_test(),
                    less_or_equal_test(),
                    greater_test(),
                    greater_or_equal_test(),
                    equal_test(),
                    not_equal_test(),
                    negate_test(),
                    truncate_test(),
                    floor_test(),
                    round_test(),
                    decimal_to_int_test()};
  for (int i = 0; i < 18; i++) {
    SRunner* runner = srunner_create(tests[i]);
    srunner_run_all(runner, CK_NORMAL);
    if (srunner_ntests_failed(runner) != 0) {
      failed = srunner_ntests_failed(runner);
    }
    srunner_free(runner);
  }

  return (failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
