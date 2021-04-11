#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
#define size(a) (int)(a).size()

const int MX = 6000;
int n;
vector<vector<int>> mat(MX,vector<int>(MX,0));

vector<int> conv(string s){
    string te = "?";
    for(char c : s) {
        switch (c) {
            case '0':
                te += "0000";
                break;
            case '1':
                te += "0001";
                break;
            case '2':
                te += "0010";
                break;
            case '3':
                te += "0011";
                break;
            case '4':
                te += "0100";
                break;
            case '5':
                te += "0101";
                break;
            case '6':
                te += "0110";
                break;
            case '7':
                te += "0111";
                break;
            case '8':
                te += "1000";
                break;
            case '9':
                te += "1001";
                break;
            case 'A':
                te += "1010";
                break;
            case 'B':
                te += "1011";
                break;
            case 'C':
                te += "1100";
                break;
            case 'D':
                te += "1101";
                break;
            case 'E':
                te += "1110";
                break;
            case 'F':
                te += "1111";
                break;
        }
    }
    vector<int> res;
    for(char c : te){
        res.push_back(c-'0');
    }
    return res;
}

int get_sum(int r1, int r2, int c1, int c2){
    return mat[r2][c2] - mat[r1][c2] - mat[r2][c1] + mat[r1][c1];
}

bool valid(int x){
    int in = n/x;
    // cout<<"x "<<x<<NL;
    for(int i = 1; i <= n; i+=in){
        for(int j = in; j <= n; j+=in){
            // int sum = mat[i+in-1][j] - mat[i+in-1][j-in] + mat[i-1][j-in] - mat[i-1][j];
            int sum = get_sum(i-1,i+in-1,j-in,j);
            // cout<<"sum "<<sum<<NL;
            if(!(sum == 0 || sum == in*in))
                return false;
        }
    }
    return true;
}

inline void solve()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        string s;cin>>s;
        mat[i] = conv(s);
        mat[i][0] = 0;
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++)
    //         mat[i][j] += mat[i][j-1];
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         mat[j][i] += mat[j-1][i];
    //     }
    // }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mat[i][j] = mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1] + mat[i][j];
        }
    }

    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            if(valid(i)){
                ans = n/i;
                break;
            }
        }
    }

    cout<<ans<<NL;
}

int32_t main()
{
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