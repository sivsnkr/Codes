#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

// agr ek logic kam nhi kr rha ya implement krna muskil hai to duskra try kro

bool is_prime(int n)
    {
        if(n == 1)
            return false;
        for(int i = 2; i*i <= n; i++)
            if(n%i == 0)
                return false;

        return true;
    }

inline void solve()
{
    int a = 1e9+9;
    cout<<is_prime(a)<<"\n";
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
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<"\n";
    #endif
    cout.flush();
    return 0;
}
