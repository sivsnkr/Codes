#include<bits/stdc++.h>
using namespace std;

//Fast doubling method

// pair<int, int> fib (int n) {
//     if (n == 0)
//         return {0, 1};

//     auto p = fib(n >> 1);
//     int c = p.first * (2 * p.second - p.first);
//     int d = p.first * p.first + p.second * p.second;
//     if (n & 1)
//         return {d, c + d};
//     else
//         return {c, d};
// }

// int main(){
// 	pair<int,int> c = fib(5);
	
// 	cout<<c.first<<" "<<c.second<<endl;
// }

vector<vector<int>> matrixMul(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> c(2);
	c[0].push_back(a[0][0]*b[0][0]+a[0][1]*b[1][0]);
	c[0].push_back(a[0][0]*b[0][1]+a[0][1]*b[1][1]);
	c[1].push_back(a[1][0]*b[0][0]+a[1][1]*b[1][0]);
	c[1].push_back(a[1][0]*b[0][1]+a[1][1]*b[1][1]);
	return c;
}

vector<vector<int>> pow(vector<vector<int>> arr, int p){
	if(p == 0){
		vector<vector<int>> c;
		c.push_back({1,0});
		c.push_back({0,1});
		return c;
	}

	vector<vector<int>> res = pow(arr,p/2);
	vector<vector<int>> c;
	c = matrixMul(res,res);
	if(p%2){
		return matrixMul(c,arr);
	}
	return c;
}

int main(){g
	vector<vector<int>> c;
	c.push_back({0,1});
	c.push_back({1,1});

	int n;
	cout<<"Enter the fib no you want to find and i will find it in log(n): ";

	cin>>n;
	c = pow(c,n-1);

	cout<<c[1][0]<<endl;
	return 0;
}