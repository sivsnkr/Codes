/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int a : stones)
        {
            q.push(a);
        }
        while(q.size() > 1)
        {
            int f = q.top();
            q.pop();
            int s = q.top();
            q.pop();
            if(f != s)
                q.push(max(f,s)-min(f,s));
        }
        if(q.empty())
            return 0;
        return q.top();
    }
};
int main()
{
    Solution s;
    vector<int> v{2,7,4,1,8,1};
    cout<<s.lastStoneWeight(v)<<"\n";
}