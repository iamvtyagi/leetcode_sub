class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int x : nums) {
            // Find first element > x
            int idx = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            int greaterCount = n - idx;

            if (greaterCount >= k)
                ans++;
        }
        return ans;
    }
};