#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]

const int MX = 205;
vector<vector<int>> g(MX);
vector<int> col(MX,-1),col1(MX,-1);

inline void solve()
{
    int n;cin>>n;
    string s;cin>>s;

    for(int i = 0; i < n; i++){
        char c = s[0];
        int in = 0;
        for(int j = 0; j < n-i; j++){
            if(c < s[j]) {
                c = s[j];
                in = j;
            }
        }

        for(int j = in; j < n-i-1; j++){
            if(s[j] > s[j+1]){
                g[j].push_back(j+1);
                g[j+1].push_back(j);
                swap(s[j],s[j+1]);
            }
        }
    }

    bool valid = 1;
    for(int i = 0; i < n; i++){
        if(col[i] == -1) {
            bool valid1 = dfs(i,0);
            bool valid2 = dfs(i,1);

            if(!valid1 && !valid2){
                valid = 0;
                break;
            }
        }
    }

    if(!valid){
        cout<<"NO"<<NL;
        return;
    }

    cout<<"YES"<<NL;
    for(int i = 0; i < n; i++)
        cout<<col[i];
    cout<<NL;
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
