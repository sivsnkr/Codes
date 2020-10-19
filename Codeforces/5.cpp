#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    int n;cin>>n;
    vector<int> a(n);
    read(a);
    vector<int> ones,others;
    vector<pair<int,int>> ans;
    int nxt = n;
    bool valid = 1;
    vector<int> h(n);
    for(int i = n-1; i >= 0; i--)
    {
        int pair = -1;
        if(a[i] == 2)
        {
            if(ones.empty())
            {
                valid = 0;
                break;
            }
            pair = ones.back();
            ones.pop_back();
            others.push_back(i);
        }
        else if(a[i] == 3)
        {
            if(!others.empty())
            {
                pair = others.back();
                others.pop_back();
            }
            else 
            {
                if(ones.empty())
                {
                    valid = 0;
                    break;
                }
                pair = ones.back();
                ones.pop_back();
            }
            others.push_back(i);
        }

        if(a[i] == 1)
        {
            h[i] = nxt--;
            ans.emplace_back(h[i],i+1);
            ones.push_back(i);
        }
        else if(a[i] == 2)
        {
            h[i] = h[pair];
            ans.emplace_back(h[i],i+1);
        }
        else if(a[i] == 3)
        {
            nxt--;
            ans.emplace_back(nxt+1,i+1);
            ans.emplace_back(nxt+1,pair+1);
        }
    }
    if(!valid)
    {
        cout<<-1<<NL;
        return;
    }
    cout<<ans.size()<<NL;
    for(auto [x,y] : ans)
        cout<<x<<" "<<y<<NL;
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
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}