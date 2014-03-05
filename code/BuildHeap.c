/*************************************************
 * ½¨×îĞ¡¶Ñ
 *************************************************/

#include <stdio.h>

#define N 20

void printArray(int array[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[N];
    int i;
    for(i=N; i>0; i--)
    {
        array[N-i] = i;
    }

    //build heap
    for(int i=N/2-1; i>=0; i--)
    {
        HeapAdjust(array, i, N)
    }

    printArray(array, N);
}
