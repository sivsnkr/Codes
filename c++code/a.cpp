#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

// agr ek logic kam nhi kr rha ya implement krna muskil hai to duskra try kro
inline void solve()
{
    string s;cin>>s;

    int n = sz(s);
	vector<bool> islast(n, 0);

	set<char> st;
	for(int i = 0; i < n; i++){
		if(st.find(s[i]) == st.end()){
			islast[i] = 1;
		}
		st.insert(s[i]);
	}
    
    string res = "A";
    char mx = 'A';
    for(int i = sz(s) - 1; i >= 0; i--){
        if(islast[i]){
            res += s[i];
            mx = s[i];
            continue;
        }

        if(res[sz(res) - 1] > res[sz(res) - 2]){
            if(s[i] < mx){
                res += s[i];
                mx = s[i];
            }
        }else{
            if(s[i] <= mx){
                res += s[i];
                mx = s[i];
            }
        }
    }

    res = res.substr(1, sz(res) - 1);
    reverse(all(res));

    set<char> uniq;

	string te = "";
	for(char c : res){
		uniq.insert(c);
		te += c;
		if(sz(uniq) == sz(st))
			break;
	}

    cout<<te<<"\n";
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
        cout<<"Execution time : "<<execution_time()*1000<<" ms"<<"\n";
    #endif
    cout.flush();
    return 0;
}
