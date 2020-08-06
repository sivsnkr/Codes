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
        int co = 1;
        vector<int> a(n);
        stack<pair<char,int>> st;
        st.push({s[0],1});
        a[0] = 1;
        int z = 0,o = 0;
        f(i,1,n)
        {
            if(!st.empty())
            {
                pair<int,int> b = st.top();
                if(b.first != s[i])
                {
                    a[i] = b.second;
                    st.pop();
                }
                else
                {
                    a[i] = b.second+1;
                    st.push({s[i],a[i]});
                }
            }
            else
            {
                if(s[i] == '0')
                {
                    if(o == 0)
                    {
                        a[i] = o+1;
                    }
                    else
                    {
                        a[i] = o;
                    }
                }
                else
                {
                    if(z == 0)
                    {
                        a[i] = z+1;
                    }
                    else
                    {
                        a[i] = z;
                    }
                }
                st.push({s[i],a[i]});
            }
            if(s[i] == '1')
                o = a[i];
            else 
                z = a[i];
        }
        set<int> sc;
        f(i,0,n)
            sc.insert(a[i]);
        cout<<size(sc)<<NL;
        f(i,0,n)
            cout<<a[i]<<" \n"[i == n-1];
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