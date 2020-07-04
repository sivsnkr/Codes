#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int T; cin>>T;
  while (T--){
    int N,X;
    cin>>N>>X;
    int far=0; //largest favorite number
    bool print = 1;
    for (int i=0;i<N;i++){
      int A;
      cin>>A;
      if(A == X)
        {
            cout<<1<<endl;
            print = 0;
        }
      far=max(far,A);
    }
    if(print)
      cout<<max(2,(X+far-1)/far)<<endl; //expression as explained in tutorial
  }
}