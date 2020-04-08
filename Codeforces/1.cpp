#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());

    int a = s.find("AB"), b = s.length() - s1.find("AB") - 1;
    if ((a > b + 2 || b > a + 2) && (a < s.length() && b < s.length()))
    {
        cout << "YES";
    }
    else
    {
        a = s.find("BA"), b = s.length() - s1.find("BA") - 1;
        if ((a > b + 2 || b > a + 2) && (a < s.length() && b < s.length()))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    cout << "\n";
}