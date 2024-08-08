#include "binary.h"

int256 inverse_int256(int256 data) {
  for (int grade_index = 0; grade_index < FULL_INT256; grade_index += BLOCK)
    GET_GRADE(data, grade_index) = ~GET_GRADE(data, grade_index);

  return data;
}

int256 negative_int256(int256 data) {
  return binary_addition(inverse_int256(data), INT256(1));
}

void set_grade_bit(int *grade, int index) { *grade |= (1U << index); }

void set_bit(int256 *data, int index) {
  set_grade_bit(&GET_GRADE(*data, index), index % BLOCK);
}

int is_set_grade_bit(int grade, int index) {
  return !!(grade & (1U << index));
}

int is_set_bit(int256 data, int index) {
  return is_set_grade_bit(GET_GRADE(data, index), index % BLOCK);
}

void reset_grade_bit(int *grade, int index) { *grade &= ~(1U << index); }

void reset_bit(int256 *data, int index) {
  reset_grade_bit(&GET_GRADE(*data, index), index % BLOCK);
}
