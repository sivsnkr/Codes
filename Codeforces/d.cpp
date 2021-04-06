#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]


string remove_leading_zeros(string s)
{
    string res = "0";
    int c = 0;
    while(s[c] == '0')
    {
        c++;
    }

    if(c < s.size())
    {
        res = s.substr(c,s.size()-c);
    }
    return res;
}

#define size(a) (int)(a).size()
string min_e(string a,string b){
    if(a.length() > b.length())
        return b;
    if(b.length() > a.length())
        return a;

    return min(a,b);
}

inline void solve()
{
    string s;cin>>s;
    s = remove_leading_zeros(s);
    int n = s.length();
    string res = string(n,'1');
    if(s == res){
        cout<<0<<NL;
        return;
    }

    if(s == string(n,'0')){
        cout<<1<<NL;
        return;
    }

    vector<pair<int,int>> cnts(n+1);
    vector<pair<int,int>> jump(n+1);
    int zj = n,oj = n;
    cnts[n] = {0,0};
    int o = 0,z = 0;
    for(int i = n-1; i >= 0; i--){
        jump[i] = {zj,oj};
        if(s[i] == '0')
            z++,zj = i;
        else
            o++,oj = i;
        cnts[i] = {z,o};
    }

    int in = -1;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) {
            string te = to_string(i) + to_string(j);
            int it;
            for (it = n - 1; it >= 0; it--) {
                if (s[it] == te[0]) {
                    if (te[1] == '0' && cnts[it + 1].first == 0)
                        in = it;
                    else if (te[1] == '1' && cnts[it + 1].second == 0)
                        in = it;
                }
            }

            int i = 0;
            string st = "";
            while(i < in){
                st += s[i];
                if(jump[i].first > in)
                    i = jump[i].second;
                else if(jump[i].second > in)
                    i = jump[i].first;
                else
                    i = max(jump[i].first,jump[i].second);
            }

            res = min_e(res,st+te);
        }
    }

    cout<<res<<NL;
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
