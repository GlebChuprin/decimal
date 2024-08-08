#include "conversion.h"

int from_int_to_decimal(int src, decimal_t *dst) {
  int code = OK;

  if (!dst)
    code = ERROR;
  else {
    *dst = DECIMAL(0);

    if (src < 0) {
      decimal_set_sign(dst, NEGATIVE);

      if (src != INT_MIN) src = -src;
    }

    dst->bits[0] = src;
  }

  return code;
}