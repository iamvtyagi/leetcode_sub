class Solution {
public:
    int numSub(string s) {
        long long cnt = 0, ans = 0;
        const long long MOD = 1e9+7;

        for(char c : s) {
            if(c == '1') {
                cnt++;                  
            } else {
                ans += (cnt * (cnt + 1) / 2) % MOD; 
                cnt = 0;              
            }
        }

        ans += (cnt * (cnt + 1) / 2) % MOD;

        return ans % MOD;
    }
};
