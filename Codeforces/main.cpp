#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

inline void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    read(a);

    vector<int> cntl(n+1,1),cntr(n+1,1);
    int mx = 0;
    for(int i = 0; i < n-1; i++) {
        if (a[i + 1] > a[i])cntl[i + 1] += cntl[i];
        mx = max(mx,cntl[i]);
    }
    for(int i = n-1; i > 0; i--){
        if(a[i-1] > a[i]) cntr[i-1] += cntr[i];
        mx = max(mx,cntr[i]);
    }

    mx = max({mx,cntr[0],cntl[n-1]});

    set<int> st;
    for(int i = 0; i < n; i++){
        if(cntl[i] == mx)st.insert(i);
        if(cntr[i] == mx)st.insert(i);
    }

    if(size(st) > 1 || n == 2){
        cout<<"0"<<NL;
        return;
    }

    int cnt = 0;

    for(int i = 1; i < n-1; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            if(cntl[i] == mx && cntr[i] == mx && mx%2)cnt++;
        }

    }

    cout<<cnt<<NL;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
