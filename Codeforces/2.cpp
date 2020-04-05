#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long int n,x,y;
        cin>>n>>x>>y;
        long int bestp,worstp;
        worstp = min(x-1,n-y)+min(y-1,n-x)+1;
        if(worstp>n)
            worstp = n;

        bestp = 1;
        int i = 1;
        while(x+y+1-i>n){
            bestp++;
            i++;
        }
        
        cout<<bestp<<" "<<worstp<<endl;
    }
}