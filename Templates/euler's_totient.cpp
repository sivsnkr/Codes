#include<bits/stdc++.h>
using namespace std;

class Euler_totient{
    int single_value(int n){
        // tc is o(√n);
        
        int psivalue = n;
        for(int i = 2; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                while(n%i == 0)
                    n/=i;
                psivalue-=psivalue/i;
            }
        }

        if(n > 1)
            psivalue -= psivalue/n;

        return psivalue;
    }

    vector<int> range_value(int n){
        // tc is o(nloglogn)

        vector<int> psivalue(n+1);
        iota(psivalue.begin(),psivalue.end(),0);
        for(int i = 2; i <= n; i++)
        {
            if(psivalue[i] == i)
            {
                for(int j = i; j <= n; j+=i)
                {
                    psivalue[j]-=psivalue[j]/i;
                }
            }
        }
        return psivalue;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
}
