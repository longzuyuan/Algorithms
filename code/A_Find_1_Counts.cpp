/******************************************************
 * 求二进制数中1的个数
 * 比如，111010有4个1
 *   更多方法：http://blog.csdn.net/justpub/article/details/2292823
 *              http://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html
 *******************************************************/

#include <iostream>
using namespace std;

/**
 * 除2法
 */
int Find1Counts1(int n)
{
    int count = 0;
    while (n > 0)
    {
        int i = n % 2;
        if(i == 1) count++;
        n = n/2;
    }
    return count;
}

/**
 * 位移法
 */
int Find1Counts2(int n)
{
    int count = 0;
    while(n)
    {
        count += n & 0x01;
        n = n >> 1;
    }
    return count;
}

/**
 * 位与法
 */
int Find1Counts3(int n)
{
    int count = 0;
    while(n)
    {
        n = n & (n-1);
        count ++;
    }
    return count;
}

int Find1Main()
{
    int n = 121;

    int count = Find1Counts1(n);
    cout<<n<<"'s count:"<<count<<endl;

    count = Find1Counts2(n);
    cout<<n<<"'s count:"<<count<<endl;

    count = Find1Counts3(n);
    cout<<n<<"'s count:"<<count<<endl;

}
