#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; scanf("%d",&t); while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

int solve(int n,const vector<int> &allprime)
{
    int count = 0;
    for(int i = 0; allprime[i]*allprime[i] <= n; i++)
    {
        if(n%allprime[i] == 0)
        {
            count++;
            while(n%allprime[i] == 0)
                n/=allprime[i];
        }
    }
    if(n > 1)
        count++;
    return count;
}

void getallp(vector<int> &allprime,int n)
{
    vector<bool> isprime(n,1);
    for(int i = 2; i < n; i++)
    {
        if(isprime[i])
        {
            for(int j = 1+1; j*i <= n; j++)
            {
                isprime[i*j] = 0;
            }
        }
    }

    for(int i = 2; i < n; i++)
    {
        if(isprime[i])
            allprime.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    vector<int> allprime;
    getallp(allprime,100000);
    vector<vector<bool>> haskfactor(6,vector<bool>(100001,0));

    for(int i = 1; i <= 5; i++)
    {
        for(int j = 2; j < 100001; j++)
        {
            if(solve(j,allprime) == i)
                haskfactor[i][j] = 1;
        }
    }

    vector<vector<int>> nooffactor(6,vector<int>(100001));
    for(int i = 1; i < 6; i++)
    {
        int sum = 0;
        for(int j = 2; j < 100001; j++)
        {
            if(haskfactor[i][j])
            {
                sum++;
            }
            nooffactor[i][j] = sum;
        }
    }
    
    test
    {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int count = nooffactor[k][b]-nooffactor[k][a];
        if(solve(a,allprime) == k)
            count++;
        printf("%d\n",count);
    }
    return 0;
}