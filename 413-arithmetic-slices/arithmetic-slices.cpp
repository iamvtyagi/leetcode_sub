class Solution {
public:
    int helper(vector<int>& nums, int i, int& total) {
        if (i < 2) return 0; // need at least 3 elements

        int count = 0;
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            count = 1 + helper(nums, i-1, total); 
            total += count;  
        } else {
            helper(nums, i-1, total);
        }

        return count;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;
        helper(nums, nums.size()-1, total);
        return total;
    }
};
