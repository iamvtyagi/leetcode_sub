class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> criticalpts;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                criticalpts.push_back(i - 1);
            }
        }

        if (criticalpts.empty())
            return n / 2;

        vector<int> seg;
        seg.push_back(criticalpts[0] + 1); // length of the 1st part
        for (int i = 1; i < criticalpts.size(); i++) {
            seg.push_back(criticalpts[i] - criticalpts[i - 1]); //  length of the middle parts
        }
        seg.push_back(n - criticalpts.back() - 1); // length of the last part

        int ans = 0;

        for (int i = 1; i < seg.size(); i++) {
            ans = max(ans, min(seg[i - 1], seg[i]));
        }

        for (int len : seg) {
            ans = max(ans, len / 2);
        }

        return ans;
    }
};
