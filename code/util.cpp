#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * ����Ԫ��
 */
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * ���Ż��� ��һ��Ϊ��Ԫ
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
 * ���Ż��� ���һ��Ϊ��Ԫ
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
 * ���Ż��� ���һ��Ϊ��Ԫ
 */
int QuicksortPartitionRandom(int a[], int low, int high)
{
    srand((unsigned)time(0));
    int rand_num = rand() % (high-low) + low;
    Swap(a[rand_num], a[low]);

    return QuicksortPartition(a, low, high);
}

/**
 * ����
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
 * ���Ż���
 */
int QuicksortPartitionChar(string &s, int start, int end)
{
    int key = s[start]; //ѡȡ��һ��Ϊ��Ԫ
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
 * ����
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
 * �������������ֵ������
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
