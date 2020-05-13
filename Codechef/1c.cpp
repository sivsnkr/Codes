//   ^_HAR HAR MAHADEV_^
//   |Om Namah shivaya|

// AUTHOR: Harshil Mehta

#include <bits/stdc++.h>
//For ordered_set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//#include<boost/multiprecision/cpp_int.hpp>
#define mod 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define all(a) a.begin(),a.end()
#define br "\n"
//using namespace boost::multiprecision;
using namespace std;
// For ordered_set
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int maxn = 1e5;

ll x , y , l , r ;
ll sol = LLONG_MAX , tmp_sol = 0;
// Product Function
ll func(ll z) {
	return ((x & z) * (y & z)) ;
}
ll brute_force() {
	ll mx = -1 ;
	ll z = 0;
	f(i,l,r+1) {
		if(mx < func(i)) {
			mx = func(i) ;
			z = i ;
		}
	}
	return z ;
}
// Auxillary function for obtaining prefix bits which are common
int get_pre() {
	tmp_sol = 0 ;
	int k = 0;
	for(int i = 42 ; i >= 0; i--) {
		if((r & (1LL << i)) == (l & (1LL << i))) {
			if((r & (1LL << i))) {
				tmp_sol |= (1LL << i) ;
			}
		} else {
			k = i ;
			break ;
		}
	}
	return k;
}
void solve() {
	cin >> x >> y >> l >> r ;
	ll _or = (x|y) ;
	//ll ans_bf = brute_force();
	ll mx = func(l) ,t_sol = tmp_sol ;
	sol = l ;
	int k = get_pre() ;
	for(int i = k ; i >= 0 ; i --) {
		// intialising container with prefixed value
		t_sol = tmp_sol ;
		// taking all possible prefix of R
		for(int j = k ; j >= i; j--) {
			if(r & (1LL<<j)) {
				t_sol |= (1LL << j) ;
			}
		}
		// switching i th bit as Z should be smaller than R (not needed as it is already OFF)
		t_sol &= (~(1LL << i));
		// Copying next bits of X OR Y for maximizing F
		for(int j = i - 1; j >= 0 ; j--) {
			if(_or & (1LL << j)) {
				t_sol |= (1LL << j) ;
			}
		}
		// checking for validations
		if(t_sol <= r && t_sol >= l) {
			// selecting optimal solution
			if(mx < func(t_sol)) {
				mx = func(t_sol) ;
				sol = t_sol ;
			}
			// taking minimal possible Z
			if(mx == func(t_sol))sol = min(t_sol , sol) ;
		}
	}
	for(int i = k ; i >= 0 ; i --) {
		// intialising container with prefixed value
		t_sol = tmp_sol ;
		// taking all possible prefix of R
		for(int j = k ; j >= i; j--) {
			if(l & (1LL<<j)) {
				t_sol |= (1LL << j) ;
			}
		}
		// turning i th bit as Z should be greater than L
		t_sol |= (1LL << i);
		// Copying next bits of X OR Y for maximizing F
		for(int j = i - 1; j >= 0 ; j--) {
			if(_or & (1LL << j)) {
				t_sol |= (1LL << j) ;
			}
		}
		// checking for validations
		if(t_sol <= r && t_sol >=l) {
			// selecting optimal solution
			if(mx < func(t_sol)) {
				mx = func(t_sol) ;
				sol = t_sol ;
			}
			// taking minimal possible Z
			if(mx == func(t_sol))sol = min(t_sol , sol) ;
		}
	}
	// Checking for upper bound and lower bound
	if(func(r) > mx) {
		sol = r ;
	}
	cout << sol << br ;
	sol = LLONG_MAX;
}
int main() {
	//FILE_READ_IN ;
	//FILE_READ_OUT;
	fast ;
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
