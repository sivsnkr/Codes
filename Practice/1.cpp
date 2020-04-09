#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    int g = gcd(max(a,b),min(a,b));
        long long int res = a*b;
        res/=g;
	    cout<<g<<" "<<res<<"\n";
	}
	return 0;
}
