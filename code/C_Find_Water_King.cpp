/******************************************************
 * 寻找“水王”，即超过半数的数
 *
 * 拓展：有3个数，各个超过1/4
 *******************************************************/

#include <iostream>
using namespace std;

int SwapWK(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int QuicksortPartitionWK(int a[], int l, int h)
{
    int key = a[h];
    int povit = l;
    for(int i=l; i<h; i++)
    {
        if(a[i] <= key)
        {
            SwapWK(a[i], a[povit]);
            povit ++;
        }
    }
    SwapWK(a[povit], a[h]);
    return povit;
}

int QuicksortWK(int a[], int l, int h)
{
    if(l < h)
    {
        int povit = QuicksortPartitionWK(a, l, h);
        QuicksortWK(a, l, povit-1);
        QuicksortWK(a, povit+1, h);
    }
}

/**
 * 排序
 */
int FindWK1(int a[], int n)
{
    QuicksortWK(a, 0, n-1);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<" | Size:"<<n<<endl;
    cout<<"The water king is:"<<a[n/2]<<endl;
}

/**
 * 每次删除两个不同的
 */
int FindWK2(int a[], int n)
{
    int times = 0;
    int candidate;
    for(int i=0; i<n; i++)
    {
        if(times == 0)
        {
            candidate = a[i]; times++;
        }
        else
        {
            if(candidate == a[i]) times++;
            else times--;
        }
    }

    cout<<"The water king is:"<<candidate<<endl;
}

/**
 * 每次删除三个不同的
 */
int FindWK3(int a[], int n)
{
    int times1 = 0, times2 = 0;
    int candidate1 = 0, candidate2 = 0;

    for(int i=0; i<n; i++)
    {
        if(a[i] == candidate1)
        {
            times1 ++;
        }
        else if(a[i] == candidate2)
        {
            times2 ++;
        }
        else if(times1 == 0)
        {
            candidate1 = a[i]; times1 ++;
        }
        else if(times2 == 0)
        {
            candidate2 = a[i]; times2 ++;
        }
        else
        {
            times1 --;
            times2 --;
        }
    }

    cout<<"The water king is:"<<candidate1<<" and "<<candidate2<<endl;
}

/**
 * 每次删除四个不同的
 */
int FindWK4(int a[], int n)
{
    int times[3] = {0};
    int candidate[3] = {0};

    for(int i=0; i<n; i++)
    {
        if(a[i] == candidate[0]) times[0] ++;
        else if(a[i] == candidate[1]) times[1] ++;
        else if(a[i] == candidate[2]) times[2] ++;
        else if(times[0] == 0) {times[0] ++; candidate[0] = a[i];}
        else if(times[1] == 0) {times[1] ++; candidate[1] = a[i];}
        else if(times[2] == 0) {times[2] ++; candidate[2] = a[i];}
        else {times[0] --; times[1] --; times[2] --;}
    }

    cout<<"The water king is:"<<candidate[0]<<" and "<<candidate[1]<<" and "<<candidate[2]<<endl;
}

int FindWKingMain()
{
    int a[] = {7,2,7,2,2,2,7,7,2,7,7,7,2,2,7,7,7,7,2,2,2,2,2,7,2,7,2,7,2,7,7};
    int n = sizeof(a)/sizeof(int);

    FindWK2(a, n);
    FindWK1(a, n);

    int b[] = {2,7,1,7,2,7,2,1,1,1,7};
    n = sizeof(b)/sizeof(int);
    FindWK3(b, n);

    int c[] = {2,7,1,7,2,7,2,1,1,1,7,2,1,5};
    n = sizeof(c)/sizeof(int);
    FindWK4(c, n);

    return 1;
}
