#include <bits/stdc++.h>
using namespace std;

// multiply and give modulo of two numbers even if multiplication
// of those two number doesn't fit in int
int modulo = 1000000007;
int multiply(int a, int b)
{
    int p = b;
    int c = 0;
    vector<int> s;
    while (a > 1)
    {
        if (a & 1)
        {
            // odd number
            s.push_back(p);
            p *= 2;
            p %= modulo;
        }
        else
        {
            p *= 2;
            p %= modulo;
        }
        a = a >> 1;
    }

    for(int i : s)
    {
        p+=i;
        p%=modulo;
    }
    return p;
}

int main()
{
    int a = 454567565, b = 345675675;

    // int getres = multiply(a, b);
    int getres = (a * b)%modulo;
    cout << getres << "\n";
}