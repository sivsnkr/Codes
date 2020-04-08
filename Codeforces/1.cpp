#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> numbers(n);

    int i;
    for(i = 0; i < n; i++)
    {
        cin>>numbers[i];
    }

    int uniquec = 0;

    vector<bool> processed(100001);
    vector<int> uniques(n);
    for(i = n-1; i >= 0; i--)
    {
        uniques[i] = uniquec;
        if(!processed[numbers[i]])
        {
            uniquec++;
            processed[numbers[i]] = true;
        }
    }

    processed.assign(sizeof(processed),false);

    long long int sum = 0;
    for(i = 0; i < n; i++)
    {
        if(!processed[numbers[i]])
        {
            sum+=uniques[i];
            processed[numbers[i]] = true;
        }
    }
    cout<<sum<<"\n";
}