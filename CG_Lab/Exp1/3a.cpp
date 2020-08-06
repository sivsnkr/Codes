#include<bits/stdc++.h>
using namespace std;

float area(pair<float,float> a,pair<float,float> b,pair<float,float> c)
{
    float res =  (a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second));
    res/=2;
    return abs(res);
}
pair<float,float> a,b,c,p;
int main()
{
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
    cin>>p.first>>p.second;
    float a0 = area(a,b,c);
    float a1 = area(a,b,p)+area(a,p,c)+area(p,b,c);
    if(a0 == a1)
        cout<<"Point lies inside triangle";
    else    
        cout<<"Point lies outside triangle";
    cout<<endl;
}