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
vector<vector<int>> arr;
int n,m;

void max_self(int &a, int i, int j)
{
    if(i >= n || i < 0 || j >= m || j < 0)
        return;
    a = max(a,arr[i][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test
    {
        cin>>n>>m;
        arr.assign(n,vector<int>(m));
        f(i,0,n)
            f(j,0,m)
                cin>>arr[i][j];
        f(i,0,n)
        {
            string res = "";
            f(j,0,m)
            {
                int v = arr[i][j];
                max_self(arr[i][j],i-1,j-1);
                max_self(arr[i][j],i-1,j);
                max_self(arr[i][j],i-1,j+1);
                if(v == arr[i][j])
                    res+='1';
                else
                {
                    res+='0';
                } 
            }
            cout<<res<<NL;
        }
    }
    return 0;
}