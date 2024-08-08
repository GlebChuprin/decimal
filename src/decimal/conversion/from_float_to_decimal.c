#include <math.h>

#include "conversion.h"

int from_float_to_decimal(float src, decimal_t *dst) {
  int code = OK;

  int256 data = NEW;
  decimal_bit3 bit3 = NEW;

  if (!dst)
    code = ERROR;
  else if (isinf(src) || isnan(src)) {
    code = ERROR;
    data = DECIMAL_TO_INT256(DECIMAL_INF);
  } else
    float_to_int256(src, &data, &bit3);

  if (highest_bit(data) >= (FULL_DECIMAL - BLOCK - 1)) {
    code = ERROR;
    data.decimals[0] = DECIMAL_INF;
  }
  if (highest_bit(data) == 0 && EXP(bit3) >= 28) {
    code = ERROR;
    bit3.i = 0;
  }

  if (!code) int256_round_seven_digit(&data);

  if (dst) {
    *dst = INT256_TO_DECIMAL(data);
    dst->bits[3] = bit3.i;
  }
  return code;
}

void float_to_int256(float src, int256 *data, decimal_bit3 *bit3) {
  float_part parsed_src = FLOAT_PART(src);
  int256 mantiss = INT256(MANTISS(parsed_src));
  int exponent = EXP(parsed_src) - BIAS;
  int exponent_decimal = 0;

  set_bit(&mantiss, MAX_BIT_DECIMAL_MANTISS);

  if (exponent < MAX_BIT_DECIMAL_MANTISS) {
    int256 max_mantiss = NEW;

    set_bit(&max_mantiss, MAX_BIT_DECIMAL_MANTISS - exponent);
    *data = binary_fractional_division(mantiss, max_mantiss, NULL,
                                           &exponent_decimal);
  } else
    *data = shift_left(mantiss, exponent - MAX_BIT_DECIMAL_MANTISS);

  int256_round_seven_digit(data);

  SIGN(parsed_src) ? SIGN(*bit3) = 1 : 0;
  EXP(*bit3) = exponent_decimal;
}

void int256_round_seven_digit(int256 *data) {
  int highest_digit = int256_highest_digit(*data);
  int rounder = highest_digit > 7 ? highest_digit - 7 : 0;

  *data = round_to_decimal(*data, rounder, BANK_ROUND);

  *data =
      binary_multiplication(*data, decimal_exp(DECIMAL(1), rounder));
}
