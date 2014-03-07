/*************************************************
 * 寻找最小的K个数
 *
 * 堆存储最小K个数
 *************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <assert.h>

using namespace std;


void createDataFile()
{
    ofstream out("data.txt");

    srand((unsigned)time(0));
    for(int i=0; i<100000; i++)
    {
        int v = rand();
        if(v < 100) {i--;continue;}
        out << v << " ";
    }

    out.close();
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void MaxHeap(int heap[], int i, int n)
{
    int largeIndex = i;
    int left = (i*2);

    if(left <= n && heap[left] > heap[largeIndex]) largeIndex = left;
    if(left+1 <= n && heap[left+1] > heap[largeIndex]) largeIndex = left+1;

    if(largeIndex != i)
    {
        swap(&heap[i], &heap[largeIndex]);
        MaxHeap(heap, largeIndex, n);
    }
}

void BuildHeap(int heap[], int n)
{
    if(heap == NULL) return;

    for(int i=n/2; i>0; i--)
    {
        MaxHeap(heap, i, n);
    }
}

int main()
{
    //createDataFile(); return 0;

    int k;
    cout << "Input K: ";
    cin >> k;
    int *heap = new int[k+1];

    FILE *fp = fopen("data.txt", "r");
    assert(fp);

    for(int i=1; i<=k; i++)
    {
        fscanf(fp, "%d ", &heap[i]);
    }

    BuildHeap(heap, k);

    int newData;
    while(fscanf(fp, "%d ", &newData) != EOF)
    {
        if(newData < heap[1])
        {
            heap[1] = newData;
            MaxHeap(heap, 1, k);
        }
    }

    for(int i=1; i<=k; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;

    fclose(fp);

    return 0;
}
