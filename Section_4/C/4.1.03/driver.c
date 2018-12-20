/*
* TDQC5
* Bruce Cain
*
* 4.1.03
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    /*
     * Data types
     *
     * The integer types have an unsigned version, the defualt is signed. This
     * is all dependant on which ever system being currently used.
     *
     * char is a single byte integer type. Usually used to hold ascii
     * characters but can use to hold numbers from -128 to 127.
     *
     * int a four byte integer type. Range from
     * -2,147,483,648 to 2,147,483,647.
     *
     * short a 2 byte integer type. Range from
     * -32,768 to 32,767.
     *
     * long a 8 byte integer type. Range from
     * -9223372036854775808 to +9223372036854775807
     *
     * float a four byte floating point number, used to hold decimal values.
     * Range 1.2E-38 to 3.4E+38 up to 6 decimal precision.
     *
     * double a eight byte floating point number.
     * Range 2.3E-308 to 1.7E+308 up to 15 decimal precision.
     */
    unsigned int integer = INT_MAX;
    long longer = LONG_MAX;
    char shortest = CHAR_MAX;


    printf("%d\n", integer);
    integer++;
    printf("Overflow int_max + 1 = %d\n", integer);
    printf("%ld\n", longer);
    longer++;
    printf("Overflow long_max + 1 = %ld\n", longer);
    printf("%d\n", shortest);
    shortest++;
    printf("Overflow char_max + 1 = %d\n", shortest);


    float floater = 2.3;
    double doubler = 3.3;
    printf("%f + 3.15 = %f\n", floater, floater + 3.15);
    printf("%f - 3.15 = %f\n", floater, floater - 3.15);
    printf("%lf + 4.6782 = %lf\n", doubler, doubler + 4.6782);
    printf("%lf - 4.6782 = %lf\n", doubler, doubler - 4.6782);
    return 0;
}

