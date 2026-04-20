class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int ans = -1;

        while(i<=j){
        int mid = i + (j - i) / 2;
            if(nums[mid]==target){
                ans = mid;
                return ans;
            }else if(nums[mid] < target){
                ans = mid+1;
                i = mid+1;
            }else{
                ans = mid;
                j = mid-1;
            }
        }
        return ans;
    }
};