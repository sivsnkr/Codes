#include<bits/stdc++.h>
using namespace std;
long long c,d,i,n,k,j;
pair<int,int>a[100005];
int main(){
cin>>n>>d;
for(i=0;i<n;i++)cin>>a[i].first>>a[i].second;
sort(a,a+n);
for(i=0;i<n;i++){
if(a[i].first-a[j].first<d){k+=a[i].second;c=max(c,k);}else{
k-=a[j++].second;i--;
}
}
cout<<c;
}