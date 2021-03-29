#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define test int t;cin >> t;while (t--)
#define all(a) (a).begin(), (a).end()
#define read(a) for(int poi = 0; poi < size(a); poi++)cin>>(a)[poi]
#define size(a) (int)(a).size()

inline void solve()
{
    int t,n,q;cin>>t>>n>>q;
    while(t--){
        vector<int> res;
        cout<<1<<" "<<2<<" "<<3<<endl;
        vector<int> mids{1,2,3};
        int mid;cin>>mid;
        mids.erase(find(all(mids),mid));
        res.push_back(mids[0]);
        res.push_back(mid);
        res.push_back(mids[1]);
        set<int> st;
        for(int i = 4; i <= n; i++)
            st.insert(i);
        for(int i = 1; i < n; i++){
            int sz = size(res);
            if(sz == n)
                break;
            int ind = *st.begin();
            st.erase(st.begin());
            cout<<res[sz-2]<<" "<<res[sz-1]<<" "<<ind<<endl;
            int mid;cin>>mid;
            if(mid == ind){
                res.insert(res.begin()+sz-1,mid);
            }else{
                if(mid == res[sz-1]){
                    res.push_back(ind);
                }else{
                    bool ins = 0;
                    int l = 0,r = sz-2;
                    while(r-l > 1){
                        int mid = (l+r)/2;
                        cout<<res[l]<<" "<<res[mid]<<" "<<ind<<endl;
                        int val;cin>>val;
                        if(val == ind){
                            r = mid;
                        }else{
                            l = mid;
                        }
                    }

                    cout<<res[l]<<" "<<res[r]<<" "<<ind<<endl;
                    int val;cin>>val;
                    if(val == ind){
                        ins = 1;
                        res.insert(res.begin()+r,ind);
                    }



                    if(!ins)
                        res.insert(res.begin(),ind);
                }
            }
        }

        for(int i = 0; i < size(res); i++)
            cout<<res[i]<<" ";
        cout<<endl;
        int valid;cin>>valid;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    solve();
    fflush(stdin);
    fflush(stdout);
    return 0;
}
