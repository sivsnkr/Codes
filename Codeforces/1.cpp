#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;cin>>n>>k;
    int con[n+1];
    iota(con,con+n+1,0);

    for(int i = 0; i < n; i++)
    {
        int c;cin>>c;
        vector<int> te(c);
        for(int j = 0; j < c; j++)
        {
            cin>>te[i];
        }
        for(int j = 0; j < c; j++)
        {
            con[te[j]] = con[te[j+1]];
        }
    }
    return 0;
}