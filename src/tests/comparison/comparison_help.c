#include "test_help.h"

#ifdef DEBUG

void print_debug_comp(decimal_t decimal1, decimal_t decimal2,
                          int result, int expected, char *test_name,
                          int test_num) {
  printf(
      "\n\033[36m------------------------- %s - %02d "
      "-------------------------\033[0m\n\n",
      test_name, test_num);

  printf("\033[33m%s\033[0m\n", "decimal_t 1:");
  print_int256(DECIMAL_TO_INT256(decimal1));

  printf("\033[33m%s\033[0m\n", "decimal_t 2:");
  print_int256(DECIMAL_TO_INT256(decimal2));

  printf("\033[33m%s\033[0m\n", "expected :");
  printf("\n%d\n\n", expected);

  printf("\033[33m%s\033[0m\n", "result :");
  printf("\n%d\n\n", result);

  printf(
      "\033[36m----------------------------------------------------------------"
      "-\033[0m\n");
}

#endif

void test_comp(decimal_t decimal1, decimal_t decimal2, int expected,
                   int test_num, int (*func)(decimal_t, decimal_t),
                   char *test_name) {
  int result = -1;
  (void)test_name;
  (void)test_num;
  result = func(decimal1, decimal2);

#ifdef DEBUG
  if (result != expected)
    print_debug_comp(decimal1, decimal2, result, expected, test_name,
                         test_num);
#endif

  ck_assert_uint_eq(result, expected);
}

void test_less(decimal_t decimal1, decimal_t decimal2, int expected,
                   int test_num) {
  test_comp(decimal1, decimal2, expected, test_num, is_less,
                "LESS TEST");
}

void test_less_or_equal(decimal_t decimal1, decimal_t decimal2,
                            int expected, int test_num) {
  test_comp(decimal1, decimal2, expected, test_num, is_less_or_equal,
                "LESS OR EQUAL TEST");
}

void test_greater(decimal_t decimal1, decimal_t decimal2, int expected,
                      int test_num) {
  test_comp(decimal1, decimal2, expected, test_num, is_greater,
                "GREATER TEST");
}

void test_greater_or_equal(decimal_t decimal1, decimal_t decimal2,
                               int expected, int test_num) {
  test_comp(decimal1, decimal2, expected, test_num, is_greater_or_equal,
                "GREATER OR EQUAL TEST");
}

void test_equal(decimal_t decimal1, decimal_t decimal2, int expected,
                    int test_num) {
  test_comp(decimal1, decimal2, expected, test_num, is_equal,
                "EQUAL TEST");
}

void test_not_equal(decimal_t decimal1, decimal_t decimal2,
                        int expected, int test_num) {
  test_comp(decimal1, decimal2, expected, test_num, is_not_equal,
                "NOT EQUAL TEST");
}
