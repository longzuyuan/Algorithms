/******************************************************
 * �����������1�ĸ���
 * ���磬111010��4��1
 *   ���෽����http://blog.csdn.net/justpub/article/details/2292823
 *              http://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html
 *******************************************************/

#include <iostream>
using namespace std;

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


int FactorialMain()
{
    int n = 150;

    ZeroCount1(n);
    ZeroCount2(n);
}
