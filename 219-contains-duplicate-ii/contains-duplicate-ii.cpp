class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return false;

        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;

        while (j < n) {
            mp[nums[j]]++;
            if (mp[nums[j]] > 1) {
                return true; 
            }

            if (j - i >= k) { 
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};
