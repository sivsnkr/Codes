#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
template<typename T>
#define int long long
void read(vector<T> &a);

inline void solve()
{
    // let's code
    test
    {
        int n;cin>>n;
        vector<int> a(n);
        read(a);

        vector<multiset<int>> el(25);
        vector<bool> vis(n,0);
        for(int i = 24; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[j] && ((1LL<<i)&a[j]) != 0)
                {
                    el[i].insert(a[j]);
                    vis[j] = 1;
                }
            }
        }

        int kscore = 0,koscore = 0;
        bool turn = 1;

        for(int i = 0; i < n; i++)
        {
            int mxval = -1,score = turn?kscore:koscore;
            for(int j = 24; j >= 0; j--)
            {
                if(!el[j].empty() && ((1LL<<j)&score) == 0)
                {
                    mxval = *el[j].begin();
                    el[j].erase(el[j].begin());
                    break;
                }
            }
            if(mxval < 0)
            {
                 for(int j = 0; j < 25; j++)
                {
                    if(!el[j].empty() && ((1LL<<j)&score) != 0)
                    {
                        mxval = *el[j].begin();
                        el[j].erase(el[j].begin());
                        break;
                    }
                }
            }
            if(mxval > 0)
                score = score^mxval;
            // cout<<"mxval "<<mxval<<NL;
            // cout<<"turn "<<turn<<NL;
            // cout<<"score "<<score<<NL;
            if(turn)
                kscore = score;
            else 
                koscore = score;
            turn = !turn;
        }
        // cout<<kscore<<" "<<koscore<<NL;

        if(kscore == koscore)
            cout<<"DRAW";
        else if(kscore > koscore)
            cout<<"WIN";
        else
            cout<<"LOSE";
        cout<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}
