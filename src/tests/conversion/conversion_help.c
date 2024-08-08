#include "test_help.h"

int compare_significant_digits(float a, float b, int significant_digits,
                                   decimal_t decimal, float expected) {
  if (is_equal(decimal, DECIMAL(0)) && (expected == 0.)) return 1;

  float scale = pow(10, significant_digits - ceil(log10(fabs(a > b ? a : b))));
  return fabs(round(a * scale) - round(b * scale)) < 1.0;
}

void test_float_to_decimal(float flt, decimal_t expected,
                               int expected_error_code, int test_num) {
  decimal_t result = NEW;
  (void)test_num;
  int error_code = from_float_to_decimal(flt, &result);

#ifdef DEBUG
  if (!is_equal(result, expected) || error_code != expected_error_code) {
    printf(
        "\n\033[36m------------------------- %s - %02d "
        "-------------------------\033[0m\n\n",
        "TEST FLT", test_num);

    printf("\033[33m%s\033[0m\n", "float:");
    printf("\n%f\n\n", flt);

    printf("\033[31m%s\033[0m\n", "result:");
    print_int256(DECIMAL_TO_INT256(result));
    print_decimal(result);

    printf("\033[32m%s\033[0m\n", "expected:");
    print_int256(DECIMAL_TO_INT256(expected));
    print_decimal(expected);

    printf("\033[36m%-21s%d\n%s%d\033[0m\n\n", "error code: ", error_code,
           "expected error code: ", expected_error_code);

    printf(
        "\033[36m--------------------------------------------------------------"
        "---\033[0m\n");
  }
#endif

  ck_assert_uint_eq(is_equal(result, expected), 1);
  ck_assert_uint_eq(error_code, expected_error_code);
}

void test_decimal_to_float(decimal_t decimal, float expected,
                               int expected_error_code, int test_num) {
  float result = 0;
  (void)test_num;
  int error_code = from_decimal_to_float(decimal, &result);

  int significant_digits = 7;

#ifdef DEBUG
  if ((result != expected) || error_code != expected_error_code) {
    printf(
        "\n\033[36m------------------------- %s - %02d "
        "-------------------------\033[0m\n\n",
        "TEST FLT", test_num);

    printf("\033[31m%s\033[0m\n", "decimal:");
    print_int256(DECIMAL_TO_INT256(decimal));
    print_decimal(decimal);

    printf("\033[33m%s\033[0m\n", "expected :");
    printf("\n%.10f\n\n", expected);

    printf("\033[33m%s\033[0m\n", "result :");
    printf("\n%.10f\n\n", result);

    printf("\033[36m%-21s%d\n%s%d\033[0m\n\n", "error code: ", error_code,
           "expected error code: ", expected_error_code);

    printf(
        "\033[36m--------------------------------------------------------------"
        "---\033[0m\n");
  }
#endif

  ck_assert_msg(compare_significant_digits(
                    result, expected, significant_digits, decimal, expected),
                "Expected %.35f but got %.35f with %d significant digits",
                result, expected, significant_digits);

  ck_assert_uint_eq(error_code, expected_error_code);
}

void test_int_to_decimal(int num, decimal_t expected,
                             int expected_error_code, int test_num) {
  decimal_t result = NEW;
  (void)test_num;
  int error_code = from_int_to_decimal(num, &result);

#ifdef DEBUG
  if (!is_equal(result, expected) || error_code != expected_error_code) {
    printf(
        "\n\033[36m------------------------- %s - %02d "
        "-------------------------\033[0m\n\n",
        "TEST INT", test_num);

    printf("\033[33m%s\033[0m\n", "int :");
    printf("\n%d\n\n", num);

    printf("\033[31m%s\033[0m\n", "result:");
    print_int256(DECIMAL_TO_INT256(result));
    print_decimal(result);

    printf("\033[32m%s\033[0m\n", "expected:");
    print_int256(DECIMAL_TO_INT256(expected));
    print_decimal(expected);

    printf("\033[36m%-21s%d\n%s%d\033[0m\n\n", "error code: ", error_code,
           "expected error code: ", expected_error_code);

    printf(
        "\033[36m--------------------------------------------------------------"
        "---\033[0m\n");
  }
#endif

  ck_assert_uint_eq(is_equal(result, expected), 1);
  ck_assert_uint_eq(error_code, expected_error_code);
}

void test_decimal_to_int(decimal_t decimal, int expected,
                             int expected_error_code, int test_num) {
  int result = 0;
  (void)test_num;
  int error_code = from_decimal_to_int(decimal, &result);

#ifdef DEBUG
  if ((result != expected) || error_code != expected_error_code) {
    printf(
        "\n\033[36m------------------------- %s - %02d "
        "-------------------------\033[0m\n\n",
        "TEST INT", test_num);

    printf("\033[31m%s\033[0m\n", "decimal:");
    print_int256(DECIMAL_TO_INT256(decimal));
    print_decimal(decimal);

    printf("\033[33m%s\033[0m\n", "expected :");
    printf("\n%d\n\n", expected);

    printf("\033[33m%s\033[0m\n", "result :");
    printf("\n%d\n\n", result);

    printf("\033[36m%-21s%d\n%s%d\033[0m\n\n", "error code: ", error_code,
           "expected error code: ", expected_error_code);

    printf(
        "\033[36m--------------------------------------------------------------"
        "---\033[0m\n");
  }
#endif

  ck_assert_int_eq(result, expected);
  ck_assert_uint_eq(error_code, expected_error_code);
}
