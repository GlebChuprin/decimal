#include "decimal_test.h"

START_TEST(test_decimal_to_int_1) {
  // 1
  decimal_t decimal = {{0x1, 0x0, 0x0, 0x0}};
  int expected = 1;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_decimal_to_int_2) {
  // 596132
  decimal_t decimal = {{0x918A4, 0x0, 0x0, 0x0}};
  int expected = 596132;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_decimal_to_int_3) {
  //-7
  decimal_t decimal = {{0x7, 0x0, 0x0, 0x80000000}};
  int expected = -7;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_decimal_to_int_4) {
  //-2147483648
  decimal_t decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int expected = -2147483648;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_decimal_to_int_5) {
  // 2147483647;
  decimal_t decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  int expected = 2147483647;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_decimal_to_int_6) {
  // 1.5
  decimal_t decimal = {{0xF, 0x0, 0x0, 0x10000}};
  int expected = 1;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_decimal_to_int_7) {
  //-7.55492164
  decimal_t decimal = {{0x2D07E544, 0x0, 0x0, 0x80080000}};
  int expected = -7;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_decimal_to_int_8) {
  //-845613.746513248989248954
  decimal_t decimal = {{0xEAB47DBA, 0xD0243827, 0xB310, 0x80120000}};
  int expected = -845613;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_decimal_to_int_9) {
  // 481516.2342
  decimal_t decimal = {{0x1F018BE6, 0x1, 0x0, 0x40000}};
  int expected = 481516;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_decimal_to_int_10) {
  //-0.14569721534856
  decimal_t decimal = {{0x47139988, 0xD40, 0x0, 0x800E0000}};
  int expected = 0;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_decimal_to_int_11) {
  // 13
  decimal_t decimal = {{0xD, 0x0, 0x0, 0x0}};
  int expected = 13;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_decimal_to_int_12) {
  // 789554655494545595
  decimal_t decimal = {{0xA38220BB, 0xAF50FC6, 0x0, 0x0}};
  int expected = 0;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_INT, 12);
}

START_TEST(test_decimal_to_int_13) {
  // 79228162514264337593543950335
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int expected = 0;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_INT, 13);
}

START_TEST(test_decimal_to_int_14) {
  // 792281625142643375935439.50335
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int expected = 0;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_INT, 14);
}

START_TEST(test_decimal_to_int_15) {
  //-79228162514264337593543950335
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int expected = 0;
  test_decimal_to_int(decimal, expected, TEST_ERROR_CODE_INT, 15);
}

START_TEST(test_decimal_to_int_16) {
  decimal_t decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int expected_error_code = 1;
  int error_code = from_decimal_to_int(decimal, NULL);
  ck_assert_int_eq(error_code, expected_error_code);
}

Suite *decimal_to_int_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("decimal_to_int_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_decimal_to_int_1);
  tcase_add_test(core, test_decimal_to_int_2);
  tcase_add_test(core, test_decimal_to_int_3);
  tcase_add_test(core, test_decimal_to_int_4);
  tcase_add_test(core, test_decimal_to_int_5);
  tcase_add_test(core, test_decimal_to_int_6);
  tcase_add_test(core, test_decimal_to_int_7);
  tcase_add_test(core, test_decimal_to_int_8);
  tcase_add_test(core, test_decimal_to_int_9);
  tcase_add_test(core, test_decimal_to_int_10);
  tcase_add_test(core, test_decimal_to_int_11);
  tcase_add_test(core, test_decimal_to_int_12);
  tcase_add_test(core, test_decimal_to_int_13);
  tcase_add_test(core, test_decimal_to_int_14);
  tcase_add_test(core, test_decimal_to_int_15);
  tcase_add_test(core, test_decimal_to_int_16);

  suite_add_tcase(suite, core);

  return (suite);
}