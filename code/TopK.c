/*************************************************
 * Ѱ����С��K����
 *
 * �ȶ�Ԫ������ԭ�ؽ���С�ѣ�O(n)��Ȼ����ȡK �Σ�����ÿ����ȡʱ��
 * ����������Ԫ��ֻ��Ҫ���ƶ���k �ξ��㹻�ˣ����ƴ�����μ��١�
 * ���ַ����ĸ��Ӷ�ΪO��n+k^2����
 *************************************************/

#include <stdio.h>

#define MAXLEN 12345
#define K 100

void HeapAdjust(int array[], int i, int length)
{

}


void Kmin(int array[], int length, int k)
{
    //ԭ�ؽ��ѣ�O(n)


    //K��ѭ��ȡ��Сֵ��ÿ��ѭ������K�Σ�O(K*K)

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
