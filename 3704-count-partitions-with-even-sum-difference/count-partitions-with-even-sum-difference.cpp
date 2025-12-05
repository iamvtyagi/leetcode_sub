class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int leftSum = prefixSum[i];
            int rightSum = totalSum - leftSum; 
            int difference = leftSum - rightSum;

            if (difference % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};