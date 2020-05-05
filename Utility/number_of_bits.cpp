#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int solve(ll n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n = n>>1;
    }
    return count;
}

int solveanother(ll n)
{
    return floor(log2(n))+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    // count number of bits in any integer
    ll n = 16;
    int bits = solve(n);
    printf("%d\n",bits);
    printf("another solution : %d\n",solveanother(n));
    return 0;
}