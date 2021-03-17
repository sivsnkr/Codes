#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>a[poi]

inline void solve()
{
    test{
        int n,q;cin>>n>>q;
        string s,t;cin>>s>>t;
        vector<pair<int,int>> qu(q);
        for(int i = 0; i < q; i++)cin>>qu[i].first>>qu[i].second,qu[i].first--,qu[i].second--;
        reverse(all(qu));

        bool valid = 1;
        for(auto [x,y] : qu){
            int z = 0,o = 0;
            for(int i = x; i <= y; i++){
                if(t[i] == '0')z++;
                else o++;
            }

            if(o == z){
                valid = 0;
                break;
            }

            char ch = o > z ? '1':'0';
            for(int i = x; i <= y; i++){
                t[i] = ch;
            }
//            cout<<x<<" "<<y<<NL;
//            cout<<"t "<<t<<NL;
        }

//        cout<<"t "<<t<<NL;
        if(!valid || s != t)cout<<"NO";
        else cout<<"YES";
        cout<<NL;
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
