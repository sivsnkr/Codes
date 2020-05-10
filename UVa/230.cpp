#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

void borrow(string s,vector<pair<string,string>> lib,vector<int> &vacpos)
{
    auto cmp = [&](pair<string,string> a){
        return a.first == s;
    };
    vacpos.push_back(lib.erase(find_if(lib.begin(),lib.end(),cmp))-lib.begin());
}

void custret(vector<pair<string,string>> &desk,string book,unordered_map<string,string> &bok_auth)
{
    desk.push_back({book,bok_auth[book]});
}

void customsort(vector<pair<string,string>> &lib)
{
    sort(lib.begin(),lib.end(),[](pair<string,string> a, pair<string,string> b)->bool{
        if(b.second > a.second)
        {
            return true;
        }
        else if(b.second == a.second)
            return b.first > a.first;
        return false;
    });
}

void shelve(vector<pair<string,string>> &lib,vector<pair<string,string>> &desk,vector<int> &vacpos)
{
    customsort(desk);
    sort(vacpos.begin(),vacpos.end());
    int n = vacpos.size();
    int desksize = desk.size();
    for(int i = 0; i < n && i < desksize; i++)
    {
        if(vacpos[i] != 0)
        {
            cout<<"Put "<<"\""<<desk[i].first<<"\""<<" after "<<"\""<<lib[vacpos[i]-1].first<<"\""<<nl;
            lib.insert(lib.begin()+vacpos[i],desk[i]);
        }
    }

    for(int i = 0; i < desksize; i++)
        vacpos.erase(vacpos.begin());
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    vector<pair<string,string>>lib;
    unordered_map<string,string> bok_auth;
    string s;
    getline(cin,s);
    while(s != "END")
    {
        pair<string,string> st;
        st.first = s.substr(1,find(s.begin()+1,s.end(),'"')-s.begin()-1);
        s.erase(0,st.first.length()+1);
        st.second = s.substr(4,s.size()-5);
        lib.push_back(st);
        bok_auth[st.first] = st.second;
        getline(cin,s);
    }
    vector<int> vacpos;
    vector<pair<string,string>> desk;
    getline(cin,s);
    while(s != "END")
    {
        string cmd = s.substr(0,find(s.begin(),s.end(),' ')-s.begin());
        if(cmd == "BORROW")
        {
            string bok = s.substr(cmd.length()+2,s.length()-cmd.length()-3);
            borrow(bok,lib,vacpos);
        }
        else if(cmd == "RETURN")
        {
            string bok = s.substr(cmd.length()+2,s.length()-cmd.length()-3);
            custret(desk,bok,bok_auth);
        }
        else
        {
            shelve(lib,desk,vacpos);
            cout<<"END"<<nl;
        }
        
        getline(cin,s);
    }
    return 0;
}