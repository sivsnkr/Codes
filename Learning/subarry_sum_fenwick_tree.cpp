#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long L;
const char NL = '\n';
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define all(a) a.begin(),a.end()

class FenwickTree
{
    private:
    vector<int> ft;
    int n;
    int rsq(int index);
    int LSOne(int b){return b&(-b);}
    public:
    FenwickTree(int size)
    {
        n = size;
        ft.assign(n+1,0);
    }
    void print();
    int rsq(int a, int b){return rsq(b)-(a == 0?0:rsq(a-1));}
    void update(int index, int value);
};

int FenwickTree::rsq(int index)
{
    int sum = 0;
    for(int i = index; i > 0; i-=LSOne(i))
        sum+=ft[i];
    return sum;
}

void FenwickTree::update(int index, int value)
{
    for(int i = index; i <= n; i+=LSOne(i))
    {
        ft[i]+=value;
    }
    return;
}

void FenwickTree::print()
{
    for(int i = 0; i < n; i++)
        cout<<ft[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int f[] = { 2,4,5,5,6,6,6,7,7,8,9 };
    FenwickTree ft(11);
    for (int i = 0; i < 11; i++) 
    {
        ft.update(i+1,f[i]);
    }
    // ft.print();
    printf("sum %d\n",ft.rsq(0,2));
    return 0;
}