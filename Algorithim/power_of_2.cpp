#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

// this check to check if any number is power of 2 using bitmasking
bool ispoweroftwo(int k)
{
    if((k&(k-1)) == 0)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t = 5;
    int t1 = 4;
    printf("%d %d\n",ispoweroftwo(t),ispoweroftwo(t1));
    return 0;
}