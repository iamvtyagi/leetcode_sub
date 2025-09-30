class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        // int sum = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = 0;j<n-i-1;j++){
                int val =  nums[j]+nums[j+1];
                int digit = val%10;
                nums[j] = digit;
            }
        }
        return nums[0];
    }
};