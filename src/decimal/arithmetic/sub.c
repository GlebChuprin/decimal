#include "arithmetic.h"

int sub(decimal_t value_1, decimal_t value_2, decimal_t *result) {
  int rc = OK;

  if (!(rc = check_input(value_1, value_2, result)))
    if (!(rc = negate(value_2, &value_2)))
      rc = add(value_1, value_2, result);

  return rc;
}
