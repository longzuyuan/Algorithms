/**
 * 生成随机的不重复的1000W数据
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
using namespace std;

const int max_size = 10000000;
int num[max_size];

int main()
{
     FILE *fp = fopen("data.txt", "w");
     assert(fp);

     for(int i=1; i<=max_size; i++)
     {
         num[i] = i;
     }

     srand((unsigned) time(NULL));
     for(int i=0; i<max_size; i++)
     {
         int a = (rand() + rand()*RAND_MAX) % max_size;
         int b = (rand() + rand()*RAND_MAX) % max_size;
         swap(num[a], num[b]);
     }

     for(int i=0; i<max_size; i++)
     {
         fprintf(fp, "%d ", num[i]);
     }
     fclose(fp);

     return 0;
}
