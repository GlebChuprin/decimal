#ifndef COMPARISON_H
#define COMPARISON_H

#include "arithmetic_service.h"
#include "binary.h"
#include "type.h"

int is_equal(decimal_t value_1, decimal_t value_2);
int is_not_equal(decimal_t value_1, decimal_t value_2);
int is_less(decimal_t value_1, decimal_t value_2);
int is_less_or_equal(decimal_t value_1, decimal_t value_2);
int is_greater(decimal_t value_1, decimal_t value_2);
int is_greater_or_equal(decimal_t value_1, decimal_t value_2);

#endif
