class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];

        while(l<=r){
            int mid = (l) + (r-l)/2;

            //check got ans or not
            if(mid>0 && mid<n-1 && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            //cal len of left and right
            int len = n-mid-1;
            //check odd or even and act accordingly
            if(len%2==0){
                //here check matching kidhar se hori 
                if(mid>0 && nums[mid]==nums[mid-1]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(mid>0 && nums[mid]==nums[mid-1]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return 0;
    }
};