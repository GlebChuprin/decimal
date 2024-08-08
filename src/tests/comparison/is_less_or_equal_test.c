#include "decimal_test.h"

START_TEST(test_less_or_equal_1) {
  // 0
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  decimal_t decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 1);
}

START_TEST(test_less_or_equal_2) {
  //-123412341234.12341234
  decimal_t decimal1 = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  //-123412341234.12341234
  decimal_t decimal2 = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 2);
}

START_TEST(test_less_or_equal_3) {
  //-7896452314745.56984
  decimal_t decimal1 = {{0x809F4038, 0xAF56227, 0x0, 0x80050000}};
  //-789645231474.556984
  decimal_t decimal2 = {{0x809F4038, 0xAF56227, 0x0, 0x80060000}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 3);
}

START_TEST(test_less_or_equal_4) {
  //-0.15
  decimal_t decimal1 = {{0xF, 0x0, 0x0, 0x80020000}};
  // 3955454
  decimal_t decimal2 = {{0x3C5AFE, 0x0, 0x0, 0x0}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 4);
}

START_TEST(test_less_or_equal_5) {
  // max
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // min
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int expected = FALSE;

  test_less_or_equal(decimal1, decimal2, expected, 5);
}

START_TEST(test_less_or_equal_6) {
  // min
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // max
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 6);
}

START_TEST(test_less_or_equal_7) {
  //-1.0000000000000000000007
  decimal_t decimal1 = {{0xB2400007, 0x19E0C9BA, 0x21E, 0x80160000}};
  //-1.0000000000000000000008
  decimal_t decimal2 = {{0xB2400008, 0x19E0C9BA, 0x21E, 0x80160000}};
  int expected = FALSE;

  test_less_or_equal(decimal1, decimal2, expected, 7);
}

START_TEST(test_less_or_equal_8) {
  // 1717178965432198
  decimal_t decimal1 = {{0xE2401786, 0x619C3, 0x0, 0x0}};
  // 0
  decimal_t decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int expected = FALSE;

  test_less_or_equal(decimal1, decimal2, expected, 8);
}

START_TEST(test_less_or_equal_9) {
  // 10
  decimal_t decimal1 = {{0xA, 0x0, 0x0, 0x0}};
  // 10.1
  decimal_t decimal2 = {{0x65, 0x0, 0x0, 0x10000}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 9);
}

START_TEST(test_less_or_equal_10) {
  // 10000000
  decimal_t decimal1 = {{0x80, 0x0, 0x0, 0x0}};
  // 1000000
  decimal_t decimal2 = {{0x40, 0x0, 0x0, 0x0}};
  int expected = FALSE;

  test_less_or_equal(decimal1, decimal2, expected, 10);
}

START_TEST(test_less_or_equal_11) {
  // 0
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  //-0
  decimal_t decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 11);
}

START_TEST(test_less_or_equal_12) {
  // 0.003457000001
  decimal_t decimal1 = {{0xCE0DA241, 0x0, 0x0, 0xC0000}};
  // 792281625142643375935439.50335
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 12);
}

START_TEST(test_less_or_equal_13) {
  // 3569.78124
  decimal_t decimal1 = {{0x15470DCC, 0x0, 0x0, 0x50000}};
  //-0.0000000795672222222
  decimal_t decimal2 = {{0x41C29A0E, 0xB9, 0x0, 0x80130000}};
  int expected = FALSE;

  test_less_or_equal(decimal1, decimal2, expected, 13);
}

START_TEST(test_less_or_equal_14) {
  // 123456789.987654321
  decimal_t decimal1 = {{0xE052FAB1, 0x1B69B4B, 0x0, 0x90000}};
  // 123456789.987654321
  decimal_t decimal2 = {{0xE052FAB1, 0x1B69B4B, 0x0, 0x90000}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 14);
}

START_TEST(test_less_or_equal_15) {
  // min
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // min
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int expected = TRUE;

  test_less_or_equal(decimal1, decimal2, expected, 14);
}

Suite *less_or_equal_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("less_or_equal_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_less_or_equal_1);
  tcase_add_test(core, test_less_or_equal_2);
  tcase_add_test(core, test_less_or_equal_3);
  tcase_add_test(core, test_less_or_equal_4);
  tcase_add_test(core, test_less_or_equal_5);
  tcase_add_test(core, test_less_or_equal_6);
  tcase_add_test(core, test_less_or_equal_7);
  tcase_add_test(core, test_less_or_equal_8);
  tcase_add_test(core, test_less_or_equal_9);
  tcase_add_test(core, test_less_or_equal_10);
  tcase_add_test(core, test_less_or_equal_11);
  tcase_add_test(core, test_less_or_equal_12);
  tcase_add_test(core, test_less_or_equal_13);
  tcase_add_test(core, test_less_or_equal_14);
  tcase_add_test(core, test_less_or_equal_15);

  suite_add_tcase(suite, core);

  return (suite);
}