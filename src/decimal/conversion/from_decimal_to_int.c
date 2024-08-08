#include "conversion.h"

int from_decimal_to_int(decimal_t src, int *dst) {
  int code = OK;

  if (!dst)
    code = ERROR;
  else {
    *dst = 0;
    decimal_t truncated = NEW;
    truncate(src, &truncated);

    if (is_less(truncated, DEC_INT_MIN))
      code = ERROR;
    else if (is_greater(truncated, DEC_INT_MAX))
      code = ERROR;
    else
      *dst = truncated.bits[0];

    if ((SIGN_DEC(src) == NEGATIVE) && (*dst != INT32_MIN)) *dst = *dst * -1;
  }
  return code;
}