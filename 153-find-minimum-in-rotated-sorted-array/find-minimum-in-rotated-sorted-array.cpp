class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minValue = INT_MAX;
        for(int i = 0;i<n;i++){
             minValue = min(nums[i],minValue);
        }
        return  minValue;
    }
};