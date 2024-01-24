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

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
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

    int longestLenPlaindrome(string s){
        auto setmax = [](int i, int j, bool isplaindrome, int &l, int &r, int &res)->void{
            if(isplaindrome){
                int len = j - i + 1;
                if(len > res){
                    res = len;
                    l = i, r = j;
                }
            }
        };

        int l = 0, r = 0;
        int res = 0;
        
        int n = (int)s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
        
        for(int _i = 0; _i < n; _i++){
            for(int _j = 0; _j <= _i; _j++){
                
                int j = max(_i , _j), i = min(_i , _j);
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }else if(j - 1 == i){
                    if(s[j] == s[i])
                        dp[i][j] = (s[i] == s[j]);
                    setmax(i, j, dp[i][j], l , r, res);
                    continue;
                }
                
                
                dp[i][j] = (dp[i + 1][j - 1] & (s[i] == s[j]));
                setmax(i, j, dp[i][j], l , r, res);
            }
        }
        
        // string maxlenplaindrome = "";
        // for(int i = l; i <= r; i++){
        //     maxlenplaindrome += s[i];
        // }
        
        return res;
    }

    vector<int> kmp_string_matching(string s, string p){
        vector<int> lps = kmp_preprocessing(p);
        p = "&" + p;
        int i = 0, j = 0;
        int n = s.length();
        vector<int> mat;

        while(i < n){
            if(s[i] == p[j + 1]){
                i++;
                if(j + 1 != p.length() - 1){
                    j++;
                }else {
                    mat.push_back(i - p.length() + 1);
                }
            }else {
                if(j == 0){
                    i++;
                }
                j = lps[j];
            }
        }

        return mat;
    }

    private:
    vector<int> kmp_preprocessing(string s){
        int n = s.length();
        vector<int> lps(n + 1);
        s = "&" + s;
        lps[0] = 0, lps[1] = 0;
        int li = 0, ci = 2;
        while(ci <= n){
            if(s[ci] == s[li + 1]){
                lps[ci++] = ++li;
            }else {
                if(li == 0){
                    ci++;
                }
                li = lps[li];
            }
        }

        return lps;
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
