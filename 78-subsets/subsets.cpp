class Solution {
public:
    void helper(vector<int>& nums, int idx , vector<vector<int>>& res,vector<int> curr){

        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }

        // pick 
        curr.push_back(nums[idx]);
        helper(nums,idx+1,res,curr);
        curr.pop_back();
        // no pick
        helper(nums,idx+1,res,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums,0,ans,curr);
        return ans;
    }
};