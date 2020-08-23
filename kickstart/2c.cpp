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
// #define int long long int
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

bool valid(vector<int> &res,int a,int b,int n)
{
    int A = 1;
    int mx = res[0];
    f(i,1,n)
    {
        if(res[i] >= mx)
            A++;
        mx = max(mx,res[i]);
    }
    mx = res[n-1];
    int B = 1;
    fr(i,n-2,0)
    {
        if(res[i] >= mx)
            B++;
        mx = max(mx,res[i]);
    }
    if(A != a || B != b)
        return false;
    return true;
}

inline void solve()
{
    // all the code goes here
    int te = 1;
    test
    {
        int n,a,b,c;
        scanf("%d%d%d%d",&n,&a,&b,&c);
        vector<int> res(n,-1);
        f(i,0,a-c)
        {
            res[i] = n-1;
        }
        int i = n-1;
        int co = b-c;
        while(co-- > 0)
        {
            res[i] = n-1;
            i--;
        }
        for(i = 0; i <= c; i++)
        {
            vector<int> resc = res;
            int fi = i;
            f(i,0,n)
                if(resc[i] == -1 && fi-- > 0)
                    resc[i] = n;
            int co = c-i;
            fr(i,n-1,0)
                if(resc[i] == -1 && co-- > 0)
                    resc[i] = n;
            f(i,0,n)
                if(resc[i] == -1)
                    resc[i] = n-2; 
            bool validate = valid(resc,a,b,n);
            if(validate)
            {
                res = resc;
                break;
            }
        }
        if(i == c+1)
            printf("Case #%d: IMPOSSIBLE\n",te);
        else
        {
            printf("Case #%d: ",te);
            f(i,0,n)
                printf("%d ",res[i]);
            printf("\n");
        }
        te++;
    }
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     fh;
    // #endif
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}