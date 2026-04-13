class Solution {
public:
    int getMinDistance(vector<int>& nums, int tar, int start) {
        int minD = INT_MAX;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            if(nums[i] == tar)
            {
                minD = min(minD, abs(i-start));
            }
            if(minD == 0) return minD;
        }
        return minD;
    }
};