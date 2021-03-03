#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

inline void solve()
{
    // let's code
    test{
        int x,y;cin>>x>>y;
        int b = 1;
        for(int i = y; i >= 2; i--){
            if(i*i-1 <= x){
                b = i;
                break;
            }
        }

//        int n_terms = b-2+1;
        cout<<"b "<<b<<NL;
        int n_terms_a = min(x-1,y);
//        cout<<"n_terms "<<n_terms_a<<NL;
        LL res = (LL)b*(b-1)/2;
        int val = n_terms_a;
        int pval = val,cnt = 2;
        while(val > b){
            val = (n_terms_a-cnt)/cnt;
            if(val < b)
                res += abs(pval - max(val,b+1)+1) * (cnt - 1);
            else
                res += abs(pval - val) * (cnt - 1);
//            cout<<"val cnt "<<val<<" "<<cnt<<NL;
            pval = val;
            cnt++;
        }
//        res += abs(pval-b)*(cnt-1);
        cout<<res<<NL;
    }
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
