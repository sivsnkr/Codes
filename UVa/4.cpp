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
    int t;
    scanf("%d", &t);
    while(t--)
    {
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        do{
            cout<<s<<nl;
        }while(next_permutation(s.begin(),s.end()));
        printf("\n");
    }

    return 0;
}