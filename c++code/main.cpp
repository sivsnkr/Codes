#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

// agr ek logic kam nhi kr rha ya implement krna muskil hai to duskra try kro
const int N = 10;
vector<vector<char>> a(N,vector<char>(N));
vector<vector<bool>> vis(N,vector<bool>(N));
int k,n;
double cnt = 0;

void dfs(int i, int j, int len){

    if(len > k)
        return;

    if(i < 0 || j < 0 || i >= n || j >= n || a[i][j] == '#' || vis[i][j])
        return;
    
    if(len == k)
        cnt += 1;
    vis[i][j] = 1;

    dfs(i - 1, j, len + 1);
    dfs(i + 1, j, len + 1);
    dfs(i, j - 1, len + 1);
    dfs(i, j + 1, len + 1);
}


inline void solve()
{
    cin>>n>>k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }

    double res = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == '.'){
                cnt = 0;
                vis.assign(N,vector<bool>(N,0));
                dfs(i,j,1);
                res += cnt;
            }
        }
    }

    cout<<res/2<<NL;
}

int32_t main()
{
    clock_t startTime;
    startTime = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    int t = 1;
    while(t--){
        solve();
    }
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<NL;
    #endif
    return 0;
}
