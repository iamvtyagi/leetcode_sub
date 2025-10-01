class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;

        int maxLen = 0;
        unordered_map<char,int> mp; 
        int l = 0;
        int r = 0;

        while(l <= r && r < n){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]] + 1);  
            }
            mp[s[r]] = r;
            maxLen = max(maxLen, r - l + 1); 
            r++;
        }

        return maxLen;
    }
};
