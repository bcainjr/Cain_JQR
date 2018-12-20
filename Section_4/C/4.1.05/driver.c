/*
* TDQC5
* Bruce Cain
*
* 4.1.05
*/

#include <stdio.h>

int main(void)
{
    int add = 2;
    puts("Addition");
    printf("1 + 2 = %d\n\n", add + 1);

    char sub = -3;
    puts("Subtraction");
    printf("-3 - 3 = %d\n\n", sub - 3);

    int mul = 8;
    puts("Multiplication");
    printf("8 * 4 = %d\n\n", mul * 4);

    int divv = 10;
    float divvy = 4;
    puts("Division");
    printf("int division\n10 / 3 = %d\n", divv / 3);
    printf("float division\n4 / 7 = %f\n\n", divvy / 7);

    int mod = 13;
    puts("Modulus");
    printf("13 %% 7 = %d\n\n", mod % 7);

    double inc = 3.2;
    puts("Increment");
    printf("3.2++ = %f\n\n", inc++);

    short dec = 55;
    puts("Decrement");
    printf("55-- = %d\n\n", dec--);

    /*
     * PEMDAS
     *
     * Parenthesis
     * Exponents
     * Multiplication
     * Division
     * Add
     * Subtract
     */
    puts("Order of operation");
    printf("2 + (8 * (10 / 4) - (-3)) = %f\n",
            add + (mul * (divv / divvy) - sub));
    return 0;
}

