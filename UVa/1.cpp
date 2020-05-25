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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int row,column;
    while(!cin.eof() && cin>>row>>column)
    {
        vector<vector<pair<int,int>>> mat(row);
        f(i,0,row)
        {
            int n;
            cin>>n;
            f(j,0,n)
            {
                int ro;
                cin>>ro;
                mat[i].push_back({ro-1,0});
            }
            f(j,0,n)
            {
                int value;
                cin>>value;
                mat[i][j].second = value;
            }
        }

        vector<vector<pair<int,int>>> transpose(column);
        f(i,0,row)
        {
            int n = size(mat[i]);
            f(j,0,n)
            {
                transpose[mat[i][j].first].push_back({i+1,mat[i][j].second});
            }
        }

        cout<<column<<" "<<row<<NL;
        f(i,0,column)
        {
            int n = size(transpose[i]);
            if(n > 0)
                cout<<n<<" ";
            else
            {
                cout<<n;
            }
            
            bool in = false;
            f(j,0,n-1)
            {
                cout<<transpose[i][j].first<<" ";
            }
            if(n > 0)
                cout<<transpose[i][n-1].first;
            cout<<NL;
            in = false;
            f(j,0,n-1)
            {
                cout<<transpose[i][j].second<<" ";
            }
            if(n > 0)
                cout<<transpose[i][n-1].second;
            cout<<NL;
        }
        fflush(stdin);
    }
    return 0;
}