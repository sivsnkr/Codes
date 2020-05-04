// programe to remove leading zeros from and integer string
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "000045605";
    string res = "0";
    int c = 0;
    while(s[c] == '0')
    {
        c++;
    }

    if(c < s.size())
    {
        res = s.substr(c,s.size()-c);
    }
    cout<<res<<"\n";
}