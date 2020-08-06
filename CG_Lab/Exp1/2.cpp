#include<bits/stdc++.h>
using namespace std;

pair<float,float> a,b,p;

int pos()
{
    return ((b.first-a.first)*(p.second-a.second) - (b.second-a.second)*(p.first-a.first));
}

int main()
{
    cin>>a.first>>a.second>>b.first>>b.second;
    cin>>p.first>>p.second;
    int po = pos();
    if(!po)
        cout<<"Point lies on the line";
    else if(po > 0)
        cout<<"Point lies in left side of the line";
    else
    {
        cout<<"Point lies on the right side of the line";
    }
    cout<<endl;
}