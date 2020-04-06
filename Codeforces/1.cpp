#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];

    int i;
    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    unordered_set<int> visited;
    unordered_set<int> slog(n);

    int noofdays = 1;
    vector<int> sizearr;
    int size = 0;
    bool valid = true;
    
    for(int j : arr)
    {
        size++;
        if(j < 0)
        {
            if(slog.find(-j) == slog.end())
            {
                valid = false;
                break;
            }
            slog.erase(-j);
            if(slog.size() == 0)
            {
                noofdays++;
                sizearr.push_back(size);
                size = 0;
                visited.clear();
            }
        }
        else
        {
            if(visited.find(j) != visited.end())
            {
                valid = false;
                break;
            }
            slog.insert(j);
            visited.insert(j);
        }
    }

    if(!valid || slog.size() > 0)
        cout<<-1;
    else
    {
        cout<<noofdays-1<<"\n";
        for(int j : sizearr)
            cout<<j<<" ";
    }
    cout<<"\n";
    return 0;
}