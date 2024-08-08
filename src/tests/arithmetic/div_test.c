#include "decimal_test.h"

START_TEST(test_dvv_1) {
  decimal_t decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  decimal_t decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  decimal_t expected = {{0x0, 0x0, 0x1, 0x80180000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 1);
}

START_TEST(test_dvv_2) {
  decimal_t decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  decimal_t decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  decimal_t expected = {{0x7D, 0x7D, 0x0, 0x80030000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 2);
}

START_TEST(test_dvv_3) {
  decimal_t decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  decimal_t decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  decimal_t expected = {{0x129776EC, 0x9FC9D0A2, 0x8AA3A528, 0x130000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 3);
}

START_TEST(test_dvv_4) {
  decimal_t decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  decimal_t decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  decimal_t expected = {{0x1, 0x1, 0x0, 0x10000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 4);
}

START_TEST(test_dvv_5) {
  decimal_t decimal1 = {{0x1F4, 0, 0, 0}};
  decimal_t decimal2 = {{0xA, 0, 0, 0}};
  decimal_t expected = {{0x32, 0, 0, 0}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 5);
}

START_TEST(test_dvv_6) {
  decimal_t decimal1 = {{0x6A528800, 0x74, 0, 0}};
  decimal_t decimal2 = {{0xA, 0, 0, 0}};
  decimal_t expected = {{0xA43B7400, 0xB, 0, 0}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 6);
}

START_TEST(test_dvv_7) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  decimal_t expected = NEW;

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_BIG, 7);
}

START_TEST(test_dvv_8) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  decimal_t expected = NEW;

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_SMALL, 8);
}

START_TEST(test_dvv_9) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = NEW;
  decimal_t expected = NEW;

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_DIV_ZERO, 9);
}

START_TEST(test_dvv_10) {
  decimal_t decimal1 = NEW;
  decimal_t decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0}};
  decimal_t expected = NEW;

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 10);
}

START_TEST(test_dvv_11) {
  decimal_t decimal1 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  decimal_t decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  decimal_t expected = {{0x3C2CB79D, 0x3E0B91AF, 0x7623FB44, 0x130000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 11);
}

START_TEST(test_dvv_12) {
  decimal_t decimal1 = NEW;
  decimal_t decimal2 = NEW;
  decimal_t expected = NEW;

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_DIV_ZERO, 12);
}

START_TEST(test_dvv_13) {
  decimal_t decimal1 = {{0x1F40, 0x0, 0x0, 0x30000}};
  decimal_t decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  decimal_t expected = {{0xFA0, 0x0, 0x0, 0x80030000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 13);
}

START_TEST(test_dvv_14) {
  decimal_t decimal1 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  decimal_t decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  decimal_t expected = {{0x16D55555, 0x1F453787, 0x8A0055, 0x1C0000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 14);
}

START_TEST(test_dvv_15) {
  decimal_t decimal1 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  decimal_t decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  decimal_t expected = {{0x16D55555, 0x1F453787, 0x8A0055, 0x1C0000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 15);
}

START_TEST(test_dvv_16) {
  decimal_t decimal1 = {{0xA, 0x0, 0x0, 0x80000000}};
  decimal_t decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  decimal_t expected = {{0x74000019, 0x4FE8401E, 0x19D971E, 0x801A0000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 16);
}

START_TEST(test_dvv_17) {
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  decimal_t expected = {{0x0, 0x0, 0x0, 0x801B0000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 17);
}

START_TEST(test_dvv_18) {
  decimal_t decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  decimal_t decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  decimal_t expected = {{0x0, 0x2, 0x0, 0x80000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 18);
}

START_TEST(test_dvv_19) {
  decimal_t decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  decimal_t expected = {{0x0, 0x0, 0x0, 0x801B0000}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 19);
}

START_TEST(test_dvv_20) {
  decimal_t decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  decimal_t expected = {{0x1, 0x0, 0x0, 0x0}};

  test_dvv(decimal1, decimal2, expected, TEST_ERROR_CODE_OK, 20);
}

Suite *dvv_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("dvv_test");
  core = tcase_create("Core");

  tcase_add_test(core, test_dvv_1);
  tcase_add_test(core, test_dvv_2);
  tcase_add_test(core, test_dvv_3);
  tcase_add_test(core, test_dvv_4);
  tcase_add_test(core, test_dvv_5);
  tcase_add_test(core, test_dvv_6);
  tcase_add_test(core, test_dvv_7);
  tcase_add_test(core, test_dvv_8);
  tcase_add_test(core, test_dvv_9);
  tcase_add_test(core, test_dvv_10);
  tcase_add_test(core, test_dvv_11);
  tcase_add_test(core, test_dvv_12);
  tcase_add_test(core, test_dvv_13);
  tcase_add_test(core, test_dvv_14);
  tcase_add_test(core, test_dvv_15);
  tcase_add_test(core, test_dvv_16);
  tcase_add_test(core, test_dvv_17);
  tcase_add_test(core, test_dvv_18);
  tcase_add_test(core, test_dvv_19);
  tcase_add_test(core, test_dvv_20);

  suite_add_tcase(suite, core);

  return (suite);
}
