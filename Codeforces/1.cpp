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
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void readarray(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

void solve()
{
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    int n,q;cin>>n>>q;
    int err = 0;
    set<int> a1,a2;
    f(i,0,q)
    {
        int a,b;cin>>a>>b;
        b--;
        if(a == 1)
        {
            if(a1.find(b) != a1.end())
            {
                a1.erase(b);
                if(b+1 < n && a2.find(b+1) != a2.end())
                    err--;
                if(b-1 >= 0 && a2.find(b-1) != a2.end())
                    err--;
                if(a2.find(b) != a2.end())
                    err--;
            }
            else
            {
                a1.insert(b);
                if(b+1 < n && a2.find(b+1) != a2.end())
                    err++;
                if(b-1 >= 0 && a2.find(b-1) != a2.end())
                    err++;
                if(a2.find(b) != a2.end())
                    err++;  
            }
            
        }
        else
        {
            if(a2.find(b) != a2.end())
            {
                a2.erase(b);
                if(b+1 < n && a1.find(b+1) != a1.end())
                    err--;
                if(b-1 >= 0 && a1.find(b-1) != a1.end())
                    err--;
                if(a1.find(b) != a1.end())
                    err--;
            }
            else
            {
                a2.insert(b);
                if(b+1 < n && a1.find(b+1) != a1.end())
                    err++;
                if(b-1 >= 0 && a1.find(b-1) != a1.end())
                    err++;
                if(a1.find(b) != a1.end())
                    err++;  
            }
        }
        
        if(err > 0)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}