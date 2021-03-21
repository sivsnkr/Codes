#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define all(a) (a).begin(), (a).end()
#define read(a)                             \
    for (int poi = 0; poi < size(a); poi++) \
    cin >> (a)[poi]
#define int long long

inline void solve()
{
    test
    {
        int n;
        cin >> n;
        vector<pair<int, int>> h(n);
        vector<int> hs(n);
        vector<int> costs, costr;
        for (int i = 0; i < n; i++)
        {
            cin >> h[i].first >> h[i].second;
            hs[i] = h[i].first;
            costs.push_back(h[i].second);
            costr.push_back(h[i].second);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (h[i].first - 1 == h[i + 1].first)
            {
                costs[i + 1] += costs[i];
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (h[i].first - 1 == h[i - 1].first)
            {
                costr[i - 1] += costr[i];
            }
        }

        int cst = 0;
        for (int i = 1; i < n; i++)
        {
            if (hs[i] == hs[i - 1])
            {
                int mi = LLONG_MAX;
                int val = hs[i];
                if (i < n - 1 && hs[i] + 2 == hs[i + 1])
                {
                    //                    if(mi > h[i].second+costr[i])
                    //                        hs[i] = hs[i + 1];
                    mi = min(mi, h[i].second + costr[i]);
                }
                else
                {
                    if (mi > 2 * h[i].second)
                        val = hs[i - 1] + 2;
                    mi = min(mi, 2 * h[i].second);
                }

                if (i < n - 1 && hs[i] + 1 == hs[i + 1])
                {
                    //                    if(mi > costr[i])
                    //                        hs[i] = hs[i+1];
                    mi = min(mi, costr[i]);
                }
                else
                {
                    //                    cout<<"i "<<i<<NL;
                    //                    cout<<hs[i]+1<<" "<<hs[i+1]<<NL;
                    if (mi > h[i].second)
                        val = hs[i - 1] + 1;
                    mi = min(mi, h[i].second);
                }

                //                cout<<"Mi "<<mi<<NL;
                if (i > 1 && hs[i - 1] + 2 == hs[i - 2])
                {
                    if (mi > h[i - 1].second + costs[i - 1])
                        val = hs[i - 1];
                    mi = min(mi, h[i - 1].second + costs[i - 1]);
                }
                else
                {
                    if (mi > 2 * h[i - 1].second)
                        val = hs[i - 1];
                    mi = min(mi, 2 * h[i - 1].second);
                }

                if (i > 1 && hs[i - 1] + 1 == hs[i - 2])
                {
                    if (mi > costs[i - 1])
                        val = hs[i - 1];
                    mi = min(mi, costs[i - 1]);
                }
                else
                {
                    if (mi > h[i - 1].second)
                        val = hs[i - 1];
                    mi = min(mi, h[i - 1].second);
                }
                hs[i] = val;

                //                cout<<"i val "<<i<<" "<<hs[i]<<NL;

                cst += mi;
            }
        }

        cout << cst << NL;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
