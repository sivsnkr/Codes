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
    int tc,n,k;

	scanf("%d",&tc);

	while(tc--)
    {
		scanf("%d %d",&n,&k);
		printf("%d\n", k^(k>>1));
	}
    return 0;
}