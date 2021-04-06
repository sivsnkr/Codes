#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
#define size(a) (int)(a).size()

int a[200005], b[200005];
int t, n, i,s;
long long sum;

inline void solve()
{
    cin>>n;
    for (i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    sum=0;
    s=0;
    for (i=0;i<n;i++) {
        if (sum<b[i])
            s=i;
        sum+=b[i];
    }
    cout<<n-s<<NL;
    for(i=0;i<n;i++){
        if(a[i]>=b[s])
            cout<<i+1<<" ";
    }
    cout<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}
