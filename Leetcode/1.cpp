#include <bits/stdc++.h>
using namespace std;

void lshift(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int ls = 0, rs = 0;
        for (auto j : shift)
        {
            j[0] == 0 ? ls += j[1] : rs += j[1];
        }

        if (ls > rs)
        {
            int v = max(ls, rs);
            while (v > 0)
            {
                lshift(s, min(int(s.length()), v));
                v -= s.length();
            }
        }
        else
        {
            int v = max(ls, rs);
            while (v > 0)
            {
                lshift(s, s.length() - min(int(s.length()), v));
                v -= s.length();
            }
        }
        return s;
    }
};