#include "decimal_test.h"

START_TEST(test_float_to_decimal_1) {
  float num = 1.5;
  decimal_t expected = {{0xF, 0, 0, 0x10000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_float_to_decimal_2) {
  float num = 0.01825;
  decimal_t expected = {{0x721, 0, 0, 0x50000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_float_to_decimal_3) {
  float num = 5.0000163478259;
  // 5.000016
  decimal_t expected = {{0x4C4B50, 0x0, 0, 0x60000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_float_to_decimal_4) {
  float num = -0.99900001786;
  //-0.999
  decimal_t expected = {{0x3E7, 0x0, 0x0, 0x80030000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_float_to_decimal_5) {
  float num = -9;
  decimal_t expected = {{0x9, 0x0, 0, 0x80000000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_float_to_decimal_6) {
  float num = 7.777777;
  decimal_t expected = {{0x76ADF1, 0x0, 0x0, 0x60000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_float_to_decimal_7) {
  float num = 1237.0000000777777;
  // 1237
  decimal_t expected = {{0x4D5, 0x0, 0x0, 0x0}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_float_to_decimal_8) {
  float num = -5678919.364777777589102467469;
  //-5678920
  decimal_t expected = {{0x56A748, 0x0, 0x0, 0x80000000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_float_to_decimal_9) {
  float num = 1.000000000789;
  // 1
  decimal_t expected = {{0x1, 0x0, 0x0, 0x0}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_float_to_decimal_10) {
  float num = -0.1;
  decimal_t expected = {{0x1, 0x0, 0x0, 0x80010000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_float_to_decimal_11) {
  float num = 0.0000000000000000000000000002;
  decimal_t expected = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_float_to_decimal_12) {
  float num = -0.000000000000000000000000000001;
  decimal_t expected = NEW;

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_FLOAT, 12);
}

START_TEST(test_float_to_decimal_13) {
  float num = 79228162514264337593543950335.0005;
  decimal_t expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_FLOAT, 13);
}

START_TEST(test_float_to_decimal_14) {
  float num = -0.0000000000000000816909314548;
  //-0.00000000000000008169093
  decimal_t expected = {{0x7CA685, 0x0, 0x0, 0x80170000}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_float_to_decimal_15) {
  float num = 421181508;
  // 421181500
  decimal_t expected = {{0x191AB83C, 0x0, 0x0, 0x0}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_OK, 15);
}

START_TEST(test_float_to_decimal_16) {
  float num = NAN;

  decimal_t expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_FLOAT, 16);
}

START_TEST(test_float_to_decimal_17) {
  float num = 0.000000000000000000000000000001;

  decimal_t expected = {{0x0, 0x0, 0x0, 0x0}};

  test_float_to_decimal(num, expected, TEST_ERROR_CODE_FLOAT, 17);
}

START_TEST(test_float_to_decimal_18) {
  float a = 0;
  int expected_error_code = 1;
  int error_code = from_float_to_decimal(a, NULL);
  ck_assert_int_eq(error_code, expected_error_code);
}

Suite *float_to_decimal_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("float_to_decimal_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_float_to_decimal_1);
  tcase_add_test(core, test_float_to_decimal_2);
  tcase_add_test(core, test_float_to_decimal_3);
  tcase_add_test(core, test_float_to_decimal_4);
  tcase_add_test(core, test_float_to_decimal_5);
  tcase_add_test(core, test_float_to_decimal_6);
  tcase_add_test(core, test_float_to_decimal_7);
  tcase_add_test(core, test_float_to_decimal_8);
  tcase_add_test(core, test_float_to_decimal_9);
  tcase_add_test(core, test_float_to_decimal_10);
  tcase_add_test(core, test_float_to_decimal_11);
  tcase_add_test(core, test_float_to_decimal_12);
  tcase_add_test(core, test_float_to_decimal_13);
  tcase_add_test(core, test_float_to_decimal_14);
  tcase_add_test(core, test_float_to_decimal_15);
  tcase_add_test(core, test_float_to_decimal_16);
  tcase_add_test(core, test_float_to_decimal_17);
  tcase_add_test(core, test_float_to_decimal_18);

  suite_add_tcase(suite, core);

  return (suite);
}
