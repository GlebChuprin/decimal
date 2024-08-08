#include "binary.h"

void shift_left_one(int256 *data);
void shift_right_one(int256 *data);

int256 shift_left(int256 data, int shifts) {
  while (shifts-- > 0) shift_left_one(&data);

  return data;
}

int256 shift_right(int256 data, int shifts) {
  while (shifts-- > 0) shift_right_one(&data);

  return data;
}

void shift_left_one(int256 *data) {
  int overflow = 0;

  for (int block_index = 0; block_index < FULL_INT256; block_index += BLOCK) {
    overflow |= is_set_grade_bit(GET_GRADE(*data, block_index), BLOCK - 1);

    GET_GRADE(*data, block_index) <<= 1;

    if (is_set_grade_bit(overflow, 1))
      set_grade_bit(&GET_GRADE(*data, block_index), 0);

    overflow <<= 1;
  }
}

void shift_right_one(int256 *data) {
  int overflow = 0;

  for (int grade_index = FULL_INT256 - BLOCK; grade_index >= 0;
       grade_index -= BLOCK) {
    overflow |= is_set_bit(*data, grade_index);

    GET_GRADE(*data, grade_index) >>= 1;

    if (is_set_grade_bit(overflow, 1))
      set_bit(data, grade_index + BLOCK - 1);
    else if (is_set_grade_bit(GET_GRADE(*data, grade_index), BLOCK - 1))
      reset_bit(data, grade_index + BLOCK - 1);

    overflow <<= 1;
  }
}
