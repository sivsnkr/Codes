#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
#define size(a) (int)(a).size()

inline void solve()
{
    int te = 1;
    test{
        int n,c;cin>>n>>c;
        if(c < n-1 || c > n*(n+1)/2-1){
            cout<<"Case #"<<te<<": "<<"IMPOSSIBLE"<<NL;
            te++;
            continue;
        }

        int cnt = c;
        vector<int> res(n+1,0);
        vector<bool> put(n+1,0);
        vector<pair<int,int>> rev;
        for(int i = 1; i <= n; i++){
            if(put[i])
                continue;
            for(int j = n-i+1; j >= i; j--){
                if(cnt - n+i+1 >= (j-i+1)){
                    rev.emplace_back(i,j);
                    cout<<i<<" "<<j<<NL;
                    res[j] = i;
                    res[i] = j;
                    put[i] = 1,put[j] = 1;
                    cnt -= (j-i+1);
                    break;
                }
            }
        }

        for(auto [x,y] : rev){
            reverse(res.begin()+min(x,y),res.begin()+max(x,y)+1);
            swap(res[x],res[y]);
        }

        cout<<"Case #"<<te<<": ";
        for(int i = 1; i <= n; i++)
            cout<<res[i]<<" \n"[i==n];
        te++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
