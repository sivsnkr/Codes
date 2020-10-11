// list all prime number upto n in o(n) time
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> is_prime(n+1,0);
    vector<int> primelist;
    for(i = 2; i <= n; i++)
    {
        if(is_prime[i] == 0)
        {
            is_prime[i] = i;
            primelist.push_back(i);
        }
        for(int j = 0; j < primelist.size()&&i*primelist[j]<=n&&primelist[j]<=is_prime[i]; j++)
        {
            is_prime[i*primelist[j]] = primelist[j];
        }
    }

    for(i = 2; i <= n; i++)
    {
        if(is_prime[i] == i)
        {
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}