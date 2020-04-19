#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        multiset<char> st;
        for (char a : s)
        {
            st.insert(a);
        }
        int c1 = st.count('A'), c2 = st.count('B');
        int c3 = 0;
        for (int j = 0; j < int(s.length()); j++)
        {
            if (s[j] != *st.begin())
            {
                c3++;
            }
            st.erase(st.begin());
        }

        int mi = min({c1, c2, c3});
        cout << mi << "\n";
    }

    return 0;
}