#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // all the code goes here
    string s;cin>>s;
    // below code find plaindrome in O(n^2)
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
    cout<<maxlength<<nl;
    return 0;
}