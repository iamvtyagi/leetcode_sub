class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                // Minimum lies in right half because right is unsorted
                l = mid + 1;
            } else {
                // Minimum lies in left half (including mid) left unsorted
                r = mid;
            }
        }
        return nums[l];
    }
};
