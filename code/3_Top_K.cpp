/******************************************************
 * Ѱ����С��k ����
 * ��Ŀ������������С��k ��Ԫ��
 * ��Ŀ������n �����������������С��k ����
 * ��������1��2��3��4��5��6��7 ��8 ��8 �����֣�����С��4 ������Ϊ1��2��3 ��4��
 *******************************************************/

#include <iostream>
#include "util.h"

using namespace std;

/**
 * ���� O(n*lg(n))
 */
void FindTopK1(int a[], int n, int k)
{
    Quicksort(a, 0, n-1);
    //for(int i=0; i<n; i++) cout<<a[i]<<" ";
    for(; k>0; k--) cout<<a[k-1]<<" ";
    cout<<endl;
}

/**
 * ����arr[k]�洢����n*O(k)=O(n*k)
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
