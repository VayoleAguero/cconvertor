#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>
#include "numbr_convertation.h"
#include "bit_opers.h"


void print_number_in_base(int64_t number, int base);
int64_t and_operation(int64_t num_args, ...);
int64_t or_operation(int64_t num_args, ...);
int64_t xor_operation(int64_t num1, int64_t num2);
int64_t nor_operation(int64_t num1);
void print_number_in_architecture(int64_t number, int architecture);
void print_number_in_order(int64_t number, int endian);

int main(int argc, char **argv) {
    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s [flags] <number1> [<number2>]\n", argv[0]);
        printf("Flags:\n");
        printf("  -s <base1> <base2> ...: Print number in additional bases (up to 32)\n");
        printf("  -a: Print number in 32-bit and 64-bit architectures\n");
        printf("  --help: Display this help message\n");
        printf("  --nor <number>: Perform NOR operation on a single number\n");
        printf("  --and <number1> <number2>: Perform AND operation on two numbers\n");
        printf("  --or <number1> <number2>: Perform OR operation on two numbers\n");
        printf("  --xor <number1> <number2>: Perform XOR operation on two numbers\n");
        printf("  -e <endian>: Print number in specified endianness (big or little)\n");
        return 0;
    }

    int64_t number1 = 0, number2 = 0;
    int nor_flag_processed = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--nor") == 0) {
            if (!nor_flag_processed && i + 1 < argc) {
                number1 = atoll(argv[i + 1]);
                int64_t result = nor_operation(number1);
                printf("%"PRId64" NOR = %"PRId64"\n", number1, result);
                i++;
                nor_flag_processed = 1;
            } else {
                printf("Invalid usage of --nor flag. Provide a number after the flag.\n");
            }
        } else if (strcmp(argv[i], "--and") == 0) {
            if (i + 2 < argc) {
                number1 = atoll(argv[i + 1]);
                number2 = atoll(argv[i + 2]);
                int64_t result = and_operation(2, number1, number2);
                printf("%"PRId64" AND %"PRId64" = %"PRId64"\n", number1, number2, result);
                i += 2;
            } else {
                printf("Invalid usage of --and flag. Provide two numbers.\n");
            }
        } else if (strcmp(argv[i], "--or") == 0) {
            if (i + 2 < argc) {
                number1 = atoll(argv[i + 1]);
                number2 = atoll(argv[i + 2]);
                int64_t result = or_operation(2, number1, number2);
                printf("%"PRId64" OR %"PRId64" = %"PRId64"\n", number1, number2, result);
                i += 2;
            } else {
                printf("Invalid usage of --or flag. Provide two numbers.\n");
            }
        } else if (strcmp(argv[i], "--xor") == 0) {
            if (i + 2 < argc) {
                number1 = atoll(argv[i + 1]);
                number2 = atoll(argv[i + 2]);
                int64_t result = xor_operation(number1, number2);
                printf("%"PRId64" XOR %"PRId64" = %"PRId64"\n", number1, number2, result);
                i += 2;
            } else {
                printf("Invalid usage of --xor flag. Provide two numbers.\n");
            }
        } else if (strcmp(argv[i], "-s") == 0) {
            i++;
            while (i < argc && atoi(argv[i]) > 1 && atoi(argv[i]) <= 32) {
                int base = atoi(argv[i]);
                printf("%dbase: ", base);
                print_number_in_base(number1, base);
                printf("\n");
                i++;
            }
            i--;
        } else if (strcmp(argv[i], "-a") == 0) {
            print_number_in_architecture(number1, 32);
            print_number_in_architecture(number1, 64);
        } else if (strcmp(argv[i], "-e") == 0) {
            i++;
            if (i < argc && (strcmp(argv[i], "big") == 0 || strcmp(argv[i], "little") == 0)) {
                int endian = strcmp(argv[i], "big") == 0 ? BIG_ENDIAN : LITTLE_ENDIAN;
                print_number_in_order(number1, endian);
                printf("\n");
            } else {
                printf("Invalid endianness. Usage: -e big|little\n");
            }
        } else {
            number1 = atoll(argv[i]);
            printf("Value %"PRId64" -\n", number1);
            printf("bin: ");
            print_number_in_base(number1, 2);
            printf("\noctal: ");
            print_number_in_base(number1, 8);
            printf("\nhex: 0x");
            print_number_in_base(number1, 16);
            printf("\n");
        }
    }

    return 0;
}