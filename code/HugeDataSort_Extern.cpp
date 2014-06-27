/**
 * 排序1000W数据，归并、外排
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "HugeDataSort_Extern.h"


const unsigned int count = 10000000;
const unsigned int number_to_sort = 1000000;
const char *unsort_file = "unsort_data.txt";
const char *sort_file = "sort_data.txt";

void init_data(unsigned int num);

int main()
{
    srand(time(NULL));
    init_data(count);

    ExternSort extSort(unsort_file, sort_file, number_to_sort);
    extSort.sort();

    system("pause");

    return 0;
}

void init_data(unsigned int num)
{
    FILE *fp = fopen(unsort_file, "w");
    for(int i=0; i<num; i++)
    {
        fprintf(fp, "%d ", rand());
    }
    fclose(fp);
}
