#include "arithmetic.h"

int add(decimal_t value_1, decimal_t value_2, decimal_t *result) {
  int rc = OK;

  if (!(rc = check_input(value_1, value_2, result))) {
    int256 data_res = NEW;
    int256 data_1 = NEW;
    int256 data_2 = NEW;

    decimal_bit3 bit3 = NEW;

    EXP(bit3) = preprocessing(value_1, value_2, &data_1, &data_2);

    data_res = binary_addition(data_1, data_2);

    if (is_set_bit(data_res, FULL_INT256 - 1))
      data_res = negative_int256(data_res), SIGN(bit3) = 1;

    rc = int256_to_decimal(data_res, result, bit3);
  }

  return rc;
}
