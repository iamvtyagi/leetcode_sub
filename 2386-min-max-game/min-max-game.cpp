class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            return min(nums[0], nums[1]);
        }
        while(n > 1){
            int p = 0;
            bool turn = true; 
            for(int j = 1; j < n; j += 2){
                if(turn){
                    nums[p] = min(nums[j], nums[j-1]);
                    turn = false;
                } else {
                    nums[p] = max(nums[j], nums[j-1]);
                    turn = true;
                }
                p++;
            }
            n /= 2; 
        }
        return nums[0];
    }
};
