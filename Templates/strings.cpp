#include <bits/stdc++.h>
using namespace std;

class Strings
{
    public:
    string remove_leading_zeros(string s)
    {
        string res = "0";
        int c = 0;
        while(s[c] == '0')
        {
            c++;
        }

        if(c < s.size())
        {
            res = s.substr(c,s.size()-c);
        }
        return res;
    }

    vector<string> split(string s,char a)
    {
        int j = 0;
        int n = s.length();
        vector<string> res;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == a)
            {
                res.push_back(s.substr(j,i-j));
                j = i+1;
            }
        }
        res.push_back(s.substr(j,n-j));
        return res;
    }

    pair<vector<int>,vector<int>> all_plaindromes(string s)
    {
        // manacher's algorithm
        // calculate all plaindromes in string of length L, in O(L)
        // time
        int n = s.length();
        vector<int> d1(n),d2(n);
        for(int i = 0,l = 0,r = -1; i < n; i++)
        {
            int k = (i > r) ? 1 : min(d1[l+r-i],r-i+1);
            while(i-k >= 0 && i + k < n && s[i-k] == s[i+k])
                k++;
            d1[i] = k--;
            if(i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }

        for(int i = 0,l = 0,r = -1; i < n; i++)
        {
            int k = (i > r) ? 0 : min(d1[l+r-i+1],r-i+1);
            while(i-k-1 >= 0 && i + k < n && s[i-k-1] == s[i+k])
                k++;
            d2[i] = k--;
            if(i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }
        }

        return {d1,d2};
    }

    int LCS_length(string s,string t)
    {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int res = 0;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i < n && j < m && s[i] == t[j])
                {
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                }
                if(i+1 <= n)
                    dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                if(j+1 <= m)
                    dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
                res = max(dp[i][j],res);
            }
        }

        return res;
    }

    string LCS_string(string s,string t)
    {
        int n = s.length(),m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<vector<tuple<char,int,int>>> backtrack(n+1,vector<tuple<char,int,int>>(m+1,{'*',-1,-1}));
    
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i] == t[j])
                {
                    if(dp[i][j]+1 > dp[i+1][j+1])
                    {
                        backtrack[i+1][j+1] = {s[i],i,j};
                    }
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                }
                if(dp[i][j] > dp[i][j+1])
                    backtrack[i][j+1] = backtrack[i][j];
                dp[i][j+1] = max(dp[i][j],dp[i][j+1]);
                if(dp[i][j] > dp[i+1][j])
                    backtrack[i+1][j] = backtrack[i][j];
                dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
            }
        }
        
        int mx = 0;
        pair<int,int> in = {0,0};
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(dp[i][j] > mx)
                {
                    mx = dp[i][j];
                    in = {i,j};
                }
            }
        }
        string res = "";
        while(true)
        {
            auto [s,i,j] = backtrack[in.first][in.second];
            if(i < 0 || j < 0)
                break;
            res+=s;
            in = {i,j};
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

inline void solve()
{
    // all the code goes here
    class Strings st;
    auto [d1,d2] = st.all_plaindromes("abaaraa");
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
