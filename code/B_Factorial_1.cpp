/******************************************************
 * 1��N! ĩβ�ж��ٸ�0
 * 2��N! ��������ĩһ��1����
 *
 * N! �������ֽ� = 2^X + 3^Y + 5^Z + ...
 *******************************************************/

#include <iostream>
using namespace std;

/**
 * 5��ָ����
 */
void ZeroCount1(int n)
{
    int count = 0;

    for(int i=1; i<=n; i++)
    {
        int j = i;
        while(j % 5 == 0)
        {
            count ++;
            j = j/5;
        }
    }

    cout<<n<<"'s count:"<<count<<endl;
}

/**
 * ��ʽ����[N/5] + [N/5^2] + [N/5^3] + ...
 */
void ZeroCount2(int n)
{
    int count = 0;

    int i = 5;
    while(i <= n)
    {
        count += n/i;
        i *= 5;
    }

    cout<<n<<"'s count:"<<count<<endl;
}

/**
 * ��ʽ����[N/2] + [N/2^2] + [N/2^3] + ...
 */
void LowestOne1(int n)
{
    int pos = 0;

    while(n)
    {
        n >>= 1;
        pos += n;
    }

    cout<<"lowest 1 position:"<<pos<<endl;
}

/**
 * ��ʽ����N - [N�Ķ������к�1������]
 */
void LowestOne2(int n)
{
    int pos = n;

    int c = 0;
    while(n)
    {
        n = n & (n-1);
        c++;
    }
    pos -= c;

    cout<<"lowest 1 position:"<<pos<<endl;
}

int FactorialMain()
{
    int n = 100;

    ZeroCount1(n);
    ZeroCount2(n);

    LowestOne1(n);
    LowestOne2(n);
}
