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
//#define size(container) (int)container.size()
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

//bool is_plain(string s)
//{
//    int st = 0,e = s.length()-1;
//    while(st < e)
//    {
//        if(s[st] != s[e])
//            return false;
//        st++,e--;
//    }
//    return true;
//}

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
};

//string find_l(string s)
//{
//    int n = s.length();
//    string res = "";
//    f(i,1,n+1)
//    {
//        string tmp = s.substr(0,i);
//        if(is_plain(tmp))
//        {
//            if(tmp.length() > res.length())
//                res = tmp;
//        }
//    }
//    return res;
//}
void solve()
{
    // fh;// comment this line before submitting to online judge
    // all the code goes here
    class Strings str;
    test
    {
        string s;cin>>s;
        string f = "",b = "";
        int st = 0,e = s.length()-1;
        int n = s.length();
        while(st <= e)
        {
            if(st == e)
            {
                f+=s[st];
                break;
            }
            if(s[st] == s[e])
            {
                f+=s[st],b+=s[e];
            }
            else
                break;
            st++,e--;
        }
        reverse(all(b));
        if(st < e)
        {
            // cout<<f<<" "<<b<<NL;
//            string res1 = find_l(s.substr(st,abs(e-st)+1));
            string tmp = s.substr(st,abs(e-st)+1);
//            reverse(all(tmp));
//            string res2 = find_l(tmp);
            // cout<<res1<<" "<<res2<<NL;
//            cout<<"tmp "<<tmp<<NL;
            auto [d1,d2] = str.all_plaindromes(tmp);
//            for(int i : d1)
//                cout<<i<<" ";
//            cout<<NL;
//            for(int i : d2)
//                cout<<i<<" ";
//            cout<<NL;
            int r = tmp.length()-1;
            int val = -1;
            for(int i = tmp.length()-1; i >= 0; i--){
                int le = d1[i];
                if(i+le == tmp.length()){
                    if(val < 2*d1[i]-1){
                        val = 2*d1[i]-1;
                        r = tmp.length()-1;
                    }
                }else if(i-le < 0){
                    if(val < 2*d1[i]-1){
                        val = 2*d1[i]-1;
                        r = -1;
                    }
                }
            }

//            cout<<"l r "<<l<<" "<<r<<NL;
            for(int i = tmp.length()-1; i >= 0; i--){
                int le = d2[i];
                if(i + le == tmp.length()){
//                    cout<<"val "<<val<<NL;
                    if(val < 2*d2[i]){
                        val = 2*d2[i];
                        r = tmp.length()-1;
                    }
                }else if(i-le == 0) {
                    if(val < 2*d2[i]){
                        val = 2*d2[i];
                        r = -1;
                    }
                }
            }

            string res = f;
            if(r == -1){
                for(int l = 1; l <= val; l++){
                    res += tmp[l-1];
                }
            }else{
                reverse(all(tmp));
                string te = "";
                for(int l = 1; l <= val; l++){
                    te += tmp[l-1];
                }
                reverse(all(te));
                res += te;
            }

            cout<<res+b<<NL;
//            if(res1.length() >= res2.length())
//            {
//                cout<<f+res1+b<<NL;
//            }
//            else
//            {
//                reverse(all(res2));
//                cout<<f+res2+b<<NL;
//            }
        }
        else
            cout<<f+b<<NL;
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