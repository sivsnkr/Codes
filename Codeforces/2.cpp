#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define PI 3.14159265
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define testf        \
    int t;           \
    scanf("%d", &t); \
    while (t--)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define mod 1000000007
#define all(a) a.begin(), a.end()
#define size(container) (int)container.size()
#define int long long int
int n;
string s;
vector<int> a(51);
void solve()
{
    test
    {
        cin >> s;
        cin >> n;
        f(i, 0, n) cin >> a[i];
        priority_queue<char> pq;
        multiset<char> st;
        f(i, 0, s.length())
        {
            pq.push(s[i]);
            st.insert(s[i]);
        }
        char t[n + 1];
        vector<bool> v(n,0);
        f(k, 0, n)
        {
            int cz = 0;
            f(i,0,n)
            {
                if(a[i] == 0 && !v[i])
                    cz++;
            }
            while(st.count(pq.top()) < cz && !pq.empty())
            {
                pq.pop();
            }
            st.erase(pq.top());
            vector<int> temp = a;
            f(i,0,n)
            {
                if(a[i] == 0 && !v[i] && !pq.empty())
                {
                    t[i] = pq.top();
                    pq.pop();
                    v[i] = 1;
                    f(j,0,n)
                    {
                        int sub = temp[j]-abs(i-j);
                        if(sub >= 0 && !v[j])
                        {
                            temp[j] = sub;
                        }
                    }
                }
            }
            f(i,0,n)
                a[i] = temp[i];
        }
        f(i, 0, n)
            cout<<t[i];
        cout << NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // clock_t st = clock();
    // all the code goes here
    solve();
    // cout<<"Time taken "<<((float)clock()-st)/CLOCKS_PER_SEC<<endl;
    fflush(stdin);
    fflush(stdout);
    return 0;
}