#ifndef OTHER_H
#define OTHER_H

#include "arithmetic_service.h"
#include "binary.h"
#include "type.h"

int truncate(decimal_t value, decimal_t *result);
int negate(decimal_t value, decimal_t *result);
int floor_f(decimal_t value, decimal_t *result);
int round_f(decimal_t value, decimal_t *result);

#endif