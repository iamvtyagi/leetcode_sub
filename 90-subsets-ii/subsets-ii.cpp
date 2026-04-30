class Solution {
public:
    void helper(vector<int>& nums, int idx , set<vector<int>>& res,vector<int> curr){

        if(idx == nums.size()){
            res.insert(curr);
            return;
        }

        // pick 
        curr.push_back(nums[idx]);
        helper(nums,idx+1,res,curr);
        curr.pop_back();
        // no pick
        helper(nums,idx+1,res,curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> curr;
        helper(nums,0,ans,curr);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;       
    }
};