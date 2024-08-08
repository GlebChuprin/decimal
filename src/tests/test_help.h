#ifndef CHECK_TEST_HELP_H
#define CHECK_TEST_HELP_H

#include <check.h>
#include <math.h>

#include "../decimal.h"

#ifdef DEBUG

#include "stdio.h"

void print_int256(int256 int256);
void print_decimal(decimal_t decimal);

#endif

void test_dvv(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num);
void test_mul(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num);
void test_sub(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num);
void test_add(decimal_t decimal1, decimal_t decimal2,
                  decimal_t expected, int expected_error_code, int test_num);

void test_float_to_decimal(float flt, decimal_t expected,
                               int expected_error_code, int test_num);
void test_decimal_to_float(decimal_t decimal, float flt,
                               int expected_error_code, int test_num);
void test_int_to_decimal(int num, decimal_t expected,
                             int expected_error_code, int test_num);
void test_decimal_to_int(decimal_t decimal, int expected,
                             int expected_error_code, int test_num);

void test_less(decimal_t decimal1, decimal_t decimal2, int expected,
                   int test_num);
void test_less_or_equal(decimal_t decimal1, decimal_t decimal2,
                            int expected, int test_num);
void test_greater(decimal_t decimal1, decimal_t decimal2, int expected,
                      int test_num);
void test_greater_or_equal(decimal_t decimal1, decimal_t decimal2,
                               int expected, int test_num);
void test_equal(decimal_t decimal1, decimal_t decimal2, int expected,
                    int test_num);
void test_not_equal(decimal_t decimal1, decimal_t decimal2,
                        int expected, int test_num);

void test_negate(decimal_t decimal, decimal_t expected,
                     int expected_error_code, int test_num);
void test_truncate(decimal_t decimal, decimal_t expected,
                       int expected_error_code, int test_num);
void test_floor(decimal_t decimal, decimal_t expected,
                    int expected_error_code, int test_num);
void test_round(decimal_t decimal, decimal_t expected,
                    int expected_error_code, int test_num);

#endif
