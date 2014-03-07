/*************************************************
 * 寻找最小的K个数
 *
 * 快速排序
 *************************************************/

#include <stdio.h>

#define CUTOFF 3

#define MAXLEN 11
#define KK 1


void printArray(int array[], int n)
{
    printf("\n");
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/**
 * 取三数中值做为主元
 */
int median3(int a[], int left, int right)
{
    int center = (left + right) / 2;

    if(a[left] > a[center]) swap(&a[left], &a[center]);
    if(a[left] > a[right]) swap(&a[left], &a[right]);
    if(a[center] > a[right]) swap(&a[center], &a[right]);

    swap(&a[center], &a[right-1]);
    return a[right-1];
}

void insertSort(int a[], int left, int right)
{
    int i = left+1;
    for(; i<=right; i++)
    {
        int temp = a[i];
        int j = i-1;
        while(j>=left && a[j]>temp) a[j+1] = a[j--];

        a[j+1] = temp;
    }
}

/**
 * places the Kth smallest element in a[k]
 */
void quickSelect(int a[], int k, int left, int right)
{
    if(right - left >= CUTOFF)
    {
        int pivot = median3(a, left, right);

        int i=left, j=right-1;
        while(1)
        {
            while(a[++i] < pivot);
            while(a[--j] > pivot);
            if(i < j) swap(&a[i], &a[j]);
            else break;
        }
        swap(&a[i], &a[right-1]);

        if(k < i)
        {
            quickSelect(a, k, left, i-1);
        }
        else if(k > i)
        {
            quickSelect(a, k, i+1, right);
        }
    }
    else
    {
        insertSort(a, left, right);
    }
}

int main()
{
    int array[MAXLEN];
    int i;
    for(i=MAXLEN; i>0; i--)
    {
        array[MAXLEN-i] = i;
    }
    printArray(array, MAXLEN);

    quickSelect(array, KK-1, 0, MAXLEN-1);
    //printf("\naa:%d\n", array[MAXLEN]);

    printArray(array, MAXLEN);

    printf("%d", array[KK-1]);

    return 1;
}
