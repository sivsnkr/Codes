#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string a, string b) {
        int l1 = -1,l2 = -1;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != '#')
            {
                a[++l1] = a[i];
            }
            else
            {
                if(l1-1 >= -1)
                    l1--;
            }
        }

        for(int i = 0; i < b.length(); i++)
        {
            if(b[i] != '#')
            {
                b[++l2] = b[i];
            }
            else
            {
                if(l2-1 >= -1)
                    l2--;
            }
        }

        // cout<<l1<<" "<<l2<<"\n";
        bool isvalid = true;
        if(l1 != l2)
            isvalid = false;
        else
        {
            for(int i = 0; i <= l1; i++)
            {
                if(a[i] != b[i])
                {
                    isvalid = false;
                    break;
                }
            }
        }

        return isvalid;
    }
};

int main()
{
    Solution s;
    string a,b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
    cout<<s.backspaceCompare(a,b)<<"\n";
}

// "xywrrmp"
// "xywrrmu#p"