#ifndef CHECK_DECIMAL_TEST_H
#define CHECK_DECIMAL_TEST_H

#include "test_help.h"

#define TEST_ERROR_CODE_OK 0
#define TEST_ERROR_CODE_BIG 1
#define TEST_ERROR_CODE_SMALL 2
#define TEST_ERROR_CODE_DIV_ZERO 3
#define TEST_ERROR_CODE_FLOAT 1
#define TEST_ERROR_CODE_INT 1
#define TRUE 1
#define FALSE 0

Suite *add_test(void);
Suite *dvv_test(void);
Suite *mul_test(void);
Suite *sub_test(void);

Suite *float_to_decimal_test(void);
Suite *decimal_to_float_test(void);
Suite *int_to_decimal_test(void);
Suite *decimal_to_int_test(void);

Suite *less_test(void);
Suite *less_or_equal_test(void);
Suite *greater_test(void);
Suite *greater_or_equal_test(void);
Suite *equal_test(void);
Suite *not_equal_test(void);

Suite *negate_test(void);
Suite *truncate_test(void);
Suite *floor_test(void);
Suite *round_test(void);

#endif
