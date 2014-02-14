#include <iostream>

using namespace std;

/**
 * ����һλ
 */
void leftshiftone(char* s, int n)
{
    char c = s[0];
    for(int i=1; i<n; i++)
    {
        s[i-1] = s[i];
    }
    s[n-1] = c;
}

/**
 * ����ȫ��
 */
void leftshift(char* s, int n, int len)
{
    //int len = sizeof(s);
    //for(int i=1; i<=n; i++)
    while(n--)
    {
        leftshiftone(s, len);
    }
}

/**
 * ��������
 */
int LeftShiftMain()
{
    char s[7] = "abcdef";
    int len = sizeof(s)-1;
    cout<<s<<" : ";
    leftshift(s, 2, len);
    cout<<s<<endl;

    return 0;
}
