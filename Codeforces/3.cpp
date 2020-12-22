#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define int long long
template<typename T>
void read(vector<T> &a);

inline void solve()
{
    // all the code goes here
    test
    {
        int n,k;cin>>n>>k;
        vector<vector<int>> res(n,vector<int>(n,0));
        int r = 0,c = 0;
        while(k > 0 && r < n)
        {
            res[r][r] = 1;
            k--;
            r++;
        }
        r = 1;
        while(k > 0 && r < n)
        {
            int ir = r;
            int ic = 0;
            while(k < n-ir)
                ir++;
            while(ir < n && ic < n && k > 0)
            {
                res[ir][ic] = 1;
                k--;
                ir++,ic++;
            }
            ir = r;
            ic = ir,ir = 0;
            while(k < n-ic)
                ic++;
            while(ic < n && ir < n && k > 0)
            {
                res[ir][ic] = 1;
                k--;
                ir++,ic++;
            }
            r++;
        }

        // cout<<"k "<<k<<NL;

        set<int> col,row;
        f(i,0,n)
        {
            int sum = 0;
            f(j,0,n)
                if(res[i][j])
                    sum++;

            row.insert(sum);
            sum = 0;
            f(j,0,n)
                if(res[j][i])
                    sum++;

            col.insert(sum);
        }

        cout<<pow(*col.rbegin()-*col.begin(),2)+pow(*row.rbegin()-*row.begin(),2)<<NL;
        f(i,0,n)
        {
            f(j,0,n)
                cout<<res[i][j];
            cout<<NL;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
template<typename T>
void read(vector<T> &a)
{
    for(auto &it : a)cin>>it;
}