#include "decimal_test.h"

START_TEST(test_sub_1) {
  decimal_t decimal1 = NEW;
  decimal_t decimal2 = NEW;
  decimal_t expected = NEW;

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_sub_2) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t expected = NEW;

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_sub_3) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  decimal_t expected = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_sub_4) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t expected = NEW;

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_SMALL, 4);
}

START_TEST(test_sub_5) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  decimal_t expected = NEW;

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_BIG, 5);
}

START_TEST(test_sub_6) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t expected = NEW;

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_sub_7) {
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  decimal_t decimal2 = NEW;
  decimal_t expected = NEW;

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 7);
}

START_TEST(test_sub_8) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  decimal_t expected = {{0x0, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 8);
}

START_TEST(test_sub_9) {
  decimal_t decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  decimal_t decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  decimal_t expected = {{0x56E84F00, 0x55555555, 0x0, 0x0}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 9);
}

START_TEST(test_sub_10) {
  decimal_t decimal1 = {{0x8, 0x0, 0x0, 0x0}};
  decimal_t decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  decimal_t expected = {{0x10, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_sub_11) {
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  decimal_t decimal2 = {{0x55555565, 0x0, 0x55555555, 0x80150000}};
  decimal_t expected = {{0x55555565, 0x0, 0x55555555, 0x150000}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_sub_12) {
  decimal_t decimal1 = {{0x4C23E884, 0x648C703C, 0xC2A02CFF, 0x0}};
  decimal_t decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  decimal_t expected = {{0x4C23E884, 0x648C703C, 0xC2A02CFF, 0x0}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 12);
}

START_TEST(test_sub_13) {
  decimal_t decimal1 = NEW;
  decimal_t decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  decimal_t expected = {{0x55555555, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_sub_14) {
  decimal_t decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  decimal_t decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  decimal_t expected = {{0x1FFFFC17, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_sub_15) {
  decimal_t decimal1 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  decimal_t decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  decimal_t expected = {{0x53C25BAA, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 15);
}

Suite *sub_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("sub_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_sub_1);
  tcase_add_test(core, test_sub_2);
  tcase_add_test(core, test_sub_3);
  tcase_add_test(core, test_sub_4);
  tcase_add_test(core, test_sub_5);
  tcase_add_test(core, test_sub_6);
  tcase_add_test(core, test_sub_7);
  tcase_add_test(core, test_sub_8);
  tcase_add_test(core, test_sub_9);
  tcase_add_test(core, test_sub_10);
  tcase_add_test(core, test_sub_11);
  tcase_add_test(core, test_sub_12);
  tcase_add_test(core, test_sub_13);
  tcase_add_test(core, test_sub_14);
  tcase_add_test(core, test_sub_15);

  suite_add_tcase(suite, core);

  return (suite);
}
