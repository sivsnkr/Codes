#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

bool is_prime(int n)
{
    if(n == 1)
        return false;
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n;cin>>n;
    is_prime(n)?cout<<"YES":cout<<"NO";
    cout<<nl;

    return 0;
}