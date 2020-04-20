#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // all the code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n,0),b(n,0);
        int su = 0;
        for(int i = n-1; i >=0; i--)
        {
            if(s[i] == 'A')
                su++;
            a[i] = su;
        }

        int sum = 0;
        int noofb = 0;
        int in = 0;
        for(int i = 0; i < n; i++)
        {
            // cout<<noofb<<"\n";
            // if(s[i] > s[i+1])
            // {
                
            //     if(noofb+1 > a[i])
            //     {
            //         s[i+1] = 'B';
            //     }
            //     else
            //     {
            //         // cout<<noofb<<" "<<a[i]<<"\n";
            //         s[i] = 'A';
            //         a[i]++;
            //         if(i-1 >= 0)
            //             a[i-1]++;
            //         if(i-2 >= -1)
            //             i-=2;
            //     }
            //     sum++;
            // }
            // if(s[i] == 'B')
            //     noofb++;
            // if(noofb+1 != a[i])
            //     sum = max(sum,min(noofb+1,a[i]));
            // if(s[i] == 'B')
            //     noofb++;
            if(s[i] == 'B')
            {
                if(noofb+1 < a[i])
                {
                    sum++;
                    s[i] = 'A';
                }
                // sum = min(noofb+1,a[i]);
                // sum = max(sum,min(noofb+1,a[i]));
            }
            else
            {
                if(noofb > a[i] || (noofb == a[i] && noofb!=0))
                {
                    sum++;
                    s[i] = 'B';
                    noofb++;
                }
                // sum = min(noofb,a[i]);
                // sum = max(sum,min(noofb,a[i]));
            }
        }
        cout<<s<<"\n";
        cout<<sum<<"\n";
    }

    return 0;
}