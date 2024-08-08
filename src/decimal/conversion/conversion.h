#ifndef CONVERSION_H
#define CONVERSION_H

#include <limits.h>

#include "arithmetic_service.h"
#include "type.h"

#define BIAS 127
#define MAX_BIT_DECIMAL_MANTISS 23
#define DEC_INT_MIN                      \
  (decimal_t) {                        \
    { 0x80000000, 0x0, 0x0, 0x80000000 } \
  }
#define DEC_INT_MAX               \
  (decimal_t) {                 \
    { 0x7FFFFFFF, 0x0, 0x0, 0x0 } \
  }

int from_float_to_decimal(float src, decimal_t *dst);
int from_decimal_to_float(decimal_t src, float *dst);
int from_int_to_decimal(int src, decimal_t *dst);
int from_decimal_to_int(decimal_t src, int *dst);

void float_to_int256(float src, int256 *data, decimal_bit3 *bit3);
void int256_round_seven_digit(int256 *data);
void int256_to_double(int256 *data, double *src);

typedef union double_part {
  double df;
  struct {
    uint64_t mantiss : 52;
    uint64_t exponent : 11;
    uint64_t sign : 1;
  } parse;
} double_part;

typedef union uint64_t_part {
  uint64_t uint;
  struct {
    int bit0 : 32;
    int bit1 : 32;
  } parse;

} uint64_t_part;

#endif
