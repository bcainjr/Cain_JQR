/*
* JQR
* Cain, Bruce
*/

/*
 * p. Endianness
 *
 * Two types, big and little endian. Big endian will place the left most byte
 * into memory first. Little endian will place the right most byte first.
 */


#include <stdio.h>

/*
 * i. Header files
 *
 * Header files usually contain functions that work for a similar task
 * the program has a need for. They can contain any function that is to be
 * included into a program so the programmer can call and use those functions.
 */
#include "header.h"

/*
 * m. C preprocessor
 *
 * The preprocessor is everything to be done by the compiler. The following
 * macro will replace anywhere that MACRO is called with the integer 10.
 */
#define MACRO 10

int extern_value = 10;

/*
 * a. main function
 *
 * The main function is used as the driver of C programs. It's used to invoke
 * other code found in libraries to produce certain outcomes. It can read
 * command line arguments that may be needed through out the program. 
 */
int main(void)
{

    /*
     * d. Data types
     * https://www.tutorialspoint.com/cprogramming/c_data_types.htm
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
    char character = 0;
    short shorter = 0;
    int integer = 0;
    long longer = 0;
    float floating = 0.0;
    double doubly = 0.0;

    if (character == 0 || shorter == 0 || integer == 0 || longer == 0 ||
        floating < 0 || doubly < 0)
    {
        puts("true");
    }
    /*
     * n. Casting
     *
     * Casting is used to change the type of a variable. This will fail when
     * the variables new type cannot hold the information it contains. Others
     * may lose information when being casted into different types. Casting a
     * float into a int will produce a completely different value.
     */
    character = 10;
    printf("%d\n", (int)character);
    /*
     * k. pointers
     *
     * Pointers are used to point to a variable's location in memory. The
     * pointer must be the same type and is initialized with a * after its
     * type. This allows the ability to modify a variable from several
     * locations. Also allows larger structs to be reference withouth creating
     * a whole copy.
     */
    int *integer_pointer = &integer;
    printf("%d\n", *integer_pointer);


    /*
     * l. An array
     *
     * Arrays in C are points to the beginning of the memory location where
     * the first element is located. The following memory addresses are
     * initialized based on user defined size.
     *
     * The following is a character array that can be assigned a literal string
     * and the compiler will designate all the required memory space. A string
     * array is null terminated so the size is +1.
     *
     * Array's elements can be accessed by indexing array[1] or by addition
     * array + 1. Those produce the same results.
     */
    char array[12] = "Hello world";
    for (unsigned int i = 0; i < strlen(array); i++)
    {
        printf("%c", array[i]);
    }

    puts("");

    char array_hash[13] = "Hashing time";
    printf("hash %s, %d\n", array, hash(array));
    printf("hash %s, %d\n", array_hash, hash(array_hash));
    /*
     * g. Scope
     *
     * This is at a given point in a program, what information it can see.
     * The for loop below can see the variables declared in the same function
     * and any globals. I cannont see the new variable created in the inner
     * for loop. 
     *
     * Functions called in other functions cannot see the caller's variables
     * because of the callee's scope.
     */
    for (int i = 0; i < 5; i++)
    {
        int another_int = 0;

        for (int j = 0; j < 5; j++)
        {
            another_int += j + i;
        }

        printf("%d\n", another_int);
    }

    printf("sum 1 + 2 %d\n", add(1, 2));
    printf("sum 1 + 2 %d\n", add(1, 2));

    /*
     * o. Control flow
     *
     * Control flow allows for certain things to happen when a certain
     * condition is met. Usually done with if - else statements.
     */
    int control = 1;
    if (control == 0)
    {
        puts("control is 0");
    }
    else if (control == 1)
    {
        puts("control is 1");
    }
    else
    {
        puts("control is 2");
    }

    /*
     * q. Multi-threading
     * https://www.geeksforgeeks.org/multithreading-c-2/
     * https://www.cs.nmsu.edu/~jcook/Tools/pthreads/library.html
     *
     * Multi-threading allows for multiple actions to take places in
     * parallel. This can help with performance of a program. The example
     * below runs threadder 3 times in parallel using 3 different threads.
     */
    pthread_t tid;
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&tid, NULL, threadder, NULL);
    }

    pthread_exit(NULL);
    /*
     * b. return statement
     * h. return values
     *
     * In this example it is being used as a exit code, which is used by other
     * programs that run this function. Return will take information from a
     * function and give (return) it to whomever called it. 
     */
    return 0;
}

