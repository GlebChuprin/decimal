#include "decimal_test.h"

START_TEST(test_greater_or_equal_1) {
  // 0.003457000001
  decimal_t decimal1 = {{0xCE0DA241, 0x0, 0x0, 0xC0000}};
  //-7000000000000000.303
  decimal_t decimal2 = {{0x93BC012F, 0x6124FEE9, 0x0, 0x80030000}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 1);
}

START_TEST(test_greater_or_equal_2) {
  //-0.0000000795672222222
  decimal_t decimal1 = {{0x41C29A0E, 0xB9, 0x0, 0x80130000}};
  // 0
  decimal_t decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int expected = FALSE;

  test_greater_or_equal(decimal1, decimal2, expected, 2);
}

START_TEST(test_greater_or_equal_3) {
  // 0
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  //-0
  decimal_t decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 3);
}

START_TEST(test_greater_or_equal_4) {
  // 0.003457000001
  decimal_t decimal1 = {{0xCE0DA241, 0x0, 0x0, 0xC0000}};
  // 0.003457000001
  decimal_t decimal2 = {{0xCE0DA241, 0x0, 0x0, 0xC0000}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 4);
}

START_TEST(test_greater_or_equal_5) {
  // 0.11
  decimal_t decimal1 = {{0xB, 0x0, 0x0, 0x20000}};
  // 0.1
  decimal_t decimal2 = {{0x1, 0x0, 0x0, 0x10000}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 5);
}

START_TEST(test_greater_or_equal_6) {
  // 10
  decimal_t decimal1 = {{0xA, 0x0, 0x0, 0x0}};
  // 10.1
  decimal_t decimal2 = {{0x65, 0x0, 0x0, 0x10000}};
  int expected = FALSE;

  test_greater_or_equal(decimal1, decimal2, expected, 6);
}

START_TEST(test_greater_or_equal_7) {
  // 85642395734636.4656
  decimal_t decimal1 = {{0x3AC3ACF0, 0xBE2A10D, 0x0, 0x40000}};
  // 85642395734636.4657
  decimal_t decimal2 = {{0x3AC3ACF1, 0xBE2A10D, 0x0, 0x0}};
  int expected = FALSE;

  test_greater_or_equal(decimal1, decimal2, expected, 7);
}

START_TEST(test_greater_or_equal_8) {
  // min
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // max
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int expected = FALSE;

  test_greater_or_equal(decimal1, decimal2, expected, 8);
}

START_TEST(test_greater_or_equal_9) {
  //-7896452314745.56984
  decimal_t decimal1 = {{0x809F4038, 0xAF56227, 0x0, 0x80050000}};
  //-789645231474.556984
  decimal_t decimal2 = {{0x809F4038, 0xAF56227, 0x0, 0x80060000}};
  int expected = FALSE;

  test_greater_or_equal(decimal1, decimal2, expected, 9);
}

START_TEST(test_greater_or_equal_10) {
  //-0.15
  decimal_t decimal1 = {{0xF, 0x0, 0x0, 0x80020000}};
  // 3955454
  decimal_t decimal2 = {{0x3C5AFE, 0x0, 0x0, 0x0}};
  int expected = FALSE;

  test_greater_or_equal(decimal1, decimal2, expected, 10);
}

START_TEST(test_greater_or_equal_11) {
  // 10000000
  decimal_t decimal1 = {{0x80, 0x0, 0x0, 0x0}};
  // 1000000
  decimal_t decimal2 = {{0x40, 0x0, 0x0, 0x0}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 11);
}

START_TEST(test_greater_or_equal_12) {
  //-5896
  decimal_t decimal1 = {{0x1708, 0x0, 0x0, 0x80000000}};
  //-7876
  decimal_t decimal2 = {{0x1EC4, 0x0, 0x0, 0x80000000}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 12);
}

START_TEST(test_greater_or_equal_13) {
  // 25565584854.265656565
  decimal_t decimal1 = {{0x019C74F5, 0x62CB33F9, 0x1, 0x0}};
  // 3
  decimal_t decimal2 = {{0x3, 0x0, 0x0, 0x80000000}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 13);
}

START_TEST(test_greater_or_equal_14) {
  // max
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // min
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 14);
}

START_TEST(test_greater_or_equal_15) {
  //-0
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 0
  decimal_t decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int expected = TRUE;

  test_greater_or_equal(decimal1, decimal2, expected, 15);
}

Suite *greater_or_equal_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("greater_or_equal_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_greater_or_equal_1);
  tcase_add_test(core, test_greater_or_equal_2);
  tcase_add_test(core, test_greater_or_equal_3);
  tcase_add_test(core, test_greater_or_equal_4);
  tcase_add_test(core, test_greater_or_equal_5);
  tcase_add_test(core, test_greater_or_equal_6);
  tcase_add_test(core, test_greater_or_equal_7);
  tcase_add_test(core, test_greater_or_equal_8);
  tcase_add_test(core, test_greater_or_equal_9);
  tcase_add_test(core, test_greater_or_equal_10);
  tcase_add_test(core, test_greater_or_equal_11);
  tcase_add_test(core, test_greater_or_equal_12);
  tcase_add_test(core, test_greater_or_equal_13);
  tcase_add_test(core, test_greater_or_equal_14);
  tcase_add_test(core, test_greater_or_equal_15);

  suite_add_tcase(suite, core);

  return (suite);
}