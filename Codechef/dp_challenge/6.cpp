#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
vector<vector<bool>> dp;
int n,m;

void make_dirty(int i, int j)
{
    if(i >= n || i < 0 || j >= m || j < 0)
        return;
    dp[i][j] = 1;
    make_dirty(i+1,j);
    make_dirty(i+1,j-1);
    make_dirty(i+1,j+1);
    return;
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
        // vector<vector<int>> arr(n,vector<int>(m));
        // f(i,0,n)
        //     f(j,0,m)
        //         cin>>arr[i][j];
        int x;
        map<int,pair<int,int>> st;
        f(i,0,n)
            f(j,0,m)
            {
                cin>>x;
                st[x] = make_pair(i,j);
            }
        // f(i,0,n)
        //     f(j,0,m)
        //         st[arr[i][j]] = {i,j};
        // vector<vector<bool>> dp(n,vector<bool>(m,0));
        dp.assign(n,vector<bool>(m,1));
        // f(i,0,m)
        //     dp[0][i] = 0;

        // f(i,1,n)
        //     f(j,0,m)
        //     {
        //         bool dirty = false;
        //         if(j > 0)
        //         {
        //             if(arr[i-1][j-1] > arr[i][j])
        //                 dirty = true;
        //         }
        //         if(arr[i-1][j] > arr[i][j])
        //             dirty = true;
        //         if(j+1 < m)
        //             if(arr[i-1][j+1] > arr[i][j])
        //                 dirty = true;
        //         dp[i][j] = dirty;
        //     }
        for(auto it : st)
        {
            int i = it.second.first;
            int j = it.second.second;
            dp[i][j] = 0;
            make_dirty(i+1,j);
            make_dirty(i+1,j-1);
            make_dirty(i+1,j+1);
        }

        f(i,0,n)
        {
            f(j,0,m)
                cout<<!(dp[i][j])<<" ";
            cout<<NL;
        }
    }
    return 0;
}