/******************************************************
 * һ����1��N���������к�1������
 *
 * ����f(N) = N�������N�Ƕ���
 *******************************************************/

#include <iostream>
using namespace std;

long GetOnes(long i)
{
    long c = 0;
    while (i)
    {
        if(i%10 == 1) c++;
        i = i/10;
    }
    return c;
}

/**
 * ������
 */
long GetOnesCount1(long n)
{
    long count = 0;
    for(long i=1; i<=n; i++)
    {
        count += GetOnes(i);
    }

    return count;
}

/**
 * ���ɡ�ͳ��
 */
long GetOnesCount2(long n)
{
    long count = 0;

    int p = 1;
    while(n > p)
    {
        int c = n/p % 10;
        int f = n/(p*10)*p;
        if(c == 1)
        {
            f += n%p + 1;
        }
        else if(c > 1)
        {
            f += p;
        }
        //cout<<c<<" "<<p<<" "<<f<<endl;
        p = p * 10;
        count += f;
    }

    return count;
}

int OnesCountMain()
{
    long n = 1111111110;
    long r = GetOnesCount(n);
    cout<<n<<": "<<r<<endl;

    r = GetOnesCount2(n);
    cout<<n<<": "<<r<<endl;
}
