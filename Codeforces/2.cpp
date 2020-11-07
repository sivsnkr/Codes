#include<iostream>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	int t,n,d,m,i;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		d=1, m=0;
		for(i=1; i<(int) s.length(); i++){
			if(s[i-1] !=s[i]) d++;
			else m++;
			m=min(m, d);
		}
		m +=(d-m+1)/2;
		cout<<m<<endl;
	}
}