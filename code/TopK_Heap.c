/*************************************************
 * 寻找最小的K个数
 *
 * 先对元素数组原地建最小堆，O(n)。然后提取K 次，但是每次提取时，
 * 换到顶部的元素只需要下移顶多k 次就足够了，下移次数逐次减少。
 * 此种方法的复杂度为O（n+k^2）。
 *************************************************/

#include <stdio.h>

#define MAXLEN 123456
#define K 100

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

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void HeapAdjust(int a[], int i, int len)
{
    int l = (i<<1) + 1;
    int smallest = i;

    while(l < len)
    {
        if(a[l] < a[smallest]) smallest = l;
        if((l+1)<len && a[l+1] < a[smallest]) smallest = l + 1;

        if(i != smallest) swap(&a[i], &a[smallest]);
        else break;

        l = (smallest<<1) + 1;
        i = smallest;
    }
}

int GetMin(int a[], int len, int k)
{
    int min = a[0];
    swap(&a[0], &a[len-1]);

    int i = 0;
    int l = 1;
    int smallest = i;

    while(l < len && --k > 0)
    {
        if(a[l] < a[smallest]) smallest = l;
        if((l+1)<len && a[l+1] < a[smallest]) smallest = l + 1;

        if(i != smallest) swap(&a[i], &a[smallest]);
        else break;

        l = (smallest<<1) + 1;
        i = smallest;
    }

    return min;
}

void Kmin(int array[], int length, int k)
{
    //原地建堆，O(n)
    int i;
    for(i=length/2-1; i>=0; i--)
    {
        HeapAdjust(array, i, length);
    }
    //printArray(array, length);

    //K次循环取最小值，每次循环交换K次，O(K*K)
    printf("\nTop %d are: ", K);
    int j = length;
    for(i=k; i>0; i--, j--)
    {
        int m = GetMin(array, j, i);
        printf("%d ", m);
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

    Kmin(array, MAXLEN, K);

    return 1;
}
