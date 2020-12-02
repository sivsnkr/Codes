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
    test
    {
        int n;cin>>n;
        vector<int> a(n);
        read(a);
        sort(all(a));
        int mi = 0;
        map<int,int> st,tim,fre;
        f(i,0,n)
        {
            st[a[i]] = i;
            fre[a[i]]++;
        }
        f(i,0,n)
        {
            int mis = LLONG_MAX;
            int mit = 0;
            f(ti,max(mi,(int)1),201)
            {
                int sum = 0;
                // int tim = ti;
                f(j,i,n)
                {
                    sum+=abs(ti+(j-i)-a[j]);
                    // tim;
                }
                // cout<<"sum "<<sum<<NL;
                // cout<<"ti "<<ti<<NL;
                if(mis > sum)
                {
                    mis = sum;
                    mit = ti;
                }
            }
            // cout<<"mis "<<mis<<NL;
            // cout<<"mit "<<mit<<NL;
            mi = mit+fre[a[i]];
            tim[a[i]] = mit;
            i = st[a[i]];
        }
        // for(auto [x,y] : tim)
        // {
        //     cout<<x<<" "<<y<<NL;
        // }
        int res = 0;
        int time = tim[a[0]];
        f(i,0,n)
        {
            while(i < n-1 && a[i] == a[i+1])
            {
                cout<<a[i]<<" "<<time<<NL;
                res+=abs(time-a[i]);
                i++;
                time++;
            }
            cout<<a[i]<<" "<<time<<NL;
            res+=abs(time-a[i]);
            time = tim[a[i+1]];
        }
        // cout<<"res "<<res<<NL;
        // cout<<time<<" "<<a[n-1]<<NL;
        cout<<res<<NL;
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
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}