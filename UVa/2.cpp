#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int nfp(string s)
{
    string t = "#";
    set<char> st;
    set<string> st1;
    for(char a : s)
    {
        t+=a;
        t+='#';
        st.insert(a);
    }
    // cout<<t<<nl;
    int n = t.length();
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int r = i+1,l = i-1;
        string s1 = "";
        while(l >= 0&& r< n&&t[r] == t[l])
        {
            if(t[r] != '#')
            {
                s1+=t[r];
                string s2 = s1;
                reverse(s2.begin(),s2.end());
                // cout<<s2<<" "<<s1<<nl;
                if(t[i] != '#')
                    s2+=t[i];
                // cout<<s2<<nl;
                // cout<<s2<<" "<<s1<<nl;
                s2+=s1;
                // cout<<s2<<nl;
                // cout<<s2<<" "<<s1<<" "<<t[i]<<nl;
                st1.insert(s2);
            }
            l--,r++;
        }
    }
    // for(string s : st1)
    // {
    //     cout<<s<<nl;
    // }
    return int(st.size())+int(st1.size());    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    string s;
    while(cin>>s)
    {
        int n = nfp(s);
        cout<<"The string "<<"'"<<s<<"'"<<" contains "<<n<<" palindromes."<<nl;
    }
    return 0;
}