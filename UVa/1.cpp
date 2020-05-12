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
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(10);
    q.push(9);
    printf("%d\n",q.top());
    return 0;
}