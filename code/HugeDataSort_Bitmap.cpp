/**
 * 排序不重复的1000W数据
 */
#include <iostream>
#include <bitset>
#include <assert.h>
#include <time.h>
#include <stdio.h>
using namespace std;

const int max_each_scan = 5000000;
const int max_size = 10000000;

int main()
{
    clock_t begin = clock();
    bitset<max_each_scan> bit_map;
    bit_map.reset();

    FILE *fp_unsort_file = fopen("data.txt", "r");
    assert(fp_unsort_file);

    int num;
    while(fscanf(fp_unsort_file, "%d ", &num) != EOF)
    {
        if(num < max_each_scan)
            bit_map.set(num, 1);
    }

    FILE *fp_sort_file = fopen("data_sort.txt", "w");
    assert(fp_sort_file);

    for(num=0; num<max_each_scan; num++)
    {
        if(bit_map[num] == 1)
            fprintf(fp_sort_file, "%d ", num);
    }

    if(!fseek(fp_unsort_file, 0L, SEEK_SET))
    {
        bit_map.reset();
        while(fscanf(fp_unsort_file, "%d ", &num) != EOF)
        {
            if(num >= max_each_scan && num < max_size)
            {
                bit_map.set(num-max_each_scan, 1);
            }
        }

        for(num=0; num<max_each_scan; num++)
        {
            if(bit_map[num] == 1)
                fprintf(fp_sort_file, "%d ", num + max_each_scan);
        }
    }

    clock_t end = clock();
    cout << "Time spend:";
    cout << (end - begin) << "ms" << endl;
    fclose(fp_sort_file);
    fclose(fp_unsort_file);

    return 0;
}
