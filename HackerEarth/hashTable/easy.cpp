#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string jaadu;
        string jhool;

        cin >> jhool >> jaadu;

        int arrJd[26] = {0};
        int arrJh[26] = {0};
        int flag = 0;

        int j;

        for (j = 0; j < jhool.length(); j++)
        {
            arrJh[jhool[j] - 97]++;
        }

        for (j = 0; j < jaadu.length(); j++)
        {
            arrJd[jaadu[j] - 97] += (arrJh[jaadu[j] - 97] + 1);
        }

        for (j = 0; j < 26; j++)
        {
            if (arrJd[j] > arrJh[j] && arrJh[j] != 0)
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
        }

        if (flag != 1)
        {
            cout << "NO" << endl;
        }
    }
}