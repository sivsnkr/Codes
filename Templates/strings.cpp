#include <bits/stdc++.h>
using namespace std;
const char NL = '\n';
#define test int t;cin >> t;while (t--)
#define all(a) a.begin(), a.end()
#define int long long
void read(vector<int> &a);

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

    int max_len_plain(string s)
    {
        string as = "";
        for(char a : s)
        {
            as+=a;
            as+='#';
        }

        int n = as.length();
        int maxlength = 0;
        for(int i = 0; i < n; i++)
        {
            int j = i-1,k = i+1;
            int count = 0;
            while(j>=0&&k<n)
            {
                if(as[j] == as[k] && as[j] != '#')
                {
                    count+=2;
                }
                else if(as[j] != '#')
                    break;
                j--,k++;
            }
            if(as[i] != '#')
                count++;
            maxlength = max(maxlength,count);
        }
        return maxlength;
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
        reverse(all(res));
        return res;
    }
};

inline void solve()
{
    // all the code goes here
    class Strings st;
    string s,t;cin>>s>>t;
    cout<<st.LCS_string(s,t)<<NL;
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

void read(vector<int> &a)
{
    for(auto &it : a)cin>>it;
}