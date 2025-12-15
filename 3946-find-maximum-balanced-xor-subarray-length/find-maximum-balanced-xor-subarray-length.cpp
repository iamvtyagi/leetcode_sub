class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<long long,unordered_map<long long,long long>> mp;
        // xor cap idx
        long long cnt = INT_MIN;
        long long xorValue = 0;
        long long cap = 0;
        mp[0][cap] = -1; 
        for(int i = 0;i<n;i++){
            xorValue ^= nums[i];

            if(nums[i]%2 == 0) cap++;
            else cap--;
            if(mp[xorValue].find(cap) != mp[xorValue].end()){
                 cnt = max(cnt,i-mp[xorValue][cap]);
            }else{
                mp[xorValue][cap] = i;
            }
        }
        return (cnt==INT_MIN)?0:cnt;
    }
};