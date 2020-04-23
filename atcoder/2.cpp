#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here

    int n;cin>>n;
    
    ll dp[n];
    ll a[n];
    for(int i = 0; i < n; i++)
    {
    	cin>>a[i];
    	dp[i] = a[i];
    }
    ll sum  = 0;
    for(int i = 0; i < n-1; i++){
    	pair<int,int> a;
    	ll m = numeric_limits<ll>::max();
    	for(int j  = 0; j < n-i-1; j++){
    		if(dp[j]+dp[j+1] < m){
    			m = dp[j]+dp[j+1];
    			a = {j,j+1};
    		}
    	}

    	ll temp = dp[a.first]+dp[a.second];
    	dp[a.first] = temp;
    	for(int j  = a.second;j < n-i; j++)
    		dp[j] = dp[j+1];

    		// cout<<n-i-2<<"\n";
    	sum+=temp;
    }

    cout<<sum<<"\n";

    return 0;
}