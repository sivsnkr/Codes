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

string adds(string a,string b)
{
    // cout<<a<<" "<<b<<NL;
    string s = "";
    int i = 0;
    reverse(all(a)),reverse(all(b));
    int c = 0;
    for(i = 0; i < min(a.length(),b.length()); i++)
    {
        int su = (a[i]-48)+(b[i]-48)+c;
        s+=to_string(su-(su/10)*10);
        c = su/10;
    }
    while(c > 0 && i < a.length())
    {
        int su = (a[i]-48)+c;
        s+=to_string(su-(su/10)*10);
        c = su/10;
        i++;
    }
    while(c > 0 && i < b.length())
    {
        int su = (b[i]-48)+c;
        s+=to_string(su-(su/10)*10);
        c = su/10;
        i++;
    }
    // cout<<c<<NL;
    while(i < b.length())
        s+=b[i],i++;
    while(i < a.length())
        s+=a[i],i++;
    if(c > 0)
        s+=to_string(c);
    reverse(all(s));
    // cout<<"str "<<s<<NL;
    return s;
}

void solve()
{
    #ifndef ONLINE_JUDGE
        fh;
    #endif
    // all the code goes here
    int n;cin>>n;
    string s;cin>>s;
    string ms = s;
    f(i,n/2-4,n/2+5)
    {
        if(i <= 0 || i >= n || s[i] == '0')
            continue;
        string te = adds(s.substr(0,i),s.substr(i,n-i));
        if(te.length() < ms.length())
            ms = te;
        else if(te.length() == ms.length())
        {
            ms = min(te,ms);
        }
    }
    cout<<ms<<NL;
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