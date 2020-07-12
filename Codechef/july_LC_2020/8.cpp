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
int n,m;
void solve()
{
    test
    {
        cin>>n>>m;
        vector<int> state(n,-1);
        vector<int> times(n,1);
        vector<map<int,int>> pr(n);
        int ti = -2;
        f(i,0,m)
        {
            int a,b;
            cin>>a>>b;a--,b--;
            int ri;cin>>ri;
            int flag = 0;
            f(i,0,ri)
            {
                flag = 1;
                int pn,nt;cin>>pn>>nt;
                if(state[a] != 0)
                {
                    if(pr[a].find(pn) != pr[a].end())
                    {
                        pr[a][pn] = min(pr[a][pn],nt);
                    }
                    else
                    {
                        ti = 0;
                    } 
                }
                else
                {
                    ti = 0;
                }
                

                if(state[b] != 0)
                {
                    if(pr[b].find(pn) != pr[b].end())
                    {
                        pr[b][pn] = min(pr[b][pn],nt);
                    }
                    else
                    {
                        ti = 0;
                    }
                }
                else
                {
                    ti = 0;
                }
                
            }
            state[a] = state[b] = flag;
            if(flag == 0)
                times[a] = times[b] = 1;
        }
        if(ti == 0)
            cout<<0;
        else if(*min_element(all(state)) == -1)
            cout<<-1;
        else
        {
            int p = 1;
            for(int i : times)
            {
                p*=i;
                p%=mod;
            }
            cout<<p;
        }
        cout<<NL;
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