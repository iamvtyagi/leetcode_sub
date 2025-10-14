class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1;
        bool first = false;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                cnt++;
            } else {
                if (cnt >= 2 * k) return true;
                if (cnt >= k) first = true;
                else first = false; 
                cnt = 1;
            }

   
            if (first && cnt >= k) return true;
        }

        if (cnt >= 2 * k) return true;
        return false;
    }
};
