#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0,sum = 0;
        int n = nums.size();

        pair<int,int> s[n];
        for(int i = 0; i < n; i++)
        {
            sum+=nums[i];
            s[i] = {sum,i};
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(s[j].first-s[i].first+nums[s[i].second] == k)
                    count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1,1,1};
    int re = s.subarraySum(nums,2);
    cout<<re<<"\n";
}