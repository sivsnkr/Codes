#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()

// bool find(vector<int> arr, int value)
// {
//     bitset<50> can;
//     can[0] = true;
//     int n = size(arr);
//     for(int i = 0; i < n; i++)
//     {
//         can|=(can << arr[i]);
//     }
//     return can[value];
// }

bool find(vector<int> arr, int value)
{
    bitset<50> can;
    can[0] = 1;
    int n = size(arr);
    for(int i = 0; i < n;i++)
    {
        for(int j = value; j >= arr[i]; j--)
        {
            if(can[j-arr[i]])
                can[j] = true;
        }
    }
    return can[value];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    vector<int> arr{1,2,3,4};
    bool isthere = find(arr,3);
    cout<<isthere<<endl;
    isthere = find(arr,7);
    cout<<isthere<<endl;
    isthere = find(arr,20);
    cout<<isthere<<endl;
    return 0;
}