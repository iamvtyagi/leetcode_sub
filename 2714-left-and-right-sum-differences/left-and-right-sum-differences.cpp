class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n),pre(n),suff(n);
        pre[0]=0;
        for(int i=1; i<n; i++)
        {
          pre[i]=nums[i-1]+pre[i-1];
        }
        suff[n-1]=0;
        for(int i=n-2; i>=0; i--)
        {
        suff[i]=nums[i+1]+suff[i+1];
        }
        for(int i=0; i<n; i++)
        {
            ans[i]=abs(pre[i]-suff[i]);
        }

        return ans;
        
    }
};