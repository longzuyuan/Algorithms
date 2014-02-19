/******************************************************
 * 寻找最小的k 个数
 * 题目描述：查找最小的k 个元素
 * 题目：输入n 个整数，输出其中最小的k 个。
 * 例如输入1，2，3，4，5，6，7 和8 这8 个数字，则最小的4 个数字为1，2，3 和4。
 *******************************************************/

#include <iostream>
#include "util.h"

using namespace std;

/**
 * 排序法 O(n*lg(n))
 */
void FindTopK1(int a[], int n, int k)
{
    Quicksort(a, 0, n-1);
    //for(int i=0; i<n; i++) cout<<a[i]<<" ";
    for(; k>0; k--) cout<<a[k-1]<<" ";
    cout<<endl;
}

/**
 * 数组arr[k]存储法：n*O(k)=O(n*k)
 */
void FindTopK2(int a[], int n, int k)
{
    int tmp[k];
    for(int i=0; i<k; i++)
    {
        tmp[i] = a[i];
    }

    int maxIndex = FindMaxIndex(tmp, k);
    for(int i=k; i<n; i++)
    {
        if(a[i] < tmp[maxIndex])
        {
            tmp[maxIndex] = a[i];
            maxIndex = FindMaxIndex(tmp, k);
        }
    }

    for(int i=0; i<k; i++)
    {
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
}

int TopKMain()
{
    int a[8] = {5, 6, 3, 2, 8, 0, 9, -1};
    int k = 4;
    int n = sizeof(a)/sizeof(int);

    FindTopK2(a, n, k);

    FindTopK1(a, n, k);

    return 1;
}
