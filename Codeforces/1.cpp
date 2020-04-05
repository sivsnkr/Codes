#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    int i;
    for(i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int freq[10000000] = {0};
    unordered_set<int> slog(n);

    bool print = true;
    int noofdays = 1;
    vector<int> sizearr;
    int size = 0;
    for(int j : arr)
    {
        size++;
        if(j < 0)
        {
            if(slog.find(-j) == slog.end())
            {
                cout<<-1;
                print = false;
                break;
            }
            else
            {
                slog.erase(-j);
            } 
        }
        else
        {
            freq[j]++;
            if(freq[j] > 1)
            {
                if(slog.size() == 0)
                {   
                    noofdays++;
                    sizearr.push_back(size-1);
                    slog.insert(j);
                    size = 1;
                }
                else
                {
                    cout<<-1;
                    print = false;
                    break;
                }
            }
            else
            {
                slog.insert(j);
            }
        } 
    }

    if(print)
    {
        if(slog.size() > 0)
        {
            cout<<-1;
        }
        else
        {
            sizearr.push_back(size);
            cout<<noofdays<<endl;
            for(int i: sizearr)
            {
                cout<<i<<" ";
            }
        }
    }
    cout<<endl;
}