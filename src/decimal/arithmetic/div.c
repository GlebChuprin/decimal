#include "arithmetic.h"

int dvv(decimal_t value_1, decimal_t value_2, decimal_t *result) {
  int rc = OK;

  if (!(rc = check_input(value_1, value_2, result)) &&
      !(rc = check_is_zero(value_2))) {
    int256 data_res = NEW;

    decimal_bit3 bit3 = NEW;

    SIGN(bit3) = SIGN_DEC(value_1) ^ SIGN_DEC(value_2);
    int exp = EXP_DEC(value_1) - EXP_DEC(value_2);

    data_res = binary_fractional_division(
        DECIMAL_TO_INT256(value_1), DECIMAL_TO_INT256(value_2), NULL, &exp);

    EXP(bit3) = exp;

    rc = int256_to_decimal(data_res, result, bit3);
  }

  return rc;
}
