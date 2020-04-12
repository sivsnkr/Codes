#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t > 0)
    {
        int n;cin>>n;
        int arr[n+1];
        memset(arr,0,n+1);

        bool in[n+1];
        memset(in,0,sizeof(in));

        for(int i = 2; i <= n; i++)
        {
            if(arr[i] == 0)
            {
                for(int j = i*i; j <= n; j+=i)
                {
                    if(arr[j] == 0)
                        arr[j] = i;
                }
            }
        }

        set<int> temp;
        temp.insert(1);
        int noofdays = 0;
        t--;    
    }
}