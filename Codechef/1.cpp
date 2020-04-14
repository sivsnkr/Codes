#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int givef(int x)
{
    for(int i = 3; i*i <= x; i+=2)
    {
        if(x%i == 0)
        {
            return i;
        }
    }
    return -1;
}

bool ispossible(int x, int k)
{
    int counter = k;
    while(counter > 1)
    {
        if(x%2)
        {
            int fa = givef(x);
            if(fa<0)
                return false;
            x/=fa;
        }else
        {
            // even
            x /= 2;
        }
        counter--;
    }

    if(x == 1)
        return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t>0)
    {
        int x,k;cin>>x>>k;
        if(x > k&&x >= (long long)pow(2,k))
        {
            if(is_prime(x))
            {
                if(k == 1)
                    cout<<"1";
                else
                {
                    cout<<"0";
                }
                
            } 
            else
            {
                if(k == 1)
                    cout<<"1";
                else
                {
                    if(ispossible(x,k))
                        cout<<"1";
                    else
                    {
                        cout<<"0";
                    }
                    
                }
                
            }
            
        }
        else
        {
            cout<<"0";
        }
        cout<<"\n";
        
        t--;
    }
    return 0;
}