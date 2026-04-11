class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i = 0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;

        for(auto& el : mp){
            vector<int>& v = el.second;
            if(v.size() >= 3){
                for(int i = 0;i<v.size()-2;i++){
                    int ans = 2 * (v[i+2] - v[i]);
                    mini = min(mini,ans);
                }
            }
        }
        return (mini==INT_MAX)?-1:mini;;
    }
};