#include <bits/stdc++.h>
using namespace std;

int get_result(vector<int> v[], unordered_set<int> &dir_to_d, int size)
{
    int counter = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (v[i].size() > 0 && dir_to_d.find(v[i].front()) != dir_to_d.end())
        {
            counter++;
            dir_to_d.erase(v[i].front());
            int j;
            for (j = 1; j < v[i].size(); j++)
            {
                if (dir_to_d.find(v[i].at(j)) != dir_to_d.end())
                    dir_to_d.erase(v[i].at(j));
            }
        }
        if (dir_to_d.size() == 0)
            break;
    }
    return counter;
}

int main()
{
    int n;
    cin >> n;
    vector<int> graph[n];
    int i;
    cin >> i;
    for (i = 0; i < n - 1; i++)
    {
        int value;
        cin >> value;
        if (graph[i + 1].size() == 0)
        {
            graph[i + 1].push_back(i + 1);
        }
        graph[value - 1].push_back(i + 1);
    }

    unordered_set<int> dir_to_d;
    int q;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        int value;
        cin >> value;
        dir_to_d.insert(value - 1);
    }
    int res = get_result(graph, dir_to_d, n);
    cout << res << endl;
}