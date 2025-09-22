class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int mx = INT_MIN;
        int ans = 0;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            mx = max(mx,mp[nums[i]]);
        }
        for(auto& it : mp){
            if(mx == it.second) ans += it.second;
        }
        return ans;
    }
};