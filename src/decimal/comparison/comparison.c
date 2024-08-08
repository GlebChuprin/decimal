#include "comparison.h"

int compare(decimal_t value_1, decimal_t value_2) {
  int256 data_1 = NEW;
  int256 data_2 = NEW;

  preprocessing(value_1, value_2, &data_1, &data_2);

  if (!int256_is_not_zero(data_1)) decimal_set_sign(&value_1, POSITIVE);
  if (!int256_is_not_zero(data_2)) decimal_set_sign(&value_2, POSITIVE);

  int sign = SIGN_DEC(value_1) ^ SIGN_DEC(value_2) ? -1 : 1;

  return compare_int256(data_1, data_2) * sign;
}

int is_equal(decimal_t value_1, decimal_t value_2) {
  return (compare(value_1, value_2) == 0);
}

int is_not_equal(decimal_t value_1, decimal_t value_2) {
  return (compare(value_1, value_2) != 0);
}

int is_less(decimal_t value_1, decimal_t value_2) {
  return (compare(value_1, value_2) < 0);
}

int is_less_or_equal(decimal_t value_1, decimal_t value_2) {
  return (compare(value_1, value_2) <= 0);
}

int is_greater(decimal_t value_1, decimal_t value_2) {
  return (compare(value_1, value_2) > 0);
}

int is_greater_or_equal(decimal_t value_1, decimal_t value_2) {
  return (compare(value_1, value_2) >= 0);
}
