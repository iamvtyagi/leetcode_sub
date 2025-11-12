class Solution {
public:
    int shortestSubarray(vector<int>& nums){
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans;
    }
    int minOperations(vector<int>& nums) {
        int cntOne = 0;
        int n = nums.size();
        int g = nums[0];
        if(nums[0]==1)cntOne++;
        for(int i = 1;i<n;i++){
            if(nums[i]==1) cntOne++;
            g = gcd(g,nums[i]);
        }
        if(g != 1) return -1;
        if(cntOne != 0) return (nums.size()-cntOne);
        else {
            int ans = shortestSubarray(nums);
            return (ans-1) + nums.size()-1;
        }
        return -1;
    }
};