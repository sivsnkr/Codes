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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int n;
    scanf("%d",&n);
    vector<int> pies(n);
    for(int &it : pies)scanf("%d",&it);
    vector<int>total(n+1);
    vector<int>score(n+1);
    score[n] = pies[n-1];
    int sum = 0;
    for(int i = n; i > 0; i--)
    {
        sum+=pies[i-1];
        total[i] = sum;
    }

    for(int i = n-1; i > 0; i--)
    {
        score[i] = max(pies[i-1]+total[i+1]-score[i+1],score[i+1]);
    }
    printf("%d %d\n",total[1]-score[1],score[1]);
    return 0;
}