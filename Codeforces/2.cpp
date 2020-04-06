#include <bits/stdc++.h>
using namespace std;

bool can(int size, int sum)
{
    return sum>=0&&sum<=size*9;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    if(n == 0 && m == 1)
        cout<<0<<" "<<0;

    else
    {
        string s="",s1="";
        int i;
        int sum = n;
        for(i = 0; i < m; i++)
        {
            for(int j = 0; j <= 9; j++)
            {
                if(can(m-i-1,sum-j) && !(s.length()==0&&j==0))
                {
                    s+=(char(j)+'0');
                    sum-=j;
                    break;
                }
            }
        }

        sum = n;
        for(i = 0; i < m; i++)
        {
            for(int j = 9; j >= 0; j--)
            {
                if(can(m-i-1,sum-j) && !(s.length()==0&&j==0))
                {
                    s1+=(char(j)+'0');
                    sum-=j;
                    break;
                }
            }
        }
        if(s.length()==0)
            cout<<"-1 -1";
        else
            cout<<s<<" "<<s1;
    }
    cout << "\n";
    return 0;
}