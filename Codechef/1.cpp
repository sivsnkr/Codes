#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define testf int t; scanf("%d",&t); while(t--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define size(container) (int)container.size()
#define int long long int
bool hc(int coin,map<int,int> coins)
{
    if(coin == 0)
        return true;
    if(coin == 10 && coins[10] >= coin/10)
    {
        coins[10]-=coin/10;
        return true;
    }
    if(coin >= 5 && coins[5] >= coin/5)
    {
        coins[5]-=coin/5;
        return true;
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test
    {
        map<int,int> coins;
        coins[5] = 0,coins[10] = 0,coins[15] = 0;
        int n;
        cin>>n;
        bool isvalid = true;
        f(i,0,n)
        {
            int c;
            cin>>c;
            if(hc(c-5,coins))
            {
                coins[c]++;
            }
            else
            {
                cout<<"NO"<<NL;
                isvalid = false;
                break;
            }
        }
        if(isvalid)
        {
            cout<<"YES"<<NL;
        }
    }
    fflush(stdin);
    fflush(stdout);
    return 0;
}