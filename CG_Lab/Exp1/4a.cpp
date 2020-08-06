#include<bits/stdc++.h>
using namespace std;

pair<float,float> a,b,c;

float area(pair<float,float> a,pair<float,float> b,pair<float,float> c)
{
    float res =  (a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second));
    res/=2;
    return abs(res);
}

bool pos(pair<float,float> a,pair<float,float> b,pair<float,float> c,pair<float,float> p)
{
    float a0 = area(a,b,c);
    float a1 = area(a,b,p)+area(a,p,c)+area(p,b,c);
    if(a0 == a1)
        return 1;
    else    
        return 0;
}

int main()
{
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
    float my,miy,mx,mix;
    mix = (int)min({a.first,b.first,c.first});
    mx = (int)max({a.first,b.first,c.first});
    miy = (int)min({a.second,b.second,c.second});
    my = (int)max({a.second,b.second,c.second});
    cout<<"all the points inside trianlge"<<endl;
    for(int x = mix; x <= mx; x++)
    {
        for(int y = miy; y <= my; y++)
        {
            if(pos(a,b,c,{x,y}))
                cout<<x<<" "<<y<<endl;
        }
    }
}