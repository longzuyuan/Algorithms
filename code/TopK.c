/*************************************************
 * 寻找最小的K个数
 *
 * 先对元素数组原地建最小堆，O(n)。然后提取K 次，但是每次提取时，
 * 换到顶部的元素只需要下移顶多k 次就足够了，下移次数逐次减少。
 * 此种方法的复杂度为O（n+k^2）。
 *************************************************/

#include <stdio.h>

#define MAXLEN 12345
#define K 100

void HeapAdjust(int array[], int i, int length)
{

}


void Kmin(int array[], int length, int k)
{
    //原地建堆，O(n)


    //K次循环取最小值，每次循环交换K次，O(K*K)

}

int main()
{
    int array[MAXLEN];
    for(int i=MAXLEN; i>0; i--)
    {
        array[MAXLEN-i] = i;
    }

    Kmin(array, MAXLEN, K);

    return 1;
}
