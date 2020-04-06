#include<bits/stdc++.h>
using namespace std;

// calculate a to power b in log(b)+1 time
long long int binary_exponent(int a, int b)
{
    if(b == 0)
        return 1;
    int p = 1;
    long long int po = a;
    while (p<b)
    {
        po*=po;
        p*=2;
    }

    if(b > p)
    {
        po*=a;
    }

    return po;
}
int main()
{
    long long int p = binary_exponent(3,0);
    cout<<p<<"\n";
}