#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    vector<pair<string,string>>lib;
    string s;
    getline(cin,s);
    while(s != "END")
    {
        pair<string,string> st;
        st.first = s.substr(1,find(s.begin()+1,s.end(),'"')-s.begin()-1);
        s.erase(0,st.first.length()+1);
        st.second = s.substr(4,s.size()-5);
        lib.push_back(st);
        getline(cin,s);
    }
    sort(lib.begin(),lib.end(),[](pair<string,string> a, pair<string,string> b)->bool{
        if(b.second > a.second)
        {
            return true;
        }
        else if(b.second == a.second)
            return b.first > a.first;
        return false;
    });

    

    
    return 0;
}