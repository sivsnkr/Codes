#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
clock_t startTime;
double time_taken();
#define size(a) (int)(a).size()
vector<vector<int>> res;
int n;

inline void solve()
{
    cin>>n;
    int en = n*n;
    res.assign(n,vector<int>(n,0));
    vector<vector<bool>> board(n,vector<bool>(n,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0)
                continue;
            if(j == 0){
                board[i][j] = !board[i-1][j];
            }else{
                board[i][j] = !board[i][j-1];
            }
        }
    }

    for(int i = 0; i < en; i++){
        int te;cin>>te;
        bool found = 0;
        if(te == 1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(res[i][j] == 0 && board[i][j]){
                        res[i][j] = 2;
                        cout<<res[i][j]<<" "<<i+1<<" "<<j+1<<endl;
                        found = 1;
                        break;
                    }
                }
                if(found)
                        break;
            }
            if(!found){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(res[i][j] == 0 && !board[i][j]){
                            res[i][j] = 3;
                            cout<<res[i][j]<<" "<<i+1<<" "<<j+1<<endl;
                            found = 1;
                            break;
                        }
                    }
                }
                if(found)
                        break;
            }
        }else if(te == 2){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(res[i][j] == 0 && !board[i][j]){
                        res[i][j] = 1;
                        cout<<res[i][j]<<" "<<i+1<<" "<<j+1<<endl;
                        found = 1;
                        break;
                    }
                }
                if(found)
                        break;
            }
            if(!found){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(res[i][j] == 0 && board[i][j]){
                            res[i][j] = 3;
                            cout<<res[i][j]<<" "<<i+1<<" "<<j+1<<endl;
                            found = 1;
                            break;
                        }
                    }
                    if(found)
                        break;
                }
            }
        }else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(res[i][j] == 0 && !board[i][j]){
                        res[i][j] = 1;
                        cout<<res[i][j]<<" "<<i+1<<" "<<j+1<<endl;
                        found = 1;
                        break;
                    }
                }
                if(found)
                        break;
            }
            if(!found){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(res[i][j] == 0 && board[i][j]){
                            res[i][j] = 2;
                            cout<<res[i][j]<<" "<<i+1<<" "<<j+1<<endl;
                            found = 1;
                            break;
                        }
                    }
                    if(found)
                        break;
                }
            }
        }
    }
}

int32_t main()
{
    startTime = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    int t = 1;
    while(t--){
        solve();
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}

double time_taken() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
