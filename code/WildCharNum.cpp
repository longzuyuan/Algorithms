#include <iostream>
#include <string>

using namespace std;

int counter = 0;

int compare(string s1,string s2)
{
   if (s1 > s2) return 1;
   else return 0;
}

void helper(string s1,string s2,int k)
{
    int len = s1.length();
    int i;
    if('?' == s1[k])
        for(i=0; i<=9; i++)
        {
            s1[k] = i + '0';
            if(compare(s1, s2))
            {
                if(k == len-1) counter += 1;
                else helper(s1, s2, k+1);
            }
        }
    else
    {
        if(compare(s1, s2))
        {
            if(len-1 == k)
                counter += 1;
            else
                helper(s1, s2, k+1);
        }
        else
            counter = 0;
    }
}

int main()
{
    string s1, s2;

    cin>>s1>>s2;
    helper(s1, s2, 0);
    cout<<counter<<endl;

    return 0;
}

