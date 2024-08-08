#include "binary.h"

int binary_addition_algorithm(const int256 value_1,
                                  const int256 value_2, int256 *result,
                                  int index) {
  int overflow = 0;

  if (index > 0)
    overflow =
        binary_addition_algorithm(value_1, value_2, result, index - 1);

  int sum = is_set_bit(value_1, index) + is_set_bit(value_2, index) +
            overflow;

  if (sum % 2 != 0) set_bit(result, index);

  return sum > 1 ? 1 : 0;
}

int256 binary_addition(int256 value_1, int256 value_2) {
  int256 result = NEW;

  binary_addition_algorithm(value_1, value_2, &result, FULL_INT256 - 1);

  return result;
}
