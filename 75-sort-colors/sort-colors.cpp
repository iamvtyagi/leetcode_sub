class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c = 0;
        int l = 0;
        int n = nums.size();
        int r = n - 1;

        while (c <= r) {   
            if (nums[c] == 1) {
                c++;
            }
            else if (nums[c] == 0) {
                swap(nums[c], nums[l]);
                l++;
                c++;
            }
            else { 
                swap(nums[c], nums[r]);  
                r--;
            }
        }
    }
};