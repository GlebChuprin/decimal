#include "test_help.h"

#ifdef DEBUG

void int256_to_string(int256 data, char *result, int *index) {
  int256 remainder = NEW;

  data = binary_division(data, INT256(10), &remainder);

  if (int256_is_not_zero(data)) int256_to_string(data, result, index);

  result[(*index)++] = remainder.decimals[0].bits[0] + '0';
}

void print_decimal(decimal_t decimal) {
  int256 data = (int256){.decimals[0] = decimal};

  for (int i = FULL_DECIMAL - 1; i >= 0; i--) {
    printf("%d", is_set_bit(data, i));
    if (!(i % 32)) printf(" ");
    if (!(i % (32 * 2))) printf("\n");
  }

  printf("\n");
}

void print_int256(int256 int256) {
  char str_result[256];
  int size = 0;

  int256_to_string(int256, str_result, &size);
  str_result[size] = '\0';
  printf("\n%-33s%s%d\n\n", str_result, "size: ", size);
}

#endif
