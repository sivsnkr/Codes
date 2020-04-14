#include<bits/stdc++.h>
using namespace std;

int s(int a)
{
    string s = to_string(a);
    int sum = 0;
    for(char i : s)
    {
        sum+=(int(i)-'0');
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;cin>>a>>b>>c;
    vector<int> root;
    for(int x = 1; x <= 81; x++)
    {
        long long int res = b*pow(x,a)+c;
        if(res >= 1000000000)
            break;
        if(res > 0 && s(res) == x)
            root.push_back(res);
    }
    cout<<root.size()<<"\n";
    for(int x : root)
    {
        cout<<x<<" "; 
    }
    if(root.size() > 0)
        cout<<"\n";
    return 0;
}