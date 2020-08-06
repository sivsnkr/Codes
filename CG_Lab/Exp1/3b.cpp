#include<bits/stdc++.h>
using namespace std;

pair<float,float> a,b,c,p;
int pos(pair<float,float> a,pair<float,float> b,pair<float,float> p)
{
    return ((b.first-a.first)*(p.second-a.second) - (b.second-a.second)*(p.first-a.first));
}

int main()
{
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
    cin>>p.first>>p.second;
    float mx = 0,mix = 12345.4535;
    float p1 = pos(a,b,p),p2 = pos(b,c,p),p3 = pos(c,a,p);
    if((p1 < 0 && p2 < 0 && p3 < 0) || (p1 > 0 && p2 > 0 && p3 > 0) || p1 == 0 || p2 == 0 || p3 == 0)
        cout<<"Point lies inside triangle";
    else
    {
        cout<<"Point lies outside the triangle";
    }
    cout<<endl;
}