#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

// agr ek logic kam nhi kr rha ya implement krna muskil hai to duskra try kro
long double v;
long double res = 0;
void comp(int pos, vector<long double> prob, long double pro, int step){
	if(pos == 2){
		res += step * pro;
		return;
	}

	long double val = min(prob[pos], v);
	prob[pos] = max(prob[pos] - v, (long double)0);
	int cnt = 0;
	for(int i = 0; i < 3; i++){
		if(prob[i] != 0 && i != pos){
			cnt++;
		}
	}

	for(int i = 0; i < 3; i++){
		if(i != pos && prob[i] != 0){
			prob[i] += val / cnt;
		}
	}

	for(int i = 0; i < 3; i++){
		if(prob[i] != 0){
			comp(i, prob, pro * prob[i], step + 1);
		}
	}
}

inline void solve()
{
	vector<long double> prob(3);
	for(int i = 0; i < 3; i++){
		cin>>prob[i];
	}
	cin>>v;

	res = 0.0;
	for(int i = 0; i < 3; i++){
		comp(i, prob, prob[i], 1);
	}

	cout<<res<<NL;
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
	cin>>t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<NL;
    #endif
    return 0;
}
