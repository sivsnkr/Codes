#include<iostream>
#include<vector>
using namespace std;

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
int main()
{
    string s = "M 1 2";
    vector<string> splited_string = split(s,',');
    for(string s : splited_string)
        cout<<s<<" ";
    cout<<endl;
}