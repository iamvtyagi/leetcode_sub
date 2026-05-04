class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0; i < n; i++) {
            int el = nums1[i];
            bool found = false;
            bool greaterFound = false;

            for(int j = 0; j < m; j++) {
                if(nums2[j] == el) {
                    found = true;
                }

                if(found && nums2[j] > el) {
                    nums1[i] = nums2[j];  
                    greaterFound = true;
                    break;
                }
            }

            if(!greaterFound) nums1[i] = -1;  
        }
        return nums1;
    }
};