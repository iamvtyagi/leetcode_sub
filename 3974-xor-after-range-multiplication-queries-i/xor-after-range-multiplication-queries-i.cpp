class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int idx = queries[0][0];
        int mod = 1e9 + 7;
        for(int i = 0; i < queries.size(); i++){
            idx = queries[i][0];
            while(idx <= queries[i][1]){
                    nums[idx] = (((long long)nums[idx] * queries[i][3]) % mod);
                    
                    idx+= queries[i][2];
                
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }

        return ans;
    }
};