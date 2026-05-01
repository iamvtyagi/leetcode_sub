class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& res, unordered_map<int,int>& mp,vector<int> temp){

        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }

        for(auto& [num,count] : mp){
            if(count == 0) continue;

            temp.push_back(num);
            mp[num]--;

            helper(nums,res,mp,temp);
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        unordered_map<int,int> mp;
        
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        // for(auto& [num,count] : mp){
        //     cout<<num<<"  "<<count<<endl; 
        // }

        helper(nums,res,mp,temp);
        return res;
    }
};