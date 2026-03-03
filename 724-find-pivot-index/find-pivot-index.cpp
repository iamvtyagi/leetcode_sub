class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ts = 0;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            ts += nums[i];
        }
        int ls = 0;
        if(ls==(ts-nums[0])) return 0;
        for(int i = 1;i<n;i++){
            ls+=nums[i-1];
            int rs = ts - ls - nums[i];
            if(ls==rs) return i;
        }
        return -1;
    }
};