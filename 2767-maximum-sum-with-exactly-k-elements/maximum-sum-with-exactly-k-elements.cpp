class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        int el = INT_MIN;
        int sum = 0;
        for(int i = 0;i<n;i++){
            el = max(el,nums[i]);
        }
        for(int i = 1;i<=k;i++){
             sum += el++;
        }
        return sum;
    }
};