class Solution {
public:
    int dp[40001][3];
    int func(int i, int sum, vector<int> &nums){
        int n = nums.size();
        if(i==n){
            if(sum%3==0) return 0;
            return -1e9;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int maxi = func(i+1,sum,nums);
        maxi = max(maxi,nums[i]+func(i+1,(sum+nums[i])%3,nums));
        return dp[i][sum] = maxi;
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return func(0,0,nums);
    }
};