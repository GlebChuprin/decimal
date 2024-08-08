#include "test_help.h"

#ifdef DEBUG

void print_debug(decimal_t decimal1, decimal_t decimal2,
                     decimal_t result, decimal_t expected, int error_code,
                     int expected_error_code, char *test_name, int test_num) {
  printf(
      "\n\033[36m------------------------- %s - %02d "
      "-------------------------\033[0m\n\n",
      test_name, test_num);

  printf("\033[33m%s\033[0m\n", "decimal_t 1:");
  print_int256(DECIMAL_TO_INT256(decimal1));

  printf("\033[33m%s\033[0m\n", "decimal_t 2:");
  print_int256(DECIMAL_TO_INT256(decimal2));

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

void test_func(decimal_t decimal1, decimal_t decimal2,
                   decimal_t expected, int expected_error_code, int test_num,
                   int (*func)(decimal_t, decimal_t, decimal_t *),
                   char *test_name) {
  decimal_t result = NEW;
  (void)test_name;
  (void)test_num;
  int error_code = func(decimal1, decimal2, &result);

#ifdef DEBUG
  if (!is_equal(result, expected) || error_code != expected_error_code)
    print_debug(decimal1, decimal2, result, expected, error_code,
                    expected_error_code, test_name, test_num);
#endif

  ck_assert_uint_eq(is_equal(result, expected), 1);
  ck_assert_uint_eq(error_code, expected_error_code);
}

void test_dvv(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num) {
  test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                dvv, "DIV TEST");
}

void test_mul(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num) {
  test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                mul, "MUL TEST");
}

void test_sub(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num) {
  test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                sub, "SUB TEST");
}

void test_add(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num) {
  test_func(decimal1, decimal2, expected, expected_error_code, test_num,
                add, "ADD TEST");
}
