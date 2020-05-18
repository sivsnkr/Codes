class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        vector<int> t = A;
        t.insert(t.end(),A.begin(),A.end());
        int sum = 0;
        int mxsum = t[0];
        int n = A.size();
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            int msum = 0;
            for(int j = 0; j < n; j++)
            {
                sum+=t[j+i];
                if(sum < 0)
                    sum = 0;
                msum = max(msum,sum);
            }
            if(msum == 0)
                msum = *max_element(t.begin()+i,t.begin()+i+n);
            mxsum = max(mxsum,msum);
        }
        
        return mxsum;
    }
};