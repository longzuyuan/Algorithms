/*************************************************
 * Ѱ����С��K����
 *
 * �ȶ�Ԫ������ԭ�ؽ���С�ѣ�O(n)��Ȼ����ȡK �Σ�����ÿ����ȡʱ��
 * ����������Ԫ��ֻ��Ҫ���ƶ���k �ξ��㹻�ˣ����ƴ�����μ��١�
 * ���ַ����ĸ��Ӷ�ΪO��n+k^2����
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
    //ԭ�ؽ��ѣ�O(n)
    int i;
    for(i=length/2-1; i>=0; i--)
    {
        HeapAdjust(array, i, length);
    }
    //printArray(array, length);

    //K��ѭ��ȡ��Сֵ��ÿ��ѭ������K�Σ�O(K*K)
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
