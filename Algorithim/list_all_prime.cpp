#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    // list all prime number upto n in o(nloglogn)
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    for (int i = 3; i * i <= n; i+=2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    if(n >= 2)
    {
        cout<<2<<" ";
    }
    for(int i = 3; i < n+1; i+=2)
    {
        if(is_prime[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}