class Solution {
public:
    vector<vector<int>> res;
      
    void helper(vector<int>& nums,int idx , vector<int> curr,int target){

        if(target == 0){
            res.push_back(curr);
            return;
        }

        for(int i = idx;i<nums.size();i++){

            if(i>idx && nums[i] == nums[i-1]) continue;

            if(nums[i] > target ) break;

            //pick 
            curr.push_back(nums[i]);
            helper(nums,i+1,curr,target-nums[i]);
            //release
            curr.pop_back();
    }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        res.clear();
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> curr;
        helper(nums,0,curr,target);
        return res;
    }
};