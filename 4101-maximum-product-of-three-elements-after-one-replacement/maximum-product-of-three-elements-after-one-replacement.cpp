class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        if(nums[n-3]==0 && nums[n-2]==0) return 0;
        return 1LL*abs(nums[n-1]) * abs(nums[n-2])*1e5;        
    }
};