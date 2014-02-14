/******************************************************
 * ��������һ��������ĸ��ɵ��ַ���A��������һ���ַ���B���ַ�����B
 * ����ĸ�������һЩ��ʲô���������Ĳ������С�ַ���B �����ĸ�ڴ��ַ�
 * ��A �ﶼ�У�
 * ���磬��������������ַ�����
 *   String 1: ABCDEFGHLMNOPQRS
 *   String 2: DCGSRQPO
 * ����true��������string2 �����ĸstring1 Ҳ���С�
 * ��������������ַ�����
 *   String 1: ABCDEFGHLMNOPQRS
 *   String 2: DCGSRQPZ
 * ����false����Ϊ�ڶ����ַ������Z ��ĸ���ڵ�һ���ַ����
 *******************************************************/

#include <iostream>
#include <string>

using namespace std;

/**
 * 1 ��ٷ����������� O��n*m������ѯ����
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
 * ���Ż���
 */
int QuicksortPartition(string &s, int start, int end)
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
 * ��������
 */
void CounterSort(string &s)
{
    int counter[26] = {0};
    string s2 = s;

    // ����˵���i + 'A'��Ԫ�ظ���
    for(int i=0; i<s.length(); i++)
    {
        counter[s[i]-'A'] ++;
    }

    // ���ÿ��Ԫ�ض�Ӧ������λ��
    for(int i=1; i<26; i++)
    {
        counter[i] += counter[i-1];
    }

    // ��ÿ��Ԫ�طŵ����Ӧ������λ��
    for(int i=s.length()-1; i>=0; i--)
    {
        int index = s[i]-'A';
        s2[counter[index]-1] = s[i];
        counter[index] --;
    }
    s = s2;
}

/**
 * 2 O(mlogm)+O(nlogn)+O(m+n)������
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
