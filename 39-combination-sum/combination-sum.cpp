class Solution {
public:
    vector<vector<int>> res;

    void helper(vector<int>& nums,int idx , vector<int>& curr,int sum,int target){

        if(idx == nums.size()) return;
        if(sum==target){
            res.push_back(curr);
            return;
        }

        if(sum+nums[idx] > target){
            helper(nums,idx+1,curr,sum,target);
        }else{
            sum += nums[idx];
            curr.push_back(nums[idx]);
            helper(nums,idx,curr,sum,target);

            sum -= nums[idx];
            curr.pop_back();
            helper(nums,idx+1,curr,sum,target);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> curr;
        helper(nums,0,curr,0,target);
        return res;
    }
};