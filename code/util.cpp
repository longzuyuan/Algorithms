#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * 交换元素
 */
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * 快排划分 第一个为主元
 */
int QuicksortPartition(int a[], int low, int high)
{
    int key = a[low];
    int povit = low;
    for(int i=low+1; i<=high; i++)
    {
        if(a[i] <= key)
        {
            povit ++;
            Swap(a[i], a[povit]);
        }
    }
    Swap(a[povit], a[low]);
    return povit;
}

/**
 * 快排划分 最后一个为主元
 */
int QuicksortPartitionEnd(int a[], int low, int high)
{
    int key = a[high];
    int povit = high;
    for(int i=high-1; i>=low; i--)
    {
        if(a[i] >= key)
        {
            povit --;
            Swap(a[i], a[povit]);
        }
    }
    Swap(a[high], a[povit]);
    return povit;
}

/**
 * 快排划分 随机一个为主元
 */
int QuicksortPartitionRandom(int a[], int low, int high)
{
    srand((unsigned)time(0));
    int rand_num = rand() % (high-low) + low;
    Swap(a[rand_num], a[low]);

    return QuicksortPartition(a, low, high);
}

/**
 * 快排
 */
void Quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int povit = QuicksortPartitionRandom(a, low, high);
        Quicksort(a, low, povit-1);
        Quicksort(a, povit+1, high);
    }
}

/**
 * 快排划分
 */
int QuicksortPartitionChar(string &s, int start, int end)
{
    int key = s[start]; //选取第一个为主元
    int pivot = start;
    for(int i=start+1; i<=end; i++)
    {
        if(s[i] <= key)
        {
            pivot ++;
            swap(s[i], s[pivot]);
        }
    }
    swap(s[start], s[pivot]);
    return pivot;
}

/**
 * 快排
 */
void QuicksortChar(string &s, int start, int end)
{
    if(start < end)
    {
        int pivot = QuicksortPartitionChar(s, start, end);
        QuicksortChar(s, start, pivot-1);
        QuicksortChar(s, pivot+1, end);
    }
}

/**
 * 查找数组中最大值的索引
 */
int FindMaxIndex(int a[], int n)
{
    if(n <= 0) return -1;
    int max = a[0];
    int index = 0;
    for(int i=1; i<n; i++)
    {
        if(a[i] > max)
        {
            index = i;
            max = a[i];
        }
    }
    return index;
}
