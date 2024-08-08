#ifndef BINARY_H
#define BINARY_H

#include "type.h"

#define INT256(value) ((int256){.decimals[0].bits[0] = (value)})

#define GET_BLOCK(index) ((index) / BLOCK)
#define GET_GRADE(int256, index)         \
  ((int256)                              \
       .decimals[(index) / FULL_DECIMAL] \
       .bits[GET_BLOCK((index) % FULL_DECIMAL)])

int256 binary_addition(int256 value_1, int256 value_2);
int256 binary_multiplication(int256 value_1, int256 value_2);
int256 binary_division(int256 divisible, int256 divider,
                               int256 *remainder);
int256 binary_fractional_division(int256 divisible,
                                          int256 divider,
                                          int256 *remainder, int *exp);

int256 mul10(int256 data);

int compare_int256(int256 value_1, int256 value_2);
int int256_is_not_zero(int256 data);
int highest_bit(int256 data);

int256 shift_right(int256 data, int shifts);
int256 shift_left(int256 data, int shifts);

int256 negative_int256(int256 data);

void reset_grade_bit(int *grade, int index);
void reset_bit(int256 *data, int index);
void set_bit(int256 *data, int index);
void set_grade_bit(int *grade, int index);
int is_set_bit(int256 data, int index);
int is_set_grade_bit(int grade, int index);

#endif