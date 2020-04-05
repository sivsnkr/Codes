#include "../../bits_stdc++.h"
using namespace std;

struct member
{
    long height;
    long inHour;
    long endHour;
};

struct joinMember
{
    long height;
    long timed;
    bool deleteIt;
    int index;
};

int main()
{
    long h, c, q;
    cin >> h >> c >> q;
    struct member members[c];
    int i;
    for (i = 0; i < c; i++)
    {
        cin >> members[i].height >> members[i].inHour >> members[i].endHour;
    }

    vector<struct joinMember> arr;

    for (i = 0; i < q; i++)
    {
        struct joinMember temp;
        cin >> temp.height >> temp.timed;
        temp.deleteIt = false;
        temp.index = i;
        arr.push_back(temp);
    }

    int result[q];
    for (i = 0; i < q; i++)
        result[i] = 1;
    int j;
    for (i = 0; i < c; i++)
    {
        long end = arr.size();
        for (j = 0; j < end; j++)
        {
            if (arr[j].timed >= members[i].inHour && arr[j].timed <= members[i].endHour)
            {
                if (arr[j].height <= members[i].height)
                    result[arr[j].index] = 0;
                arr[j].deleteIt = true;
            }
        }

        int v = 0;
        while (v < arr.size())
        {
            if (arr[v].deleteIt)
                arr.erase(arr.begin() + v);
            else
                v++;
        }
    }

    for (i = 0; i < q; i++)
    {
        if (result[i] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}