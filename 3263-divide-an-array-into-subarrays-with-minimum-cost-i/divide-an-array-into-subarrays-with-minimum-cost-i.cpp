class Solution {
public:
    int minimumCost(vector<int>& nums) {\
       int n = nums.size();
        int val = nums[0];
        int mini = INT_MAX;
        int smini = INT_MAX;
        for(int i = 1;i<n;i++){
            if(nums[i] < mini){
                 smini = mini;
                 mini = nums[i];
            }
            else if(nums[i] >= mini && nums[i] < smini){
                smini = nums[i];
            }
        }
        return val+mini+smini;
    }
};