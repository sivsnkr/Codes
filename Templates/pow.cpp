#include<bits/stdc++.h>
using namespace std;

// calculate a to power b in log(b)+1 time
long long bin_exp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    long long int p = bin_exp(3,2);
    cout<<p<<"\n";
}