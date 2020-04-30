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
    while (t--)
    {
        vector<string> s;
        while (true)
        {
            string temp;
            cin >> temp;
            if (temp == "\n")
                break;
            s.push_back(temp);
        }
        cout << s[32] << nl;
    }

    return 0;
}