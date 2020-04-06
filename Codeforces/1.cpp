#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> queue(n);
    int i;
    for(i = 0; i < n; i++)
    {
        cin>>queue[i];
    }

    sort(queue.begin(),queue.end());

    long long int sum = 0;
    int numberofdisp = 0;
    for(int j : queue)
    {
        if(sum > j)
            numberofdisp++;
        else
            sum+=j;
    }

    cout<<n-numberofdisp<<"\n";
    return 0;
}