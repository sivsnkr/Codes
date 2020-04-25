#include<iostream>
using namespace std;
int i,a[200],s=100001,t,n,k=0;
char c[100000];
int main(){
    cin>>n>>c;
    for(i=0;i<n;i++){
        a[c[i]]++; t=a[c[i]];
        while(a[c[k]]>1) 
            a[c[k++]]--;
        if(t==1) 
            s=i-k+1;
        else 
            s=min(s,i-k+1);
    }
    cout<<s<<endl;
    return 0;
}