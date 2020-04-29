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
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,k;
        scanf("%d%d", &n,&k);
        int a[n];
        for(int i = 0; i < n;i++)scanf("%d", &a[i]);
        vector<int> pref(2*k+2,0);
        vector<int> cnt(2*k+1,0);

        for(int i = 0; i < n/2; i++)
        {
            cnt[a[i]+a[n-i-1]]++;
            pref[min(a[i],a[n-i-1])+1]++;
            pref[max(a[i],a[n-i-1])+k+1]--;
        }

        for(int i = 1; i <= 2*k; i++)
            pref[i] += pref[i-1]; 

        int m = 1e9;
        for(int i = 0; i <= 2*k; i++)
            m = min(m,pref[i]-cnt[i]+(n/2-pref[i])*2);
        cout<<m<<nl;
    }

    return 0;
}