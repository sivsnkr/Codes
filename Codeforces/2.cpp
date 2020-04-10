#include<bits/stdc++.h>
using namespace std;

bool check(long long int n)
{
    long long int a = 1,b = 0;
    while(a < n)
    {
        a += b;
        b = a-b;
    }
    
    if(a == n)
        return true;
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(check(n))
        {
            cout<<"IsFibo";
        }else{
            cout<<"IsNotFibo";
        }
    }
}