class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int orr = nums[i];
            for (int j = i; j < n; j++) {
                orr |= nums[j];
                if (orr >= k) {
                    mini = min(mini, j - i + 1);
                }
            }
        }
        if (mini == INT_MAX)
            return -1;
        return mini;
    }
};