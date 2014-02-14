/******************************************************
 * 假设这有一个各种字母组成的字符串A，和另外一个字符串B，字符串里B
 * 的字母数相对少一些。什么方法能最快的查出所有小字符串B 里的字母在大字符
 * 串A 里都有？
 * 比如，如果是下面两个字符串：
 *   String 1: ABCDEFGHLMNOPQRS
 *   String 2: DCGSRQPO
 * 答案是true，所有在string2 里的字母string1 也都有。
 * 如果是下面两个字符串：
 *   String 1: ABCDEFGHLMNOPQRS
 *   String 2: DCGSRQPZ
 * 答案是false，因为第二个字符串里的Z 字母不在第一个字符串里。
 *******************************************************/

#include <iostream>
#include <string>

using namespace std;

/**
 * 1 穷举法，暴力法， O（n*m）的轮询方法
 */
bool CheckString1(string s1, string s2)
{
    for(unsigned int i=0; i<s2.length(); i++)
    {
        unsigned int j=0;
        for(; j<s1.length(); j++)
        {
            if(s2[i] == s1[j]) break;
        }
        if(j==s1.length()) return false;
    }
    return true;
}

/**
 * 快排划分
 */
int QuicksortPartition(string &s, int start, int end)
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
void Quicksort(string &s, int start, int end)
{
    if(start < end)
    {
        int pivot = QuicksortPartition(s, start, end);
        Quicksort(s, start, pivot-1);
        Quicksort(s, pivot+1, end);
    }
}

/**
 * 计数排序
 */
void CounterSort(string &s)
{
    int counter[26] = {0};
    string s2 = s;

    // 存放了等于i + 'A'的元素个数
    for(int i=0; i<s.length(); i++)
    {
        counter[s[i]-'A'] ++;
    }

    // 求出每个元素对应的最终位置
    for(int i=1; i<26; i++)
    {
        counter[i] += counter[i-1];
    }

    // 把每个元素放到其对应的最终位置
    for(int i=s.length()-1; i>=0; i--)
    {
        int index = s[i]-'A';
        s2[counter[index]-1] = s[i];
        counter[index] --;
    }
    s = s2;
}

/**
 * 2 O(mlogm)+O(nlogn)+O(m+n)的排序法
 */
bool CheckString2(string s1, string s2)
{
    int i=0, j=0;
    while (i<s1.length() && j<s2.length())
    {
        if(s2[j] != s1[i]) i++;
        else j++;
    }

    if(j < s2.length()) return false;
    else return true;
}

int CompareStringMain()
{
    string s1 = "ABCDEFGHLLLLMNOPQRABCDEFGHLLLLMNOPQRS";
    string s2 = "DCGDSRHHQPOMDCGDSRHHQPOM";

    bool b;

    b = CheckString1(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    CounterSort(s1);
    CounterSort(s2);
    b = CheckString2(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    s1 = "ABCDEFGHLLLLMNOPQRABCDEFGHLLLLMNOPQRS";
    s2 = "DCGDSRHHQPOMDCGDSRHHQPOM";

    Quicksort(s1, 0, s1.length()-1);
    Quicksort(s2, 0, s2.length()-1);
    b = CheckString2(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    return 0;
}
