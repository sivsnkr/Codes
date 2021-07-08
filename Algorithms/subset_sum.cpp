#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

const int N = 105;
int n;
vector<int> a(N);

class SubsetSum{
    // sum should be less than 1e5 and n should be less than 1e4
    bitset<100000> sums;
    public:
    SubsetSum(vector<int> a){
        sums[0] = 1;
        for(int i : a){
            sums = (sums | (sums << i));
        }
    }

    bool possible(int val){
        return sums[val];
    }
};

inline void solve()
{
    class SubsetSum st(vector<int>{3,1,5});

    int check = 8;
    int nocheck = 7;

    cout<<st.possible(check)<<NL;
    cout<<st.possible(nocheck)<<NL;
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
