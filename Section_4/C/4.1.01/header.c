/*
* TDQC5
* Bruce Cain
*/

#include "header.h"

int add(int a, int b)
{
    /*
     * j. Keywords
     * https://medium.com/@shrmoud/static-vs-extern-a79e36f14812
     *
     * static variable is maintained from the moment it is initialized till
     * the end of a program.
     *
     * extern is used to reference a global variable found in another file.
     */
    static int sum = 0;
    extern int extern_value;
    printf("In add function in header extern_value %d\n", extern_value);
    sum += a + b;
    return sum;
}

int hash(char *hashee)
{
    int hashing = 0;
    for (unsigned int i = 0; i < strlen(hashee); i++)
    {
        hashing += (hashing | hashee[i]);
    }

    return hashing;
}

void *threadder(void *varg)
{
    if (varg == NULL)
    {
        puts("true");
    }

    int *myid = (int *)pthread_self();
    static int counter = 0;
    counter++;

    printf("My id is %d static %d\n", *myid, counter);

    return NULL;
}
