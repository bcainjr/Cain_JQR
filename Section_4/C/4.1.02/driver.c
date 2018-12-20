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
 * High memory address
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
 * Low memory address
 *
 *  Global and static variables sit in the data area, the dynamically allocated
 *  variables sit in the heap. The other variables sit in the stack. 
 *  The executable code is in the text area along with string literals.
 */

/*
 * Found in data
 */
int global_var = 10;

struct tester 
{
    int testing;
};

int main(void)
{
    /*
     * Found in data
     */
    static int static_var = 11;

    /*
     * Found on the stack
     */
    int uninitialized;
    int initialized = 10;
    struct tester test_struct;

    /*
     * Found on the head
     */
    int *heap_var = calloc(1, sizeof(*heap_var));

    /*
     * Found in text
     */
    char const *string = "hello";

    printf("uninitialized %p\n", (void *)&uninitialized);
    printf("initialized   %p\n", (void *)&initialized);
    printf("struct        %p\n", (void *)&test_struct);
    printf("heap          %p\n", (void *)heap_var);
    printf("static        %p\n", (void *)&static_var);
    printf("global        %p\n", (void *)&global_var);
    printf("const string  %p\n", (void *)string);

    free(heap_var);
    return 0;
}
