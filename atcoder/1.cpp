#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int &c : a)
    {
        cin>>c;
    }

    bool arr[k+1];
    memset(arr,0,sizeof(arr));

    for(int i = 0; i <= k; i++)
    {
        for(int c : a)
        {
            if(i >= c && !arr[i-c])
                arr[i] = true;
        }
    }

    arr[k]?cout<<"First":cout<<"Second";
    cout<<"\n";

    return 0;
}