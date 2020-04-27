#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n);
        for(int &b : a)cin>>b;
        ll sum = 0;
        int m = numeric_limits<int>::min();
        int j = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[i] > 0 && a[j] > 0)
            {
                m = max(m,a[j]);
            }
            else if(a[i] < 0 && a[j] < 0)
            {
                m = max(m,a[j]);
            }
            else
            {
                m = max(m,a[j]);
                sum+=m;
                m = numeric_limits<int>::min();
            }
            j++;
        }
        sum+=max(m,a[j]);
        cout<<sum<<nl;
    }
    return 0;
}