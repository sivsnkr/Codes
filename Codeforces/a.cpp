#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000*1000*1000+7;
ll m;
ll power(ll n) 
{ 
    if (n <= 1) 
        return m; 
  
    // This power function returns first row of 
    // {Transformation Matrix}^n-1*Initial Vector 
    n -= 2; 
  
    // This is an identity matrix. 
    ll res[2][2] = { 1, 0, 0, 1 }; 
  
    // this is Transformation matrix. 
    ll tMat[2][2] = { m-1, m-1, 1, 0 }; 
  
    // Matrix exponentiation to calculate power of {tMat}^n-1 
    // store res in "res" matrix. 
    while (n) { 
  
        if (n & 1) { 
            ll tmp[2][2]; 
            tmp[0][0] = (res[0][0] * tMat[0][0] + res[0][1] * tMat[1][0]) % mod; 
            tmp[0][1] = (res[0][0] * tMat[0][1] + res[0][1] * tMat[1][1]) % mod; 
            tmp[1][0] = (res[1][0] * tMat[0][0] + res[1][1] * tMat[1][0]) % mod; 
            tmp[1][1] = (res[1][0] * tMat[0][1] + res[1][1] * tMat[1][1]) % mod; 
            res[0][0] = tmp[0][0]; 
            res[0][1] = tmp[0][1]; 
            res[1][0] = tmp[1][0]; 
            res[1][1] = tmp[1][1]; 
        } 
        n = n / 2; 
        ll tmp[2][2]; 
        tmp[0][0] = (tMat[0][0] * tMat[0][0] + tMat[0][1] * tMat[1][0]) % mod; 
        tmp[0][1] = (tMat[0][0] * tMat[0][1] + tMat[0][1] * tMat[1][1]) % mod; 
        tmp[1][0] = (tMat[1][0] * tMat[0][0] + tMat[1][1] * tMat[1][0]) % mod; 
        tmp[1][1] = (tMat[1][0] * tMat[0][1] + tMat[1][1] * tMat[1][1]) % mod; 
        tMat[0][0] = tmp[0][0]; 
        tMat[0][1] = tmp[0][1]; 
        tMat[1][0] = tmp[1][0]; 
        tMat[1][1] = tmp[1][1]; 
    }  
    return (res[0][0] * ((m*m)%mod) + res[0][1] *m) % mod; 
} 
// ((m*m)%mod)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t; while(t--) {
        ll n; cin>>n>>m; m = m%mod;
        // cout<<n<<" "<<m<<" ";
        cout<<power(n)<<"\n";
    }
}