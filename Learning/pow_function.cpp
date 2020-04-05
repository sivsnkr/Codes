#include<bits/stdc++.h>
using namespace std;

int pow(int n,int p){
	if(p==0)
		return 1;
	int res = pow(n,p/2);
	if(p%2)
		return res*res*n;
	else
		return res*res;
}

int main(){
	int p = pow(2,3);
	cout<<p<<endl;
	return 0;
}