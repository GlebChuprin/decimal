#include "conversion.h"

int from_decimal_to_float(decimal_t src, float *dst) {
  int code = OK;
  double df = 0;
  int exponent = EXP_DEC(src);
  int256 data = DECIMAL_TO_INT256(src);

  if (!dst)
    code = ERROR;
  else if (int256_is_not_zero(data))
    int256_to_double(&data, &df);

  while (exponent) {
    df /= 10.0;
    exponent--;
  }

  if (SIGN_DEC(src)) df *= -1.;
  if (dst) *dst = (float)df;

  return code;
}

void int256_to_double(int256 *data, double *src) {
  int256 mantiss = *data;
  int highest_bit_of_data = highest_bit(mantiss);
  int shift = 52 - highest_bit_of_data;
  if (shift > 0)
    mantiss = shift_left(mantiss, shift);
  else {
    mantiss = shift_right(mantiss, (-shift) - 1);

    if (is_set_bit(mantiss, 0)) set_bit(&mantiss, 1);

    mantiss = shift_right(mantiss, 1);
  }
  reset_bit(&mantiss, 52);

  double_part parsed_src = NEW;
  uint64_t_part parsed_uint;
  parsed_uint.parse.bit0 = mantiss.decimals[0].bits[0];
  parsed_uint.parse.bit1 = mantiss.decimals[0].bits[1];
  parsed_src.parse.mantiss = parsed_uint.uint;
  parsed_src.parse.exponent = 1023 + highest_bit_of_data;

  *src = parsed_src.df;
}
