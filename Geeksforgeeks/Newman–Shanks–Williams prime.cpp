#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    n = 13;
    int newman_series[n];
    newman_series[0] = 1;
    newman_series[1] = 1;
    for(int i = 2; i < n; i++)
    {
        newman_series[i] = 2*newman_series[i-1]+newman_series[i-2];
    }

    for(int i = 0; i < n; i++)
    {
        cout<<newman_series[i]<<" ";
    }
    cout<<endl;
}