#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

// Adds two numbers represented as strings and returns a newly allocated string
char* gmp_add(const char* a, const char* b) {
    mpz_t num1, num2, sum;
    mpz_init_set_str(num1, a, 10);
    mpz_init_set_str(num2, b, 10);
    mpz_init(sum);

    mpz_add(sum, num1, num2);

    // Convert result to string
    char* result_str = mpz_get_str(NULL, 10, sum);

    // Clean up
    mpz_clear(num1);
    mpz_clear(num2);
    mpz_clear(sum);

    return result_str; // caller must free() it
}
