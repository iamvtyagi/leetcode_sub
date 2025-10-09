class Solution {
public:
    int bSearch(vector<int> &nums, int i , int j , int t){
         int l = i ;
         int r = j;
         int ans = -1;
         while(l<=r){
           int mid = l + (r-l)/2;
            if(nums[mid]==t){
                  ans = mid;
                  r = mid -1;
            }else if(nums[mid] > t){
                r = mid -1;
            }else{
                //  l = mid + 1;
                 l = mid +1;
            }
         }
         return ans;
    }

    int modifiedBSearch(vector<int> &nums, int i , int j , int t){
         int l = i ;
         int r = j;
         int ans = -1;
         while(l<=r){
           int mid = l + (r-l)/2;
            if(nums[mid]==t){
                  ans = mid;
                l = mid +1;
            }else if(nums[mid] > t){
                r = mid -1;
            }else{
                //  l = mid + 1;
                 l = mid +1;
            }
         }
         return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = bSearch(nums,0,n-1,target);
        int j = modifiedBSearch(nums,0,n-1,target);
        return {i,j};
    }
};