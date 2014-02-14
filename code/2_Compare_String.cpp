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
#include <cstring>

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

/**
 * 3 O��n+m����hashtable �ķ���
 */
bool CheckString3(string s1, string s2)
{
    int hash[26] = {0}; // ����һ���������鲢����
    int counter = 0; // counter Ϊ����������Ԫ�ظ���

    //ɨ���ַ���B
    for(int i=0; i<s2.length(); i++)
    {
        int index = s2[i] - 'A';
        // ������������и�������ӦԪ��Ϊ0������1����counter++;
        if(hash[index] == 0)
        {
            counter ++;
            hash[index] = 1;
        }
    }

    //ɨ���ַ���A
    for(int i=0; i<s1.length(); i++)
    {
        int index = s1[i] - 'A';
        // ������������и�������ӦԪ��Ϊ1����counter--;Ϊ��Ļ�������������д��䣩��
        if(hash[index] == 1)
        {
            hash[index] = 0;
            counter --;
        }
    }

    // Ϊ0 ˵��A�ַ�������B�ַ����������ַ�
    if(counter == 0) return true;
    else return false;
}

/**
 * 4 O��n+m��������洢����
 */
bool CheckString4(string s1, string s2)
{
    char shortStr[s2.length()];
    char longStr[s1.length()];

    strncpy(shortStr, s2.c_str(), s2.length());
    strncpy(longStr, s1.c_str(), s1.length());

    bool store[58];
    memset(store, false, 58);

    for(int i=0; i<sizeof(shortStr); i++)
    {
        int index = shortStr[i] - 65;
        store[index] = true;
    }

    for(int i=0; i<sizeof(longStr); i++)
    {
        int index = longStr[i] - 65;
        if(store[index]) store[index] = false;
    }

    for(int i=0; i<sizeof(store); i++)
    {
        if(store[i]) return false;
    }
    return true;
}

/**
 * 5 O��n����O��n+m������������
 */
bool CheckString5(string s1, string s2)
{
    // ��������
    int primeNumber[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
                        59,61, 67, 71, 73, 79, 83, 89, 97, 101};

    long sum = 1;
    for(int i=0; i<s1.length(); i++)
    {
        sum *= primeNumber[s1[i] - 'A'];
    }

    for(int i=0; i<s2.length(); i++)
    {
        int x = sum % primeNumber[s2[i] - 'A'];
        if(x != 0) return false;
    }

    return true;
}

bool AcontainsB(char* A, char* B)
{
    int have = 0;
    while (*A)
    {
        have |= 1 << (*(A++) - 'A');
    }

    while (*B)
    {
        if((have & (1 << (*(B++) - 'A'))) == 0) return false;
    }
    return true;
}

/**
 * 6 O��n����O��n+m����λ���㷽��
 */
bool CheckString6(string s1, string s2)
{
    char* s3 = &s1[0];
    char* s4 = &s2[0];
    return AcontainsB(s3, s4);
}

int CompareStringMain()
{
    string s3 = "ABCDEFGHLLLLMNOPQRABCDEFGHLLLLMNOPQRS";
    string s4 = "DCGDSRHHQPOMDCGDSRHHQPOM";

    bool b;

    string s1 = s3;
    string s2 = s4;

    b = CheckString1(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    CounterSort(s1);
    CounterSort(s2);
    b = CheckString2(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    s1 = s3; s2 = s4;

    Quicksort(s1, 0, s1.length()-1);
    Quicksort(s2, 0, s2.length()-1);
    b = CheckString2(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    s1 = s3; s2 = s4;

    b = CheckString3(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    b = CheckString4(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    b = CheckString5(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    b = CheckString6(s1, s2);
    cout << "A:" << s1 << " B:" << s2 << " Result:" << b << endl;

    return 0;
}
