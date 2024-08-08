#include "other.h"

int negate(decimal_t value, decimal_t *result) {
  int rc = OK;

  if (!(rc = check_bit3_decimal(value)) && !(rc = !result)) {
    decimal_set_sign(&value, !SIGN_DEC(value));

    *result = value;
  }

  return rc;
}

int truncate(decimal_t value, decimal_t *result) {
  return round_decimal(value, result, TRUNCATE_ROUND);
}

int floor_f(decimal_t value, decimal_t *result) {
  return round_decimal(value, result,
                           SIGN_DEC(value) ? CEIL_ROUND : FLOOR_ROUND);
}

int round_f(decimal_t value, decimal_t *result) {
  return round_decimal(value, result, BASIC_ROUND);
}
