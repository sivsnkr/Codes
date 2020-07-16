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

vector<int> trial_division1(int n) {
    vector<int> factorization;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

void solve()
{
    test
    {
        int n;cin>>n;
        vector<int> fa = trial_division1(n);
        if(size(fa) < 3)
            cout<<"NO";
        else
        {
            sort(all(fa));
            set<int> a;
            a.insert(fa[0]);
            int p = 1;
            int i;
            for(i = 1; i < size(fa); i++)
            {
                p*=fa[i];
                if(a.find(p) == a.end())
                {
                    a.insert(p);
                    break;
                }
            }
            p = 1;
            for(i = i+1; i < size(fa); i++)
            {
                p*=fa[i];
            }
            if(p != 1)
                a.insert(p);
            if(size(a) == 3)
            {
                cout<<"YES"<<NL;
                for(int i : a)
                    cout<<i<<" ";
            }
            else
                cout<<"NO";
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