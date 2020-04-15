#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;cin>>n>>k;
    bool q[n];
    for(int i = 0; i < n-k+1; i++)
    {
        string c;cin>>c;
        q[i] = c=="YES"?1:0;
        
    }

    string s = "A";
    char st = 'A';
    vector<string> ans(n,"");
    ans[0] = s;
    int ls = -1;
    for(int i = 0; i < n-k+1; i++)
    {
        if(q[i])
        {
            for(int j = 0; j < k; j++)
            {
                string te = "a";
                    // cout<<s<<"\n";
                    if((s+te).length() > 10)
                    {
                        st++;
                        string tle(1,st);
                        s = tle;
                    }else
                    {
                        s = s+te;
                    }
                    
                    ans[i+j] = s;
            }
            ls = i;
        }
        else
        {
            for(int j = 1; j < k; j++)
            {
                if(ans[i+j].length()==0)
                    ans[i+j] = ans[i+j-1];
            }
        }
    }

    for(int i = 0; i < ls; i++){
        if(!q[i])
        {
            ans[i] = ans[i+1];
        }
    }

    for(string s : ans)
    {
        cout<<s<<" ";
    }
    cout<<"\n";
    return 0;
}