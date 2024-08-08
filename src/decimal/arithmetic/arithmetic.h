#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "arithmetic_service.h"

int add(decimal_t value_1, decimal_t value_2, decimal_t *result);
int dvv(decimal_t value_1, decimal_t value_2, decimal_t *result);
int mul(decimal_t value_1, decimal_t value_2, decimal_t *result);
int sub(decimal_t value_1, decimal_t value_2, decimal_t *result);

#endif
