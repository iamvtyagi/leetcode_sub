class Solution {
public:
   void helper(vector<int>& nums,int idx, vector<vector<int>>& res,vector<int> vis,vector<int> curr){
       
       if(idx == nums.size()){
           res.push_back(curr);
           return;
       }

       for(int i = 0;i<nums.size();i++){
        if(!vis[i]){
            curr.push_back(nums[i]);
            vis[i]= 1;
            helper(nums,idx+1,res,vis,curr);
            vis[i] = 0;
            curr.pop_back();
        }
       }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> vis(n,0);
        vector<int> curr;
        helper(nums,0,res,vis,curr);
        return res;
    }
};