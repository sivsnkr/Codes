#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    int x,y,z;cin>>x>>y>>z;
    int a,b,c;cin>>a>>b>>c;
    bool isvalid = true;
    if(a -x < 0)
        isvalid = false;
    a-=x;
    if(a+b-y < 0 && isvalid)
        isvalid = false;

    if(a+b+c-y-z < 0 && isvalid)
        isvalid = false;

    isvalid?cout<<"YES":cout<<"NO";
    cout<<"\n";

    return 0;
}