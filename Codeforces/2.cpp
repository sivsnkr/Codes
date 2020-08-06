#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf int t;scanf("%d", &t);while (t--)
#define test int t;cin >> t;while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
#define pb push_back
#define fh freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void readarray(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}

void solve()
{
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    test
    {
        int n;cin>>n;
        string s;cin>>s;
        vector<pair<int,int>> a(n);
        f(i,0,n)
            a[i] = {s[i]-48,i};
        sort(all(a));
        set<int> fi,se;
        int in = -1;
        int val = LLONG_MAX;
        f(i,0,n)
        {
            if(a[i].second > in && a[i].first <= val)
            {
                fi.insert(a[i].second);
                in = a[i].second;
                // val = a[i].first;
                a[i].first = LLONG_MAX;
            }
            else
                val = min(a[i].first,val);
        }
        in = -1;
        f(i,0,n)
        {
            if(a[i].first != LLONG_MAX && a[i].second > in)
            {
                se.insert(a[i].second);
                in = a[i].second;
            }
        }
        if(size(fi) + size(se) != n)
        {
            cout<<"-"<<NL;
            continue;
        }
        vector<int> res(n);
        for(int i : fi)
            res[i] = 1;
        for(int i : se)
            res[i] = 2;
        for(int i : res)
            cout<<i;
        cout<<NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    startTime = clock();
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}