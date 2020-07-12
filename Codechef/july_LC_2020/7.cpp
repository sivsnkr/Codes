#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf int t;scanf("%d", &t);while (t--)
#define test int t;cin >> t;while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
int n,q;
const int MX = 2e5+1;
vector<int> h(MX),te(MX);

void solve()
{
    cin>>n>>q;
    f(i,0,n)cin>>h[i];
    f(i,0,n)cin>>te[i];
    vector<int> mb(n),mbr(n),mbs(n),mbrs(n);
    mb[n-1] = LLONG_MAX;
    mbs[n-1] = LLONG_MAX;
    mbr[0] = LLONG_MIN;
    mbrs[0] = LLONG_MIN;
    stack<int> st;
    f(i,0,n)
    {
        while(!st.empty() && h[st.top()] <= h[i])
        {
            mb[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mb[st.top()] = LLONG_MAX;
        st.pop();
    }

    f(i,0,n)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            mbs[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mbs[st.top()] = LLONG_MAX;
        st.pop();
    }

    fr(i,n-1,0)
    {
        while(!st.empty() && h[st.top()] <= h[i])
        {
            mbr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mbr[st.top()] = LLONG_MIN;
        st.pop();
    }

    fr(i,n-1,0)
    {
        while(!st.empty() && h[st.top()] < h[i])
        {
            mbrs[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        mbrs[st.top()] = LLONG_MIN;
        st.pop();
    }

    vector<int> cf(n,0),cb(n,0);
    f(i,0,n)
    {
        cf[i] = te[i];
        cb[i] = te[i];
    }
    fr(i,n-1,0)
    {
        if(mbs[i] < n)
        {
            cf[i]+=cf[mbs[i]];
        }
    }

    f(i,0,n)
    {
        if(mbrs[i] > -1)
        {
            cb[i]+=cb[mbrs[i]];
        }
    }

    // cout<<"fd"<<NL;
    // for(int i : cf)
    //     cout<<i<<" ";
    // cout<<NL;
    // cout<<"bd"<<NL;
    // for(int i : cb)
    //     cout<<i<<" ";
    // cout<<NL;
    bool updated = false;
    while(q--)
    {
        int qt,a,b;
        cin>>qt>>a>>b;
        a--,b--;
        if(qt == 1)
        {
            te[a] = b+1;
            updated = true;
            // f(i,0,n)
            // {
            //     cf[i] = te[i];
            //     cb[i] = te[i];
            // }
            // fr(i,n-1,0)
            // {
            //     if(mbs[i] < n)
            //     {
            //         cf[i]+=cf[mbs[i]];
            //     }
            // }

            // f(i,0,n)
            // {
            //     if(mbrs[i] > -1)
            //     {
            //         cb[i]+=cb[mbrs[i]];
            //     }
            // }
            
            // cout<<"fd"<<NL;
            // for(int i : cf)
            //     cout<<i<<" ";
            // cout<<NL;
            // cout<<"bd"<<NL;
            // for(int i : cb)
            //     cout<<i<<" ";
            // cout<<NL;
        }
        else
        {
            if(updated)
            {
                f(i,0,n)
                {
                    cf[i] = te[i];
                    cb[i] = te[i];
                }
                fr(i,n-1,0)
                {
                    if(mbs[i] < n)
                    {
                        cf[i]+=cf[mbs[i]];
                    }
                }

                f(i,0,n)
                {
                    if(mbrs[i] > -1)
                    {
                        cb[i]+=cb[mbrs[i]];
                    }
                }
                updated = false;
            }
            if(a > b)
            {
                if(mbr[a] < b)
                {
                    int res = cf[b]-cf[a]+te[a];
                    cout<<res<<NL;
                }
                else
                {
                    cout<<-1<<NL;
                }
            }else
            {
                if(mb[a] > b)
                {
                    int res = cb[b]-cb[a]+te[a];
                    cout<<res<<NL;
                }
                else
                {
                    cout<<-1<<NL;
                }
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    solve();
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}