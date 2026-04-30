class Solution {
public:
    void helper(vector<int>& nums,int idx ,set<vector<int>>& res){

        if(idx == nums.size()){
            res.insert(nums);
            return;
        }

        for(int i = idx ;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            helper(nums,idx+1,res);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        vector<int> curr;
        helper(nums,0,res);
        vector<vector<int>> ans(res.begin(),res.end());
        return ans;        
    }
};