#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include "numbr_convertation.h"

void print_number_in_base(int64_t number, int base) {
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (number == 0) {
        printf("0");
        return;
    }

    if (number < 0) {
        printf("-");
        number = -number;
    }

    if (number / base != 0) {
        print_number_in_base(number / base, base);
    }
    printf("%c", digits[number % base]);
}

void print_number_in_architecture(int64_t number, int architecture) {
    if (architecture == 32) {
        printf("x32: ");
        print_number_in_base((uint32_t)number, 2);
        printf("\n");
    } else if (architecture == 64) {
        printf("x64: ");
        print_number_in_base((uint64_t)number, 2);
        printf("\n");
    } else {
        printf("Invalid architecture: %d\n", architecture);
    }
}

void print_number_in_order(int64_t number, int endian) {
    if (endian == BIG_ENDIAN) {
        for (int i = 7; i >= 0; i--) {
            uint8_t byte = (number >> (i * 8)) & 0xFF;
            printf("%02X ", byte);
        }
    } else if (endian == LITTLE_ENDIAN) {
        for (int i = 0; i < 8; i++) {
            uint8_t byte = (number >> (i * 8)) & 0xFF;
            printf("%02X ", byte);
        }
    } else {
        printf("Invalid endianness: %d\n", endian);
    }
}