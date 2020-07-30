#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	
	vector<int> a(n), cnt(200 * 1000 + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	
	int val = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	int pos = find(a.begin(), a.end(), val) - a.begin();
	
	cout << n - cnt[val] << endl;
	int siz = 0;
	for (int i = pos - 1; i >= 0; --i) {
		cout << 1 + (a[i] > a[i + 1]) << " " << i + 1 << " " << i + 2 << " " << endl;
		a[i] = a[i + 1];
		++siz;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] != val) {
			assert(a[i] == val);
			cout << 1 + (a[i + 1] > a[i]) << " " << i + 2 << " " << i + 1 << " " << endl;
			a[i + 1] = a[i];
			++siz;
		}
	}
	
	assert(siz == n - cnt[val]);
	return 0;
}