#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	const string t = "RGB";

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int ans = 1e9;
		for (int offset = 0; offset < 3; ++offset) {
			vector<int> res(n);
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				res[j] = (s[j] != t[(j + offset) % 3]);
				cur += res[j];
				if (j >= k) cur -= res[j - k];
				if (j >= k - 1) ans = min(ans, cur);
			}
            for(int i = 0; i < n; i++)
                cout<<res[i]<<" \n"[i==n-1];
		}
		cout << ans << endl;
	}
	
	return 0;
}