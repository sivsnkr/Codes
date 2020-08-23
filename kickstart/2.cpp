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

inline void solve()
{
    // all the code goes here
    int te = 1;
    test
    {
        int n,a,b,c;
        scanf("%d%d%d%d",&n,&a,&b,&c);
        if(a+b-c > n)
        {
            printf("Case #%d: IMPOSSIBLE\n",te);
        }
        else
        {
            vector<int> res(n,-1);
            int h = n;
            f(i,0,a-c)
            {
                res[i] = h-1;
            }
            int i = n-1;
            int co = b-c;
            while(co-- > 0)
            {
                res[i] = h-1; 
                i--;
            }
            vector<int> resc = res;
            co = c;
            fr(i,n-1,0)
                if(res[i]==-1 && co-- > 0)
                {
                    res[i] = h;
                }
            f(i,0,n)
                if(res[i] == -1)
                    res[i] = h-2;
            // f(i,0,n)
            //     cout<<res[i]<<" \n"[i==n-1];
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
            // cout<<A<<" "<<B<<NL;
            if(A != a || B != b)
            {
                // cout<<"hdfsf"<<NL;
                // printf("Case #%d: IMPOSSIBLE\n",te);
                int co = c;
                f(i,0,n)
                    if(resc[i]==-1 && co-- > 0)
                    {
                        resc[i] = h;
                    }
                f(i,0,n)
                    if(resc[i] == -1)
                        resc[i] = h-2;
                // f(i,0,n)
                //     cout<<res[i]<<" \n"[i==n-1];
                int A = 1;
                int mx = resc[0];
                f(i,1,n)
                {
                    if(resc[i] >= mx)
                        A++;
                    mx = max(mx,resc[i]);
                }
                mx = resc[n-1];
                int B = 1;
                fr(i,n-2,0)
                {
                    if(resc[i] >= mx)
                        B++;
                    mx = max(mx,resc[i]);
                }
                if(A != a || B != b)
                    printf("Case #%d: IMPOSSIBLE\n",te);
                else
                {
                    printf("Case #%d: ",te);
                    f(i,0,n)
                    {
                        if(i == n-1)
                            printf("%d",resc[i]);
                        else
                            printf("%d ",resc[i]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Case #%d: ",te);
                f(i,0,n)
                {
                    if(i == n-1)
                        printf("%d",res[i]);
                    else
                        printf("%d ",res[i]);
                }
                printf("\n");
            }
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