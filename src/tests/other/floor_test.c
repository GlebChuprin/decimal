#include "decimal_test.h"

START_TEST(test_floor_1) {
  // 481516.2342
  decimal_t decimal = {{0x1F018BE6, 0x1, 0x0, 0x40000}};
  // 481516
  decimal_t expected = {{0x758EC, 0x0, 0x0, 0x0}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_floor_2) {
  // 75691211548654.6545118461
  decimal_t decimal = {{0xBBE88CFD, 0x49BA56C0, 0xA048, 0xA0000}};
  // 75691211548654
  decimal_t expected = {{0x3BC6E7EE, 0x44D7, 0x0, 0x0}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_floor_3) {
  // 35309188505043.582404850638318
  decimal_t decimal = {{0x1E585DEE, 0x4B1DBED3, 0x72171380, 0xF0000}};
  // 35309188505043
  decimal_t expected = {{0xFA35DD3, 0x201D, 0x0, 0x0}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_floor_4) {
  // 1237.0000000777777
  decimal_t decimal = {{0x0FEAFE31, 0x2BF273, 0x0, 0xD0000}};
  // 1237
  decimal_t expected = {{0x4D5, 0x0, 0x0, 0x0}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_floor_5) {
  // 0.9454416741519591
  decimal_t decimal = {{0xEF6FD0E7, 0x2196BD, 0x0, 0x100000}};
  // 0
  decimal_t expected = {{0x0, 0x0, 0x0, 0x0}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_floor_6) {
  //-1.0000000000000000000007
  decimal_t decimal = {{0xB2400007, 0x19E0C9BA, 0x21E, 0x80160000}};
  //-2
  decimal_t expected = {{0x2, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_floor_7) {
  //-7896452314745.56984
  decimal_t decimal = {{0x809F4038, 0xAF56227, 0x0, 0x80050000}};
  //-7896452314746
  decimal_t expected = {{0x893C367A, 0x72E, 0x0, 0x80000000}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_floor_8) {
  //-0.0000000795672222222
  decimal_t decimal = {{0x41C29A0E, 0xB9, 0x0, 0x80130000}};
  //-1
  decimal_t expected = {{0x1, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_floor_9) {
  // -792281625142643375935440
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  //-792281625142643375935440
  decimal_t expected = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_floor_10) {
  //-123412341234.12341234
  decimal_t decimal = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  //-123412341235
  decimal_t expected = {{0xBBF2E1F3, 0x1C, 0x0, 0x80000000}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_floor_11) {
  ////-5.000016
  decimal_t decimal = {{0x4C4B50, 0x0, 0, 0x80060000}};
  //-6
  decimal_t expected = {{0x6, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_floor_12) {
  //-5896
  decimal_t decimal = {{0x1708, 0x0, 0x0, 0x80000000}};
  //-5896
  decimal_t expected = {{0x1708, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_floor_13) {
  // NULL
  decimal_t decimal = {0};
  decimal_t *result = NULL;
  int expected_error_code = 1;
  int error_code = floor_f(decimal, result);
  ck_assert_int_eq(error_code, expected_error_code);
}

START_TEST(test_floor_14) {
  // 0.11
  decimal_t decimal = {{0xB, 0x0, 0x0, 0x20000}};
  // 0
  decimal_t expected = {{0x0, 0x0, 0x0, 0x0}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_floor_15) {
  // 7.777777;
  decimal_t decimal = {{0x76ADF1, 0x0, 0x0, 0x60000}};
  // 7
  decimal_t expected = {{0x7, 0x0, 0x0, 0x0}};

  test_floor(decimal, expected, TEST_ERROR_CODE_OK, 15);
}

Suite *floor_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("floor_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_floor_1);
  tcase_add_test(core, test_floor_2);
  tcase_add_test(core, test_floor_3);
  tcase_add_test(core, test_floor_4);
  tcase_add_test(core, test_floor_5);
  tcase_add_test(core, test_floor_6);
  tcase_add_test(core, test_floor_7);
  tcase_add_test(core, test_floor_8);
  tcase_add_test(core, test_floor_9);
  tcase_add_test(core, test_floor_10);
  tcase_add_test(core, test_floor_11);
  tcase_add_test(core, test_floor_12);
  tcase_add_test(core, test_floor_13);
  tcase_add_test(core, test_floor_14);
  tcase_add_test(core, test_floor_15);

  suite_add_tcase(suite, core);

  return (suite);
}
