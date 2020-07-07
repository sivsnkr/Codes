#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf        \
    int t;           \
    scanf("%d", &t); \
    while (t--)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int

map<int,int> a,b;
vector<int> va,vb;
vector<int> vall;
int n;
void solve()
{
    test
    {
        cin>>n;
        a.clear(),b.clear();
        va.clear(),vb.clear();
        vall.clear();
        f(i,0,n)
        {
            int t;
            cin>>t;
            va.push_back(t);
            vall.push_back(t);
            a[t]++;
        }
        f(i,0,n)
        {
            int t;
            cin>>t;
            vb.push_back(t);
            vall.push_back(t);
            b[t]++;
        }

        sort(all(vb));
        sort(all(va));
        sort(all(vall));
        if(va == vb)
        {
            cout<<0<<NL;
        }
        else
        {
            bool valid = 1;
            for(int i : vall)
            {
                if((a[i]+b[i])%2 != 0)
                {
                    valid = false;
                    break;
                }
            }
            if(!valid)
            {
                cout<<-1<<NL;
            }
            else
            {
                int cost = 0;
                int end = n-1;
                f(i,0,n)
                {
                    if(a[va[i]] > b[va[i]])
                    {
                        while(end > 0 && a[vb[end]] >= b[vb[end]])
                        {
                            end--;
                        }
                        // cout<<va[i]<<" "<<vb[end]<<NL;
                        cost+=min({va[i],vb[end],2*min(va[0],vb[0])});
                        a[vb[end]]++;
                        b[vb[end]]--;
                        a[va[i]]--;
                        b[va[i]]++;
                        end--;
                    }
                }
                end = n-1;
                f(i,0,n)
                {
                    if(b[vb[i]] > a[vb[i]])
                    {
                        while(end > 0 && b[va[end]] >= a[va[end]])
                        {
                            end--;
                        }
                        cost+=min({vb[i],va[end],2*min(va[0],vb[0])});
                        a[va[end]]--;
                        b[va[end]]++;
                        a[vb[i]]++;
                        b[vb[i]]--;
                        end--;
                    }
                }
                cout<<cost<<NL;
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