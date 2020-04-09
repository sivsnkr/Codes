#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d;cin>>n>>d;
    vector<pair<int,int>> timetable(n);
    int mxtime = 0,mmtime=0;
    for(int i = 0; i < n; i++)
    {
        int mt,mxt;cin>>mt>>mxt;
        timetable[i] = {mt,mxt};
        mxtime+=mxt;
        mmtime+=mt;
    }

    if(d > mxtime || d < mmtime)
    {
        cout<<"NO";
    }else
    {
        cout<<"YES"<<"\n";
        for(int i = 0; i < n; i++)
        {
            cout<<min(timetable[i].second,d-mmtime+timetable[i].first)<<" ";
            d -= min(timetable[i].second,d-mmtime+timetable[i].first);
            mmtime-=timetable[i].first;
        }
    }
    cout<<"\n";
    return 0;
}