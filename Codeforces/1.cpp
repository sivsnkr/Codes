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

bool cbp(string s)
{
    int z = 0,o = 0;
    for(char a : s)
        if(a == '0')
            z++;
        else    
            o++;
    int le = s.length();
    if(le2 == 0)
    {
        if(o%2 == 0 && z%2 == 0)
            return true;
    }
    else
    {
        int co = 0;
        if(o%2)
            co++;
        if(z%2)
            co++;
        if(co != 2)
            return true;
    }
    return false;
}

bool isplain(std::string s)
{
    int st = 0,e = s.length()-1;
    while(st < e)
    {
        if(s[st] != s[e])
            return false;
        st++,e--;
    }
    return true;
}

void solve()
{
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    test
    {
        int n;cin>>s;
        vector<string> str(n);
        int c = 0;
        int p = 0;
        f(i,0,n)
        {
            cin>>str[i];
            if(isplain(str[i]))
                p++;
        }
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