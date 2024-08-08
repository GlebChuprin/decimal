#include "decimal_test.h"

START_TEST(test_decimal_to_float_1) {
  // 1.5
  decimal_t decimal = {{0xF, 0x0, 0x0, 0x10000}};
  float expected = 1.5;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_decimal_to_float_2) {
  // 3569.78124
  decimal_t decimal = {{0x15470DCC, 0x0, 0x0, 0x00050000}};
  float expected = 3569.78124;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_decimal_to_float_3) {
  //-0.0000000795672222222
  decimal_t decimal = {{0x41C29A0E, 0xB9, 0x0, 0x80130000}};
  float expected = -0.0000000795672222222;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_decimal_to_float_4) {
  // 0
  decimal_t decimal = {{0x0, 0x0, 0x0, 0x0}};
  float expected = 0.;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_decimal_to_float_5) {
  //-0
  decimal_t decimal = {{0x0, 0x0, 0x0, 0x80000000}};
  float expected = -0.;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_decimal_to_float_6) {
  //-0.17456847232188684569862656
  decimal_t decimal = {{0xF282E200, 0x95AE8703, 0xE70A1, 0x801A0000}};
  float expected = -0.17456847232188684569862656;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_decimal_to_float_7) {
  // 0.1
  decimal_t decimal = {{0x1, 0x0, 0x0, 0x10000}};
  float expected = 0.1;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_decimal_to_float_8) {
  // 123412341234
  decimal_t decimal = {{0x12D4CB, 0x0, 0x0, 0x0}};
  float expected = 1234123;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_decimal_to_float_9) {
  //-123412341234.12341234
  decimal_t decimal = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80080000}};
  float expected = -123412341234.12341234;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_decimal_to_float_10) {
  // 123412341234.12341234
  decimal_t decimal = {{0x6FEC01F2, 0xAB44DF0C, 0x0, 0x80000}};
  float expected = 123412341234.12341234;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_decimal_to_float_11) {
  // 547
  decimal_t decimal = {{0x223, 0x0, 0x0, 0x0}};
  float expected = 547;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_decimal_to_float_12) {
  //-9
  decimal_t decimal = {{0x9, 0x0, 0x0, 0x80000000}};
  float expected = -9;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_decimal_to_float_13) {
  //-1.0000000000000000000007
  decimal_t decimal = {{0xB2400007, 0x19E0C9BA, 0x21E, 0x80160000}};
  float expected = -1;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_decimal_to_float_14) {
  //-7000000000000000.303
  decimal_t decimal = {{0x93BC012F, 0x6124FEE9, 0x0, 0x80030000}};
  float expected = -7000000000000000.303;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_decimal_to_float_15) {
  // 17.23
  decimal_t decimal = {{0x6BB, 0x0, 0x0, 0x20000}};
  float expected = 17.23;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 15);
}

START_TEST(test_decimal_to_float_16) {
  //-217.2378
  decimal_t decimal = {{0x2125DA, 0x0, 0x0, 0x80040000}};
  float expected = -217.2378;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 16);
}

START_TEST(test_decimal_to_float_17) {
  // 0.003457
  decimal_t decimal = {{0xD81, 0x0, 0x0, 0x60000}};
  float expected = 0.003457;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 17);
}

START_TEST(test_decimal_to_float_18) {
  // 0.003457000001
  decimal_t decimal = {{0xCE0DA241, 0x0, 0x0, 0xC0000}};
  float expected = 0.003457;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 18);
}

START_TEST(test_decimal_to_float_19) {
  // 79228162514264337593543950335
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  float expected = 79228162514264337593543950335.;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 19);
}

START_TEST(test_decimal_to_float_20) {
  //-79228162514264337593543950335
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  float expected = -79228162514264337593543950335.;
  test_decimal_to_float(decimal, expected, TEST_ERROR_CODE_OK, 20);
}

START_TEST(test_decimal_to_float_21) {
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int expected_error_code = 1;
  int error_code = from_decimal_to_float(decimal, NULL);
  ck_assert_int_eq(error_code, expected_error_code);
}

Suite *decimal_to_float_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("decimal_to_float_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_decimal_to_float_1);
  tcase_add_test(core, test_decimal_to_float_2);
  tcase_add_test(core, test_decimal_to_float_3);
  tcase_add_test(core, test_decimal_to_float_4);
  tcase_add_test(core, test_decimal_to_float_5);
  tcase_add_test(core, test_decimal_to_float_6);
  tcase_add_test(core, test_decimal_to_float_7);
  tcase_add_test(core, test_decimal_to_float_8);
  tcase_add_test(core, test_decimal_to_float_9);
  tcase_add_test(core, test_decimal_to_float_10);
  tcase_add_test(core, test_decimal_to_float_11);
  tcase_add_test(core, test_decimal_to_float_12);
  tcase_add_test(core, test_decimal_to_float_13);
  tcase_add_test(core, test_decimal_to_float_14);
  tcase_add_test(core, test_decimal_to_float_15);
  tcase_add_test(core, test_decimal_to_float_16);
  tcase_add_test(core, test_decimal_to_float_17);
  tcase_add_test(core, test_decimal_to_float_18);
  tcase_add_test(core, test_decimal_to_float_19);
  tcase_add_test(core, test_decimal_to_float_20);
  tcase_add_test(core, test_decimal_to_float_21);

  suite_add_tcase(suite, core);

  return (suite);
}