class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int strt=0;
        int end=n-1;
        while (strt<end){
            int mid=strt+(end-strt)/2;
            
           if(nums[mid]>nums[end]){
                strt=mid+1;
            }
            else if(nums[mid]<nums[end]){
                end=mid;
            }
            else{
                end--;
            }
        }   
        return nums[strt]; 
    }
};