class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cnt = 0;
        mp[0] = 1;
        for(int i = 1;i<n;i++){
            nums[i] = nums[i-1] + nums[i];
        }

        for(int i = 0;i<n;i++){
            if(mp.find(nums[i]-k) != mp.end()){
                cnt += mp[nums[i]-k];
            }
            mp[nums[i]]++;
        }
        return cnt;
    }
};