#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n, k;
    cin >> n >> k;
    vector<long int> ele(n);

    int i;
    for (i = 0; i < n; i++)
    {
        cin >> ele.at(i);
    }

    int length = 1;
    int start = 0;
    int maxLength = length;
    priority_queue<long int> maxValues;
    long int maxV = ele.at(0);
    maxValues.push(maxV);
    long long int sum = ele.at(0);
    for (i = 1; i < n; i++)
    {
        sum += ele.at(i);
        length++;

        if (ele.at(i) > maxV)
        {
            maxV = ele.at(i);
        }
        else
            maxValues.push(ele.at(i));

        if (maxV * length - sum <= k)
        {
            if (maxLength < length)
            {
                maxLength = length;
            }
        }
        else
        {
            while (maxV * length - sum > k)
            {
                length--;
                sum -= ele.at(start);
                if (ele.at(start) == maxV)
                {
                    maxValues.pop();
                    maxV = maxValues.top();
                }
                start++;
            }
            maxLength = max(maxLength, length);
        }
    }
    cout << max(maxLength, length) << endl;
}