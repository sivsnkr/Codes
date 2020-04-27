#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n;cin>>n;

    // ------------------------------------
    // int psivalue = n;
    // for(int i = 2; i*i <= n; i++)
    // {
    //     if(n%i == 0)
    //     {
    //         while(n%i == 0)
    //             n/=i;
    //         psivalue-=psivalue/i;
    //     }
    // }

    // if(n > 1)
    //     psivalue -= psivalue/n;

    // cout<<psivalue<<"\n";

    // time complexity of above algorithm is O(_/n);
    // ----------------------------------------

    int psivalue[n];

    iota(psivalue,psivalue+n+1,0);
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

    for(int i = 0; i <= n; i++)
    {
        cout<<psivalue[i]<<" ";
    }
    cout<<nl;

    // psi value in O(nloglogn)


    return 0;
}
