class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;

          // ye batayega ki right side mei even no of el h ya odd
            bool isEven;
            if((r-mid)%2==0){
                isEven = true;
            }else{
                isEven = false;
            }
          //yha esne mid ne just right vale se pairing krli 
            if(nums[mid]==nums[mid+1]){
                if(isEven){
                    l = mid+1;
                }else{
                    r = mid -1;
                }
            }else{
                if(isEven){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
        }
        return nums[r];
    }
};