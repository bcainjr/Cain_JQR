/*
 * c. Macro guards
 *
 * Prevents the possibility of loading the same header file more than once.
 */
#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>
#include <pthread.h>


/*
 * e. A function
 *
 * Functions are used to make code modular. They are also used to help prevent
 * code repeatability. Also try to keep them doing only one thing, if
 * multiple things are done then its likely to split it into multiple
 * functions.
 *
 * f. Parameters
 *
 * These are used in functions, the function use's the information to
 * do what ever the function does. Then returns a result.
 */
int add(int a, int b);

/*
 * r. Hashing
 *
 * Hashing is taking a input and doing some operation on it to produce some
 * unique output. The idea in security is to have the output be unique and the
 * same size no matter what you put into the hashing function. For data
 * structures like a hash table, the hash doesn't have to be that complex but
 * less collisions is better.
 */
int hash(char *hashee);

void *threadder(void *varg);

#endif
