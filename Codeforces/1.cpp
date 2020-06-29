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
// int n;
// int a[2][200001];
void solve()
{
    test
    {
        int n;
        cin>>n;
        string a[2];
        cin>>a[0];
        cin>>a[1];
        int i = 0,j = 0;
        bool valid = true;
        bool tr = 0;
        int pr,pc;
        while(true)
        {
            pr = i,pc = j;
            if(a[i][j] == '1' || a[i][j] == '2')
            {
                j++;
                tr = 0;
            }
            else
            {
                if(i == 0)
                {
                    if(!tr)
                        i++;
                    else 
                        j++;
                    tr = 1-tr;
                }
                else
                {
                    if(!tr)
                        i--;
                    else 
                        j++;
                    tr = 1-tr;
                } 
            }
            if(abs(pr-i) == 1)
            {
                // cout<<i<<" "<<j<<NL;
                if(a[i][j] == '1' || a[i][j] == '2')
                {
                    valid = false;
                    break;
                }
            }
            if(i == 1 && j == n)
                break;
            if(i < 0 || j >= n || i >= 2 || j < 0)
            {
                valid = false;
                break;
            }
        }
        if(valid)
            cout<<"YES";
        else
        {
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