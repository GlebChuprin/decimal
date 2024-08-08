#include "arithmetic_service.h"

int256 decimal_exp(decimal_t decimal, int exp) {
  int256 result = DECIMAL_TO_INT256(decimal);

  while (exp-- > 0) result = mul10(result);

  return result;
}

int leveling(decimal_t value_1, decimal_t value_2, int256 *data_1,
                 int256 *data_2) {
  int exp_1 = EXP_DEC(value_1);
  int exp_2 = EXP_DEC(value_2);

  *data_1 = decimal_exp(value_1, exp_2 - exp_1);
  *data_2 = decimal_exp(value_2, exp_1 - exp_2);

  return MAX(exp_1, exp_2);
}

int preprocessing(decimal_t value_1, decimal_t value_2,
                      int256 *data_1, int256 *data_2) {
  int exp = leveling(value_1, value_2, data_1, data_2);

  if (SIGN_DEC(value_1)) *data_1 = negative_int256(*data_1);
  if (SIGN_DEC(value_2)) *data_2 = negative_int256(*data_2);

  return exp;
}

int int256_to_decimal(int256 data, decimal_t *decimal,
                          decimal_bit3 bit3) {
  int rc = OK;

  int rounder = MAX(find_rounder(data), EXP(bit3) - EXP_LIMIT);

  if (rounder > EXP(bit3))
    rc = SIGN(bit3) ? DECIMAL_SMALL : DECIMAL_BIG;
  else
    data = round_to_decimal(data, rounder, BANK_ROUND);

  if (highest_bit(data) > FULL_DECIMAL - BLOCK - 1)
    rc = SIGN(bit3) ? DECIMAL_SMALL : DECIMAL_BIG;
  else {
    EXP(bit3) -= rounder;
    *decimal = INT256_TO_DECIMAL(data);
    decimal->bits[3] = bit3.i;
  }

  return rc;
}

void decimal_set_sign(decimal_t *decimal, int sign) {
  decimal_bit3 bit3 = {.i = decimal->bits[3]};
  SIGN(bit3) = sign;

  decimal->bits[3] = bit3.i;
}

void decimal_set_exp(decimal_t *decimal, int exp) {
  decimal_bit3 bit3 = {.i = decimal->bits[3]};
  EXP(bit3) = exp;

  decimal->bits[3] = bit3.i;
}

int int256_highest_digit(int256 data) {
  int highest_digit = 0;
  int256 ten = INT256(10);

  while (int256_is_not_zero(data))
    data = binary_division(data, ten, NULL), highest_digit++;

  return highest_digit;
}
