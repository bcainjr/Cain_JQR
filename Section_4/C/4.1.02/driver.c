/*
* TDQC5
* Bruce Cain
*
* 4.1.02
*/

#include <stdio.h>
#include <stdlib.h>



/* 
 * https://www.geeksforgeeks.org/memory-layout-of-c-program/
 *
 * ---------------
 * |CLI args &   |
 * |environment  |
 * |variables    |
 * |-------------|
 * |   stack     |
 * |     |       |
 * |     v       |
 * |             |
 * |     ^       |
 * |     |       |
 * |   heap      |
 * |-------------| 
 * | unitialized |
 * | data        |
 * |-------------|
 * | initialized |
 * | data        |
 * |-------------|
 * | text        |
 * ---------------
 */

int global_var = 10;

int main(void)
{
    static int static_var = 11;
    int uninitialized;
    int initialized = 10;
    int *heap_var = calloc(1, sizeof(*heap_var));

    printf("global        %p\n", (void *)&global_var);
    printf("static        %p\n", (void *)&static_var);
    printf("uninitialized %p\n", (void *)&uninitialized);
    printf("initialized   %p\n", (void *)&initialized);
    printf("heap          %p\n", (void *)heap_var);

    free(heap_var);
    return 0;
}
