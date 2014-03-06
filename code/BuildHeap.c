/*************************************************
 * ½¨×îÐ¡¶Ñ
 *************************************************/

#include <stdio.h>

#define N 10
int count = 0;

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

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void HeapAdjust(int a[], int i, int n)
{
    int l = (i<<1) + 1;
    int r = l + 1;
    int smallest = i;
    while(l < n)
    {
        //printf("%d ", ++count);
        if(a[smallest] > a[l]) smallest = l;
        if(r < n && a[smallest] > a[r]) smallest = r;

        if(i != smallest) swap(&a[i], &a[smallest]);
        else break;

        l = (smallest<<1) + 1;
        r = l + 1;
        i = smallest;
    }
}

void HeapAdjust2(int a[], int i, int n)
{
    int child, temp;
    for(temp=a[i]; 2*i+1<n; i=child)
    {
        child = 2*i + 1;
        if(child<n-1 && a[child+1]<a[child]) child++;

        if(temp > a[child]) a[i] = a[child];
        else break;

        a[child] = temp;
    }
}

int main()
{
    int array[N];
    int i;
    for(i=N; i>0; i--)
    {
        array[N-i] = i;
    }
    printArray(array, N);

    //build heap
    for(i=N/2-1; i>=0; i--)
    {
        HeapAdjust(array, i, N);
    }
    printArray(array, N);
}
