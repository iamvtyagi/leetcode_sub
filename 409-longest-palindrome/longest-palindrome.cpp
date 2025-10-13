class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<int,int> mp;
        long long ans = 0;
        int minVal = 0;
        for(int i = 0;i<n;i++){
             mp[s[i]]++;
        }
        for(auto& el : mp){
            if(el.second % 2 == 0){
                ans += el.second;
            }else{
                if(el.second != 1){
                    ans += el.second - 1;
                }
            }
        }
        if(ans < s.size()) ans++;
        return ans;
    }
};