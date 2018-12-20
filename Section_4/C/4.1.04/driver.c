/*
* TDQC5
* Bruce Cain
*
* 4.1.04
*/

#include <stdio.h>
#include <stdlib.h>

void increment1d(int *array, int num);
void increment2d(int **array, int row, int col, int num);

int main(void)
{
    /*
     * 1 dimensional array example.
     */
    int *d1_array = calloc(2, sizeof(*d1_array));
    d1_array[0] = 2;
    d1_array[1] = 4;

    increment1d(d1_array, 3);
    puts("1 dimensional array");
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", d1_array[i]);
    }
    puts("");


    /*
     * 2 dimensional array example. In memory it is laid out continuously
     * like a 1 dimensional array. It can still be reference like a 2d
     * array.
     */
    int row = 4;
    int col = 4;
    int **d2_array = calloc(row, sizeof(*d2_array));
    for (int i = 0; i < row; i++)
    {
        d2_array[i] = calloc(col, sizeof(**d2_array));
        for (int j = 0; j < col; j++)
        {
            d2_array[i][j] = j + i;
        }
    }


    increment2d(d2_array, row, col, 3);
    puts("\n2 dimensional array");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", d2_array[i][j]);
        }
        puts("");
    }

    free(d1_array);

    for (int i = 0; i < row; i++)
    {
        free(d2_array[i]);
    }
    free(d2_array);
    return 0;
}

void increment1d(int *array, int num)
{
    int size = sizeof(array)/sizeof(*array);
    for (int i = 0; i < size; i++)
    {
        array[i] += num;
    }
}

void increment2d(int **array, int row, int col, int num)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] += num;
        }
    }
}
