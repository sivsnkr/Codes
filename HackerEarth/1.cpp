#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;

    for(int i = 0; i < q; i++){
        int ino;
        cin>>ino;

        switch(ino){
            case 1:
                char q;
                cin>>q;
                s+=q;
                break;
            case 2:{
                // do something
                int x,y;
                cin>>x>>y;
                x--,y--;
                char ctof = s[0];

                int j;
                int l1 = 0,l2 = 0;
                int index = -1;
                for(j = x; j > 0; j--){
                    if(s[j]==ctof)
                        index = j;
                }
                if(index == -1){
                    cout<<0<<endl;
                    break;
                }

                int k = index;
                j = 0;

                // cout<<"k "<<k<<endl;
                // cout<<"--------"<<endl;

                // cout<<k<<" "<<y<<endl;

                while(k<y&&s[k]==s[j]){
                    // cout<<"fsdfs"<<endl;
                    l1++;
                    j++;
                    k++;
                }

                index = -1;

                for(j = y; j > x; j--){
                    if(s[j] == ctof)
                        index = j;
                }

                if(index == -1){
                    cout<<0<<endl;
                    break;
                }

                k = index;
                j = 0;

                // cout<<"k1 "<<k<<endl;
                while(k<s.length()&&s[k]==s[j]){
                    l2++;
                    j++;
                    k++;
                }

                // cout<<l1<<" "<<l2<<endl;

                cout<<min(l2,l1)<<endl;
                break;
            }
            default:{
                int p,l,r;
                cin>>p>>l>>r;
                l--,r--,p--;
                int index = l;

                int counter = 0;
                int j = 0;

                bool started = false;
                while(index<=r){
                    if(s[j] == s[index]){
                        if(j == 0){
                            started = true;                        }
                        j = (j+1)%(p+1);
                        if(j == 0)
                            counter++;
                    }else if(started){
                        j = 0;
                        started = false;
                    }
                    index++;
                }
                cout<<counter<<endl;
            }
        }
    }

}