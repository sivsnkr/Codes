#include <bits/stdc++.h>
using namespace std;

// multiply and give modulo of two numbers even if multiplication
// of those two number doesn't fit in int
int multiply(int a, int b)
{
    int modulo = 1000000007;

    int p = b;
    while (a > 1)
    {
        if (a & 1)
        {
            // odd number
            p *= 2;
            p %= modulo;
            p += b;
            p %= modulo;
        }
        else
        {
            p *= 2;
            p %= modulo;
        }
        a = a >> 1;
    }
    return p;
}
int main()
{
    long long int a = 56456, b = 56456;

    // int getres = multiply(a, b);
    long long int getres = a * b;
    cout << getres % 1000000007 << "\n";
}