#include<bits/stdc++.h>
using namespace std;

int index(vector<int> v, int t)
{
    int first = 0;
    int last = v.size();
    while(first <= last)
    {
        int middle = (first+last)/2;
        if(v[middle] == t)
        {
            return middle;
        }
        else if(v[middle] > t)
        {
            last = middle-1;
        }
        else
        {
            first = middle+1;
        }
    }
    return first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    vector<vector<int>> s(n);
    for(int i = 0; i < n; i++)
    {
        int c;cin>>c;
        for(int j = 0; j < c; j++)
        {
            int v;cin>>v;s[i].push_back(v);
        }
    }

    vector<bool> ha(n,false);
    vector<int> minvs,maxvs;
    for(int i = 0; i < n; i++)
    {
        // check all the sequence
        bool h = false;
        int minv = INT_MAX,maxv = 0;
        for(int j : s[i])
        {
            maxv = max(maxv,j);
            minv = min(minv,j);
            if(j > minv)
            {
                ha[i] = true;
                break;
            }
        }
        if(!ha[i])
        {
            minvs.push_back(minv);maxvs.push_back(maxv);
        }
    }

    long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(ha[i])
        {
            sum+=(2*n-1);
        }
    }

    sort(minvs.begin(),minvs.end());
    sort(maxvs.begin(),maxvs.end());

    for(int i = 0; i < minvs.size(); i++)
    {
        int ind = index(maxvs,minvs[i]);
        while(ind < maxvs.size()&&maxvs[ind] == minvs[i])
        {
            ind++;
        }
        sum+=(maxvs.size()-ind);
    }

    // for(int i = 0; i < maxvs.size(); i++)
    // {
    //     int ind = index(minvs,maxvs[i]);
    //     while(ind < minvs.size()&&minvs[ind] == maxvs[i])
    //     {
    //         ind++;
    //     }
    //     sum+=(minvs.size()-ind);
    // }
    cout<<sum<<"\n";
    return 0;
}