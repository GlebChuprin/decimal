#ifndef ARITHMETIC_SERVICE_H
#define ARITHMETIC_SERVICE_H

#include "binary.h"
#include "comparison.h"
#include "other.h"
#include "type.h"

#define OK 0
#define DECIMAL_BIG 1
#define DECIMAL_SMALL 2
#define DIV_BY_ZERO 3
#define INCORRECT_DATA 4

#define ERROR 1
#define NEGATIVE 1
#define POSITIVE 0

// decimal

#define DECIMAL(value) ((decimal_t){.bits[0] = (value)})

#define DECIMAL_TO_INT256(d) \
  ((int256){.decimals[0].bits = {d.bits[0], d.bits[1], d.bits[2], 0}})

#define INT256_TO_DECIMAL(d) ((d).decimals[0])

#define DECIMAL_MAX                             \
  (decimal_t) {                               \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0 } \
  }

#define DECIMAL_INF                                    \
  (decimal_t) {                                      \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF } \
  }

#define DECIMAL_BANK \
  (decimal_t) { .bits[0] = 5, .bits[3] = 0x00010000 }

// bit3 / float_part

#define BIT3(dec) ((decimal_bit3)(dec).bits[3])

#define FLOAT_PART(float) ((float_part)(float))

#define MANTISS(bit3) ((bit3).parse.mantiss)

#define EXP(bit3) ((bit3).parse.exp)

#define SIGN(bit3) ((bit3).parse.sign)

#define BLANKS(dec) \
  (BIT3(dec).parse.blank1 + BIT3(dec).parse.blank2)

#define EXP_DEC(dec) (EXP(BIT3((dec))))

#define SIGN_DEC(dec) (SIGN(BIT3(dec)))

#define MAX(a, b) ((a) > (b) ? a : b)

int256 decimal_exp(decimal_t decimal, int exp);

int int256_to_decimal(int256 data, decimal_t *decimal,
                          decimal_bit3 bit3);
int preprocessing(decimal_t value_1, decimal_t value_2,
                      int256 *data_1, int256 *data_2);

int check_is_zero(decimal_t decimal);
int check_bit3_decimal(decimal_t decimal);
int check_input(decimal_t value_1, decimal_t value_2,
                    decimal_t *result);

void decimal_set_sign(decimal_t *decimal, int sign);
void decimal_set_exp(decimal_t *decimal, int exp);

int int256_highest_digit(int256 data);

typedef enum round_mode {
  TRUNCATE_ROUND,
  FLOOR_ROUND,
  BANK_ROUND,
  BASIC_ROUND,
  CEIL_ROUND
} round_mode;

int256 round_to_decimal(int256 data, int rounder, round_mode mode);
int round_decimal(decimal_t value, decimal_t *result, round_mode mode);
int find_rounder(int256 data);

#endif