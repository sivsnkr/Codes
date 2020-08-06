#include<bits/stdc++.h>
using namespace std;

int main()
{
    float mx = 0,mix = 13434.5445;
    float my = 0,miy = 12344.54534;
    for(int i = 0; i < 4; i++)
    {
        float x,y;
        cin>>x>>y;
        mx = max(mx,x),mix = min(mix,x);
        my = max(my,y),miy = min(miy,y);
    }
    float px,py;
    cin>>px>>py;
    if((px >= mix && px <= mx) && (py >= miy && py <= my))
        cout<<"Point Lies Inside Rectange"<<endl;
    else
    {
        cout<<"Point lies outside Rectangle"<<endl;
    }
}