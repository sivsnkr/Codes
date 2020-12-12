#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
void read(vector<int> &a);

inline void solve()
{
    // all the code goes here
    int n,d,m;cin>>n>>d>>m;

    vector<int> in,de;

    f(i,0,n)
    {
        int x;cin>>x;
        if(x > m)
            in.push_back(x);
        else    
            de.push_back(x);
    }

    sort(all(in)),sort(all(de),greater<int>());
    int i = 0,j = 0;
    int sum = 0;
    while(i < in.size() && j < de.size())
    {
        int tsum = 0;
        if(j+d <= de.size())
        {
            f(k,j,j+d)
                tsum+=de[k];
        }
        
        if(j+d-1 >= de.size())
        {
            f(k,j,de.size())
            {
                tsum+=de[k];
                // in.push_back(de[k]);
            }
            if(in.size()-i == 1)
            {
                sum+=tsum;
                j = de.size();
                break;
            }
            if(tsum >= in[i])
            {
                sum+=tsum;
            }
            else
            {
                f(k,j,de.size())
                {
                    in.push_back(de[k]);
                }
            }
            
            j = de.size();
            break;
        }
        sum+=max(tsum,in[i]);
        i++,j+=d;
    }
    sort(in.begin()+i,in.end());

    while(j < de.size())
        sum+=de[j++];
    if(i < in.size())
    {
        int st = i,en = in.size()-1;
        while(st <= en)
        {
            sum+=in[en];
            en--,st+=d;
        }
    }

    cout<<sum<<NL;
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