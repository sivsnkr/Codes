#include<bits/stdc++.h>
using namespace std;

string b(int n)
{
    string res = "";
    while(n > 1)
    {
        res+=(char(n%2) + '0');
        n/=2;
    }
    res+=(char(n) + '0');
    int si = res.length();
    for(int i = si; i < 16; i++)
    {
        res+='0';
    }
    // cout<<res.length()<<"\n";
    reverse(res.begin(),res.end());
    // cout<<res<<"\n";
    return res;
}

void rot(string &s, int m)
{
    reverse(s.begin(),s.begin()+m);
    reverse(s.begin()+m,s.end());
    reverse(s.begin(),s.end());
}

int btoi(string s){
    int sum = 0;
    reverse(s.begin(),s.end());
    for(int i = 0; i < 16; i++)
    {
        sum+=(int(s[i])-'0')*pow(2,i);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        char c; cin>>c;

        string s = b(n);
        m%=16;
        if(c == 'L')
            rot(s,m);
        else
        {
            rot(s,16-m);
        }
        int in = btoi(s);
        cout<<in<<"\n";
    }

    return 0;
}