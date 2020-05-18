#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; scanf("%d",&t); while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

vector<int> A;
int c;
bool isvalidseq(int s, int e)
{
    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int> max_heap;

    min_heap.push(A[s]);
    min_heap.push(A[e]);
    max_heap.push(A[s]);
    max_heap.push(A[e]);

    if(min_heap.top() <= 0)
        return false;
    while (!min_heap.empty()&&!max_heap.empty())
    {
        int mi = min_heap.top();
        int mx = max_heap.top();
        max_heap.pop();
        if(mi == mx && mi == 1)
            return true;      
        if(mx-mi > 0)
        {
            min_heap.push(mx-mi);
            max_heap.push(mx-mi);
        }
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    test
    {
        c = 0;
        int n;
        scanf("%d",&n);
        f(i,0,n)
        {
            int a;
            scanf("%d",&a);
            A.push_back(a);
        }
    // cout<<isvalidseq(0,1)<<endl;
    sort(A.begin(),A.end());
    vector<int> mi;
    f(i,0,n)
    {
        f(j,i+1,n)
        {
            if(isvalidseq(i,j))
            {
                mi.push_back(j);
                c++;
                c%=mod;
            }
        }
    }

    // printf("c %d\n",c);

    while(mi.size() > 0)
    {
        vector<int> temp;
        int m = mi.size();
        f(i,0,m)
        {
            f(j,mi[i]+1,n)
            {
                temp.push_back(j);
                c++;
                c%=mod;
            }
        }
        mi = temp;
    }
    A.clear();
    printf("%d\n",c);
    }
    return 0;
}