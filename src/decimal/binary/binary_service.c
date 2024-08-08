#include "binary.h"

int compare_int256(int256 value_1, int256 value_2) {
  int result = 0;

  for (int index = FULL_INT256 - 1; !result && index >= 0; index--)
    result = is_set_bit(value_1, index) - is_set_bit(value_2, index);

  return result;
}

int int256_is_not_zero(int256 data) {
  int result = 0;

  for (int block_index = 0; !result && block_index < FULL_INT256;
       block_index += BLOCK)
    result = !!(GET_GRADE(data, block_index));

  return result;
}

int highest_bit(int256 data) {
  int result_index = 0;

  for (int i = FULL_INT256 - 1; !result_index && i >= 0; i--)
    if (is_set_bit(data, i)) result_index = i;

  return result_index;
}
