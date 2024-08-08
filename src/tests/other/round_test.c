#include "decimal_test.h"

START_TEST(test_round_1) {
  // 481516.2342 -> 481516
  decimal_t decimal = {{0x1F018BE6, 0x1, 0x0, 0x40000}};
  decimal_t expected = {{0x758EC, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 1);
}
END_TEST

START_TEST(test_round_2) {
  // -0.14569721534856 -> 0
  decimal_t decimal = {{0x47139988, 0xD40, 0x0, 0x800E0000}};
  decimal_t expected = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 2);
}
END_TEST

START_TEST(test_round_3) {
  // 1234567 -> 1234567
  decimal_t decimal = {{0x12D4CB, 0x0, 0x0, 0x0}};
  decimal_t expected = {{0x12D4CB, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 3);
}
END_TEST

START_TEST(test_round_4) {
  // -7896452314745.56984 -> -7896452314746
  decimal_t decimal = {{0x809F4038, 0xAF56227, 0x0, 0x80050000}};
  decimal_t expected = {{0x893C367A, 0x72E, 0x0, 0x80000000}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 4);
}
END_TEST

START_TEST(test_round_5) {
  // 85642395734636.4656 -> 85642395734636
  decimal_t decimal = {{0x3AC3ACF0, 0xBE2A10D, 0x0, 0x40000}};
  decimal_t expected = {{0x2C93526C, 0x4DE4, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 5);
}
END_TEST

START_TEST(test_round_6) {
  // -0.0000000795672222222 -> 0
  decimal_t decimal = {{0x41C29A0E, 0xB9, 0x0, 0x80130000}};
  decimal_t expected = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 6);
}
END_TEST

START_TEST(test_round_7) {
  // -123412341234.12341234 -> -123412341234
  decimal_t decimal = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  decimal_t expected = {{0xBBF2E1F2, 0x1C, 0x0, 0x80000000}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 7);
}
END_TEST

START_TEST(test_round_8) {
  // 792281625142643375935439.50335 -> 792281625142643375935440
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  decimal_t expected = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 8);
}
END_TEST

START_TEST(test_round_9) {
  // -1.0000000000000000000008 -> -1
  decimal_t decimal = {{0xB2400008, 0x19E0C9BA, 0x21E, 0x80160000}};
  decimal_t expected = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 9);
}
END_TEST

START_TEST(test_round_10) {
  // 0 -> 0
  decimal_t decimal = {{0x0, 0x0, 0x0, 0x80160000}};
  decimal_t expected = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 10);
}
END_TEST

START_TEST(test_round_11) {
  // min -> min
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  decimal_t expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 11);
}
END_TEST

START_TEST(test_round_12) {
  // 7.77777 -> 8
  decimal_t decimal = {{0x76ADF1, 0x0, 0x0, 0x60000}};
  decimal_t expected = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 12);
}
END_TEST

START_TEST(test_round_13) {
  // 1237.0000000777777 -> 1237
  decimal_t decimal = {{0x0FEAFE31, 0x2BF273, 0x0, 0xD0000}};
  decimal_t expected = {{0x4D5, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 13);
}
END_TEST

START_TEST(test_round_14) {
  // 35309188505043.582404850638318 -> 35309188505044
  decimal_t decimal = {{0x1E585DEE, 0x4B1DBED3, 0x72171380, 0xF0000}};
  decimal_t expected = {{0xFA35DD4, 0x201D, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 14);
}
END_TEST

START_TEST(test_round_15) {
  // 10.1 -> 10
  decimal_t decimal = {{0x65, 0x0, 0x0, 0x10000}};
  decimal_t expected = {{0xA, 0x0, 0x0, 0x0}};

  test_round(decimal, expected, TEST_ERROR_CODE_OK, 15);
}
END_TEST

START_TEST(test_round_16) {
  // NULL
  decimal_t decimal = {0};
  decimal_t *result = NULL;
  int expected_error_code = 1;
  int error_code = round_f(decimal, result);
  ck_assert_int_eq(error_code, expected_error_code);
}

Suite *round_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("round_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_round_1);
  tcase_add_test(core, test_round_2);
  tcase_add_test(core, test_round_3);
  tcase_add_test(core, test_round_4);
  tcase_add_test(core, test_round_5);
  tcase_add_test(core, test_round_6);
  tcase_add_test(core, test_round_7);
  tcase_add_test(core, test_round_8);
  tcase_add_test(core, test_round_9);
  tcase_add_test(core, test_round_10);
  tcase_add_test(core, test_round_11);
  tcase_add_test(core, test_round_12);
  tcase_add_test(core, test_round_13);
  tcase_add_test(core, test_round_14);
  tcase_add_test(core, test_round_15);
  tcase_add_test(core, test_round_16);

  suite_add_tcase(suite, core);

  return (suite);
}