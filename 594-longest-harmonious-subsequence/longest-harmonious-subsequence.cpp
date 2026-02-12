class Solution {
public:
    int findLHS(vector<int>& nums) {
        int x = nums.size();
        unordered_map<int,int> mp;
        for(auto& el : nums){
            mp[el]++;
        }
        int ans = 0;
        for(auto& el : mp){
            int val = el.first;
            int n = mp[val];
            int m;
            if(mp.find(val+1) != mp.end()){
                m = mp[val+1];
            }else{
                continue;
            }
            ans = max(ans,n+m);
        }
        return ans;
    }
};