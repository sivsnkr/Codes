#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int h, w;
    cin >> h >> w;
    const int modulo = 1000000007;
    vector<vector<char>> grid(h, vector<char>(w));

    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            grid[i][j] = s[j];
        }
    }

    int dp[h][w];
    memset(dp, 0, sizeof(dp));
    if (grid[0][1] == '.')
        dp[0][1] = 1;
    if (grid[1][0] == '.')
        dp[1][0] = 1;
    for (int i =     0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if ((i != 0 || j != 0) && grid[i][j] == '.')
            {
                int a = 0, b = 0;
                if (i - 1 >= 0)
                    a = dp[i - 1][j];
                if (j - 1 >= 0)
                    b = dp[i][j - 1];
                dp[i][j] = max(dp[i][j], (a + b) % modulo);
            }
        }
    }

    cout << dp[h - 1][w - 1] << "\n";
    return 0;
}