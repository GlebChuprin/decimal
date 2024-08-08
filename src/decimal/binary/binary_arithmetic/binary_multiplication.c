#include "binary.h"

int256 binary_multiplication(int256 value_1, int256 value_2) {
  int256 result = NEW;

  int size = highest_bit(value_2);

  for (int i = 0; i <= size; i++)
    if (is_set_bit(value_2, i))
      result = binary_addition(result, shift_left(value_1, i));

  return result;
}

int256 mul10(int256 data) {
  return binary_addition(shift_left(data, 1), shift_left(data, 3));
}
