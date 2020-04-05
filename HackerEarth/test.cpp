#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool res(ll value, int k)
{
    long int vCopy = value;
    vCopy %= 60;
    while (vCopy > k)
    {
        // tom's turn
        int j;
        bool flag = false, flag1 = false;
        if (vCopy <= k)
            return true;
        for (j = k; j >= 1; j--)
        {
            if (vCopy - j > k)
            {
                flag = true;
                vCopy -= j;
                break;
            }
        }

        if (!flag)
            return false;

        // jerry's turn
        if (vCopy <= k)
            return false;
        for (j = k; j >= 1; j--)
        {
            if (vCopy - j > k)
            {
                flag1 = true;
                vCopy -= j;
                break;
            }
        }
        // cout << vCopy << endl;
        if (!flag1)
            return true;
    }
}

int main()
{
    int q, k;
    cin >> q >> k;
    list<long long int> arr;
    unordered_map<int, ll> newValuetoPlus;
    unordered_map<int, ll> newValue;

    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        // cout << "val " + op << endl;
        if (op == "AL")
        {
            long long int value;
            list<ll>::iterator it;
            int counter = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValuetoPlus.find(counter) != newValuetoPlus.end())
                {
                    *it += newValuetoPlus[counter];
                }
                counter++;
            }
            newValuetoPlus.clear();
            counter = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValue.find(counter) != newValue.end())
                {
                    *it = newValue[counter];
                }
                counter++;
            }
            newValue.clear();
            cin >> value;
            arr.push_front(value);
        }
        else if (op == "AR")
        {
            list<ll>::iterator it;
            int counter = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValuetoPlus.find(counter) != newValuetoPlus.end())
                {
                    *it += newValuetoPlus[counter];
                }
                counter++;
            }
            newValuetoPlus.clear();
            counter = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValue.find(counter) != newValue.end())
                {
                    *it = newValue[counter];
                }
                counter++;
            }
            newValue.clear();
            long long int value;
            cin >> value;
            arr.push_back(value);
        }
        else if (op == "UR")
        {
            int l, r;
            cin >> l >> r;
            long long int x;
            cin >> x;

            for (int j = l - 1; j < r; j++)
            {
                if (newValuetoPlus.find(j - 1) == newValuetoPlus.end())
                {
                    newValuetoPlus.insert(make_pair(j, x));
                }
                else
                {
                    newValuetoPlus[j] += x;
                }
            }
        }
        else if (op == "UP")
        {
            int i;
            cin >> i;
            long long int x;
            cin >> x;
            if (newValue.find(i - 1) == newValue.end())
            {
                newValue.insert(make_pair(i - 1, x));
            }
            else
            {
                newValue[i - 1] = x;
            }
        }
        else if (op == "Q1")
        {
            // logic for q1
            int l, r;
            cin >> l >> r;
            int counter = 0;
            list<ll>::iterator it;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValuetoPlus.find(counter) != newValuetoPlus.end())
                {
                    *it += newValuetoPlus[counter];
                }
                counter++;
            }
            newValuetoPlus.clear();
            counter = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValue.find(counter) != newValue.end())
                {
                    *it = newValue[counter];
                }
                counter++;
            }
            newValue.clear();

            counter = 0;
            int index = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                // cout << *it << " ";
                if (index >= l - 1 && index < r)
                {
                    ll value = *it;
                    // cout << "Value: " << value << endl;
                    if (res(value, k))
                    {
                        counter++;
                    }
                }
                index++;
            }
            // cout << endl;
            cout << counter << endl;
        }
        else
        {
            // logic for q2
            int l, r;
            cin >> l >> r;
            long long int sum = 0;
            int index = 0;
            list<ll>::iterator it;
            int counter = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValuetoPlus.find(counter) != newValuetoPlus.end())
                {
                    *it += newValuetoPlus[counter];
                }
                counter++;
            }
            newValuetoPlus.clear();
            counter = 0;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (newValue.find(counter) != newValue.end())
                {
                    *it = newValue[counter];
                }
                counter++;
            }
            newValue.clear();
            for (it = arr.begin(); it != arr.end(); it++)
            {
                // cout << *it << " ";
                if (index >= l - 1 && index < r)
                {
                    sum += *it;
                }
                index++;
            }
            // cout << endl;
            // if ((sum / 10) % 2 == 0)
            // {
            //     cout << "Tom"
            // }
            res(sum, k) ? cout << "Tom" : cout << "Jerry";
            cout << endl;
        }
    }
}