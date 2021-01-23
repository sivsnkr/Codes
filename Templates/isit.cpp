#include <bits/stdc++.h>
using namespace std;

// this check to check if any number is power of 2 using bitmasking

class Isit
{
    public:
    bool ispoweroftwo(int n)
    {
        if((n&(n-1)) == 0)
            return true;
        return false;
    }
    bool is_prime(int n)
    {
        if(n == 1)
            return false;
        for(int i = 2; i*i <= n; i++)
            if(n%i == 0)
                return false;

        return true;
    }
    bool is_plaindrome(string s)
    {
        int st = 0,e = s.length()-1;
        while(st < e)
        {
            if(s[st] != s[e])
                return false;
            st++,e--;
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
}