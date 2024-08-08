#include "test_help.h"

#ifdef DEBUG

void print_debug_other(decimal_t decimal, decimal_t result,
                           decimal_t expected, int error_code,
                           int expected_error_code, char *test_name,
                           int test_num) {
  printf(
      "\n\033[36m------------------------- %s - %02d "
      "-------------------------\033[0m\n\n",
      test_name, test_num);

  printf("\033[33m%s\033[0m\n", "decimal:");
  print_int256(DECIMAL_TO_INT256(decimal));

  printf("\033[31m%s\033[0m\n", "result:");
  print_int256(DECIMAL_TO_INT256(result));
  print_decimal(result);

  printf("\033[32m%s\033[0m\n", "expected:");
  print_int256(DECIMAL_TO_INT256(expected));
  print_decimal(expected);

  printf("\033[36m%-21s%d\n%s%d\033[0m\n\n", "error code: ", error_code,
         "expected error code: ", expected_error_code);

  printf(
      "\033[36m----------------------------------------------------------------"
      "-\033[0m\n");
}

#endif

void test_other(decimal_t decimal, decimal_t expected,
                    int expected_error_code, int test_num,
                    int (*func)(decimal_t, decimal_t *), char *test_name) {
  decimal_t result = NEW;
  (void)test_name;
  (void)test_num;
  int error_code = func(decimal, &result);

#ifdef DEBUG
  if (!is_equal(result, expected) || error_code != expected_error_code)
    print_debug_other(decimal, result, expected, error_code,
                          expected_error_code, test_name, test_num);
#endif

  ck_assert_uint_eq(is_equal(result, expected), 1);
  ck_assert_uint_eq(error_code, expected_error_code);
}

void test_negate(decimal_t decimal, decimal_t expected,
                     int expected_error_code, int test_num) {
  test_other(decimal, expected, expected_error_code, test_num, negate,
                 "NEGATE TEST");
}

void test_truncate(decimal_t decimal, decimal_t expected,
                       int expected_error_code, int test_num) {
  test_other(decimal, expected, expected_error_code, test_num, truncate,
                 "TRUNCATE TEST");
}

void test_floor(decimal_t decimal, decimal_t expected,
                    int expected_error_code, int test_num) {
  test_other(decimal, expected, expected_error_code, test_num, floor_f,
                 "FLOOR TEST");
}

void test_round(decimal_t decimal, decimal_t expected,
                    int expected_error_code, int test_num) {
  test_other(decimal, expected, expected_error_code, test_num, round_f,
                 "ROUND TEST");
}
