#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int
int row[9],soln,a,b;

bool place(int r, int c)
{
    f(pc,1,c)
    {
        if(row[pc] == r || abs(row[pc]-r) == abs(pc-c))
            return false;
    }
    return true;
}

void backtrack(int col)
{
    f(tryrow,1,9)
    {
        if(place(tryrow,col))
        {
            row[col] = tryrow;
            if(col == 8 && row[b] == a)
            {
                printf("%2lld      %lld", ++soln, row[1]);
                for (int j = 2; j <= 8; j++) printf(" %lld", row[j]);
                printf("\n");
            }
            else
            {
                backtrack(col+1);
            }
        }
    }
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // all the code goes here
    test
    {
        soln = 0;
        cin>>a>>b;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(1);
        if(t > 0)
            cout<<NL;
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}