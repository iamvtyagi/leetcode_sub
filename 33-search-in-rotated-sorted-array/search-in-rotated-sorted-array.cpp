class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            int mid = (s) + (e-s)/2;

            if(nums[mid]==target){
                return mid;
            }

            //check left part sorted or not
           if(nums[s] <= nums[mid]) {
                //check target  exist in this array or not
                if(nums[s] <= target && target < nums[mid]){
                     e = mid-1;
                }else{
                    s = mid+1;
                }


            }

         // check right part is soted or not -> atleast one part is alwasy sorted in one time rotated array 
            else{
                    if(nums[mid]<target && nums[e]>=target){
                        s = mid+1;
                    }else{
                        e = mid-1;
                    }
            }
        }
        return -1;
    }
};