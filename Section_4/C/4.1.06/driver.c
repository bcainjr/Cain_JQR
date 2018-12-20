/*
* TDQC5
* Bruce Cain
*
* 4.1.06
*/

#include <stdio.h>

/*
 * argc is the number of cli arguments. There is atleast 1, the program itself.
 *
 * argv contains all the arguments passed on the cli as 2D array.
 */
int main(int argc, char **argv)
{
    printf("argc %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}

