#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int n;cin>>n;
    if(n == 1)
    {
        cout<<-1<<"\n";
        return 0;
    }
    if(n*(n+1) > 1000000000)
    {
        cout<<-1<<"\n";
        return 0;
    }
    cout<<n<<" "<<n+1<<" "<<n*(n+1)<<"\n";
    return 0;
}