#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>

int64_t and_operation(int64_t num_args, ...) {
    int64_t result = -1;
    va_list args;
    va_start(args, num_args);

    for (int i = 0; i < num_args; i++) {
        int64_t arg = va_arg(args, int64_t);
        result &= arg;
    }

    va_end(args);
    return result;
}

int64_t or_operation(int64_t num_args, ...) {
    int64_t result = 0;
    va_list args;
    va_start(args, num_args);

    for (int i = 0; i < num_args; i++) {
        int64_t arg = va_arg(args, int64_t);
        result |= arg;
    }

    va_end(args);
    return result;
}

int64_t xor_operation(int64_t num1, int64_t num2) {
    return num1 ^ num2;
}

int64_t nor_operation(int64_t num1) {
    return ~num1;
}