#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

const int nax = 405;
const ll INF = 1e18L + 5; // 10^18+5
ll dp[nax][nax];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int& x : a) {
        scanf("%d", &x);
    }
    auto sum = [&](int L, int R) {
        ll s = 0;
        for(int i = L; i <= R; ++i) {
            s += a[i];
        }
        return s;
    };
    for(int L = n - 1; L >= 0; --L) {
        for(int R = L; R < n; ++R) {
            if(L == R) {
                dp[L][R] = 0;
            }
            else {
                dp[L][R] = INF;
                ll s = sum(L, R);
                for(int i = L; i < R; ++i) {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + s);
                }
            }
        }
    }
    
    printf("%lld\n", dp[0][n-1]);

    return 0;
}