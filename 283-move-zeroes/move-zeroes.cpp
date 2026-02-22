class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0) cnt++;
        }
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] != 0  ){
                nums[idx++] = nums[i]; 
                
            }
        }
        for(int i = 1;i<=cnt;i++){
            nums[n-i] = 0;
        }
    }
};