// programe to remove leading zeros from and integer string
#include<bits/stdc++.h>
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
};

int main()
{
    class Strings st;
    cout<<st.max_len_plain("shivshankarmadam")<<endl;
}