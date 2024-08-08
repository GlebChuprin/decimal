#include "arithmetic_service.h"

int round_decimal(decimal_t value, decimal_t *result, round_mode mode) {
  int rc = 0;

  if (!(rc = check_bit3_decimal(value)) && !(rc = !result)) {
    int256 data =
        round_to_decimal(DECIMAL_TO_INT256(value), EXP_DEC(value), mode);

    *result = INT256_TO_DECIMAL(data);

    decimal_set_sign(result, SIGN_DEC(value));
  }

  return rc;
}

int round_conditions(int remainder, round_mode mode) {
  int round = (mode == CEIL_ROUND) ? 1 : 0;

  if (mode == BASIC_ROUND || mode == BANK_ROUND) round = remainder < 5 ? 0 : 1;

  return round;
}

int find_rounder(int256 data) {
  int256 result = NEW;

  result = binary_division(data, DECIMAL_TO_INT256(DECIMAL_MAX), NULL);

  return is_greater(INT256_TO_DECIMAL(result), DECIMAL(1))
             ? int256_highest_digit(result)
             : 0;
}

int256 find_remainder(int256 *data, int rounder) {
  int256 remainder = NEW;

  *data = binary_division(*data, decimal_exp(DECIMAL(1), rounder),
                              &remainder);

  return remainder;
}

int round_float_part(int256 data, int256 remainder, int exp,
                         round_mode mode) {
  int round = 0;

  decimal_t dec_rem = INT256_TO_DECIMAL(remainder);
  decimal_set_exp(&dec_rem, exp);

  if (mode == BANK_ROUND && is_equal(dec_rem, DECIMAL_BANK))
    round = is_set_bit(data, 0);
  else {
    int256 rem_remainder = NEW;
    remainder = binary_division(
        remainder, decimal_exp(DECIMAL(1), exp - 1), &rem_remainder);

    if (int256_is_not_zero(remainder) ||
        int256_is_not_zero(rem_remainder))
      round = round_conditions(GET_GRADE(remainder, 0), mode);
  }

  return round;
}

int256 round_to_decimal(int256 data, int rounder, round_mode mode) {
  int256 remainder = NEW;

  remainder = find_remainder(&data, rounder);

  if (round_float_part(data, remainder, rounder, mode))
    data = binary_addition(data, INT256(1));

  return data;
}
