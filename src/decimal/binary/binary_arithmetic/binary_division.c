#include "binary.h"

int256 binary_division(int256 divisible, int256 divider,
                               int256 *remainder) {
  int256 result = NEW;

  int sign = 0;
  int shifts = highest_bit(divisible) - highest_bit(divider);

  int256 pos_shift = shift_left(divider, shifts);
  int256 neg_shift = negative_int256(pos_shift);

  for (int i = shifts; i >= 0; i--) {
    divisible = binary_addition(divisible, sign ? pos_shift : neg_shift);

    sign = is_set_bit(divisible, FULL_INT256 - 1);

    if (i) divisible = shift_left(divisible, 1);

    result = shift_left(result, 1);

    if (!sign) set_bit(&result, 0);
  }

  if (remainder) {
    if (is_set_bit(divisible, FULL_INT256 - 1))
      divisible = binary_addition(divisible, pos_shift);

    *remainder = shift_right(divisible, shifts);
  }

  return result;
}

int256 binary_fractional_division(int256 divisible,
                                          int256 divider,
                                          int256 *remainder, int *exp) {
  int256 tmp_res_remainder = NEW;
  int256 tmp_remainder = NEW;

  divisible = binary_division(divisible, divider, &tmp_res_remainder);

  while ((int256_is_not_zero(tmp_res_remainder) && *exp < 28) || *exp < 0) {
    divisible = mul10(divisible);
    tmp_res_remainder = mul10(tmp_res_remainder);
    tmp_res_remainder =
        binary_division(tmp_res_remainder, divider, &tmp_remainder);
    divisible = binary_addition(divisible, tmp_res_remainder);
    tmp_res_remainder = tmp_remainder;

    (*exp)++;
  }

  if (remainder) *remainder = tmp_res_remainder;

  return divisible;
}
