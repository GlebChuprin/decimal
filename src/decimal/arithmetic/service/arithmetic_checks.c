#include "arithmetic_service.h"

int check_is_zero(decimal_t decimal) {
  return is_equal(decimal, DECIMAL(0)) ? DIV_BY_ZERO : OK;
}

int check_bit3_decimal(decimal_t decimal) {
  return (BLANKS(decimal) || EXP_DEC(decimal) > EXP_LIMIT) ? INCORRECT_DATA
                                                           : OK;
}

int check_input(decimal_t value_1, decimal_t value_2,
                    decimal_t *result) {
  return (!result || check_bit3_decimal(value_1) ||
          check_bit3_decimal(value_2))
             ? INCORRECT_DATA
             : OK;
}
