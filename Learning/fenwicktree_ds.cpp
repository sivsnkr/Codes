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

class Fenwicktree
{
    private:
    vector<int> ft;
    int n;
    int rsq(int n);
    int LSOne(int b){return b&(-b);}
    public:
    Fenwicktree(int value)
    {
        n = value;
        ft.assign(n+1,0);
    }
    int rsq(int a, int b);
    void update(int value, int k);
};

int Fenwicktree::rsq(int n)
{
    int sum = 0;
    for(;n; n-=LSOne(n))
        sum+=ft[n];
    return sum;
}

int Fenwicktree::rsq(int a, int b)
{
    return rsq(b)-(a==1?0:rsq(a-1));
}

void Fenwicktree::update(int value, int k)
{
    for(;value <= n; value+=LSOne(value))
        ft[value]+=k;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // all the code goes here
    int f[] = { 2,4,5,5,6,6,6,7,7,8,9 };
    Fenwicktree ft(10);
    for (int i = 0; i < 11; i++) 
        ft.update(f[i], 1);
    printf("%d\n", ft.rsq(1, 1));
    printf("%d\n", ft.rsq(1, 2));
    printf("%d\n", ft.rsq(1, 6)); 
    printf("%d\n", ft.rsq(1, 10)); 
    printf("%d\n", ft.rsq(3, 6)); 
    ft.update(5, 2); 
    printf("%d\n", ft.rsq(1, 10));
    return 0;
}